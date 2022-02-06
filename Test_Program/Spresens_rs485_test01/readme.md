**Spresens rs-485 Multi Drop test program**

3枚の基板を使ってRS-485のテストを行います。
実際は3枚の基板に対してのマスター・スレーブの制御が必要となりますが、今回は単純に3枚の基板から別々のデータを送信しています。
よって送信のタイミングが重なった場合は正常に動きません。

**事前準備**  
SJ1　受信イネーブル制御ピン選択　1: EMMC_DATA3  
SJ2　送信イネーブル制御ピン選択　1: EMMC_DATA2  
SJ3　ショート RXラインの終端抵抗有効 (両端の2枚)  
SJ4　ショート:RS-485  
SJ5　ショート:RS-485  

3枚の基板の Y Z または A B どうしを接続
  
**プログラム**  
spresense_rs485_unit1.ino  
　送信データ "1234567890"  

spresense_rs485_unit2.ino  
　送信データ "9876543210"

spresense_rs485_unit3.ino  
　送信データ "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

**実行結果**