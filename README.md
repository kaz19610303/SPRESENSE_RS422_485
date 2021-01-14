Sonyのマイコンボード Spresense用のRS-422/485拡張ボードです。

RS-422/485通信はその長距離通信が可能な故に今でも工場とかでは幅広く使われています。  
RS-422、RS-485 共に***差動信号による伝送***で***10Mbps***のスピードで､最大***1.2km***までデータの伝送が可能です。  
RS-422とRS-485の違いは1ライン当たりのドライバ、レシーバーの数と全2重、Point to Pointと半2重、マルチドロップの違いです。  

RS-422/485に関する詳しい説明は省かせていただきますのでご自身で検索して下さい。  

このボードに使用しているRS-422/485のチップは***Analog Devices社のADM2582EBRWZ***です。  
このチップはロジック部分と通信部分がアイソレーションされていて、  
最高通信レート: 16 Mbps、1ラインに256ノードの接続可能となっています。  

詳しくは以下のデータシートをご覧下さい。  
[ADM2582EBRWZ データシート](https://www.mouser.jp/datasheet/2/609/adm2582e_2587e-1503113.pdf)  

ジャンパー設定  
SJ1　受信イネーブル制御ピン選択　1: EMMC_DATA3　3:I2S_DIN  
SJ2　送信イネーブル制御ピン選択　1: EMMC_DATA2　3:I2S_DOUT  
SJ3　ショートでRXラインの終端抵抗有効  
SJ4　ショート:RS-485 オープン:RS-422  
SJ5　ショート:RS-485 オープン:RS-422  
(SJ4とSJ5は両方オープンまたは両方ショートに設定してください)  
![基板上のジャンパー](images/2-4.jpg)

CN3はアイソレーション電源出力です。  
1、2ピン 3.3v  
3、4ピン GND  
![外部接続端子](images/2-5.jpg)

[この基板の販売ページ](https://nextstep.official.ec/items/38434310)
