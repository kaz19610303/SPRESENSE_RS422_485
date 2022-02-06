#include <sdk/config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <poll.h>

#include <arch/board/board.h>
#include <arch/chip/pin.h>

#define RX_ENABLE PIN_EMMC_DATA3
#define TX_ENABLE PIN_EMMC_DATA2


int rs422_main(int argc, char *argv[])
{
    int fd;
    struct termios tio;                                     // シリアル通信設定
    int baudRate = B115200;
    int i;
    int len;
    int ret;
    int size;

    board_gpio_config(RX_ENABLE, 0, false, false, 0);       // 受信イネーブル Active LOW
    board_gpio_config(TX_ENABLE, 0, false, false, 0);       // 送信イネーブル Active HIGH
 
    board_gpio_write(RX_ENABLE, 0);                         // 受信は常時イネーブル
    board_gpio_write(TX_ENABLE, 0);                         // 送信は通常ディスイネーブル

    fd = open("/dev/ttyS2", O_RDWR);
    if (fd < 0)
    {
         printf("%s open error.\n", "/dev/ttyS2");
         return -1;
    }

    tio.c_cflag += CREAD;                                   // 受信有効
    tio.c_cflag += CLOCAL;                                  // ローカルライン（モデム制御なし）
    tio.c_cflag += CS8;                                     // データビット:8bit
    tio.c_cflag += 0;                                       // ストップビット:1bit
    tio.c_cflag += 0;                                       // パリティ:None

    cfsetispeed( &tio, baudRate );
    cfsetospeed( &tio, baudRate );
    cfmakeraw(&tio);                                        // RAWモード
    tcsetattr( fd, TCSANOW, &tio );                         // デバイスに設定を行う
    ioctl(fd, TCSETS, &tio);                                // ポートの設定を有効にする

    for(int i=0; i<50 ; i++)
    {
        board_gpio_write(TX_ENABLE, 1);                     // 送信イネーブル
        write_serial(fd);
        board_gpio_write(TX_ENABLE, 0);                     // 送信ディスイネーブル
        read_serial(fd);
        usleep(1000*1000);                                  // 1秒遅延
    }
}

void write_serial(int fd)
{
    char buffer[255];
    int send_data_lengs ;
    int delay_times = 1;

    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"%s","1234567890abcdefghijklmnopqrstuvwxyz\r\n");
    send_data_lengs = strlen(buffer);
    write(fd,buffer,send_data_lengs);
    printf("[write_serial]wrote = %s", buffer);
    usleep( 1 );                                            // 送信終了までの遅延 要調整
}

void read_serial(int fd)
{
    char buffer[255];
    int len;

    len = read(fd,&buffer,255);
    if(len > 0)
    {
        printf("[read_serial]buffer = %s\n", buffer);
    }
    else
    {
        printf("[read_serial]null\n");
    }
}
