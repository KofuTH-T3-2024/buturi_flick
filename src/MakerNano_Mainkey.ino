//ジョイスティックの傾きに応じて文字入力をする
#include <SPI.h>

// MCP3208のCSピン設定
const int CS_PIN_1 = 10; // MCP3208の1つ目のCSピン
const int CS_PIN_2 = 9;  // MCP3208の2つ目のCSピン
const int CS_PIN_3 = 8;  // MCP3208の3つ目のCSピン


char Vowel_temp = "null";
char Conso_temp = "null";


const int A_PIN = 2;
const int K_PIN = 3;
const int S_PIN = 4;
const int T_PIN = 5;
const int N_PIN = 6;
const int H_PIN = 7;
const int M_PIN = A0;
const int Y_PIN = A1;
const int R_PIN = A2;
const int W_PIN = A4;
const int MK_PIN = A5;

//傾きしきい値の設定
const int LeftPush = 500;
const int RightPush = 4000;



void setup() {
  Serial.begin(9600); // シリアル通信の初期化
  SPI.begin();        // SPI通信の初期化

  // 各CSピンを出力モードに設定し、初期状態をHIGHにする
  pinMode(CS_PIN_1, OUTPUT);
  digitalWrite(CS_PIN_1, HIGH);
  
  pinMode(CS_PIN_2, OUTPUT);
  digitalWrite(CS_PIN_2, HIGH);
  
  pinMode(CS_PIN_3, OUTPUT);
  digitalWrite(CS_PIN_3, HIGH);

  
  pinMode( A_PIN, INPUT_PULLUP);
  pinMode( K_PIN, INPUT_PULLUP);
  pinMode( S_PIN, INPUT_PULLUP);
  pinMode( T_PIN, INPUT_PULLUP);
  pinMode( N_PIN, INPUT_PULLUP);
  pinMode( H_PIN, INPUT_PULLUP);
  pinMode( M_PIN, INPUT_PULLUP);
  pinMode( Y_PIN, INPUT_PULLUP);
  pinMode( R_PIN, INPUT_PULLUP);
  pinMode( W_PIN, INPUT_PULLUP);
  pinMode( MK_PIN, INPUT_PULLUP);

}



void loop() {
  // MCP3208_1のデータを読み取る
  int value1_0 = readMCP3208(CS_PIN_1, 0); // MCP3208_3の0チャンネル
  int value1_1 = readMCP3208(CS_PIN_1, 1); // MCP3208_3の1チャンネル
  int value1_2 = readMCP3208(CS_PIN_1, 2); // MCP3208_3の2チャンネル
  int value1_3 = readMCP3208(CS_PIN_1, 3); // MCP3208_3の3チャンネル
  int value1_4 = readMCP3208(CS_PIN_1, 4); // MCP3208_3の0チャンネル
  int value1_5 = readMCP3208(CS_PIN_1, 5); // MCP3208_3の1チャンネル
  int value1_6 = readMCP3208(CS_PIN_1, 6); // MCP3208_3の2チャンネル
  int value1_7 = readMCP3208(CS_PIN_1, 7); // MCP3208_3の3チャンネル

  // MCP3208_2のデータを読み取る
  int value2_0 = readMCP3208(CS_PIN_2, 0); // MCP3208_3の0チャンネル
  int value2_1 = readMCP3208(CS_PIN_2, 1); // MCP3208_3の1チャンネル
  int value2_2 = readMCP3208(CS_PIN_2, 2); // MCP3208_3の2チャンネル
  int value2_3 = readMCP3208(CS_PIN_2, 3); // MCP3208_3の3チャンネル
  int value2_4 = readMCP3208(CS_PIN_2, 4); // MCP3208_3の0チャンネル
  int value2_5 = readMCP3208(CS_PIN_2, 5); // MCP3208_3の1チャンネル
  int value2_6 = readMCP3208(CS_PIN_2, 6); // MCP3208_3の2チャンネル
  int value2_7 = readMCP3208(CS_PIN_2, 7); // MCP3208_3の3チャンネル

  // MCP3208_3のデータを読み取る
  int value3_0 = readMCP3208(CS_PIN_3, 0); // MCP3208_3の0チャンネル
  int value3_1 = readMCP3208(CS_PIN_3, 1); // MCP3208_3の1チャンネル
  int value3_2 = readMCP3208(CS_PIN_3, 2); // MCP3208_3の2チャンネル
  int value3_3 = readMCP3208(CS_PIN_3, 3); // MCP3208_3の3チャンネル
  int value3_4 = readMCP3208(CS_PIN_3, 4); // MCP3208_3の0チャンネル
  int value3_5 = readMCP3208(CS_PIN_3, 5); // MCP3208_3の1チャンネル
  int value3_6 = readMCP3208(CS_PIN_3, 6); // MCP3208_3の2チャンネル
  int value3_7 = readMCP3208(CS_PIN_3, 7); // MCP3208_3の3チャンネル

//あ行
    if (digitalRead(A_PIN) == LOW)
    {
        Serial.println("a\t");
    }
  
    if (value1_0 <= LeftPush)

    {
        Serial.println("i\t");
    }
  
    if (value1_0 >= RightPush)
    {
        Serial.println("e\t");
    }

    if (value1_1 <= LeftPush)
    {
        Serial.println("u\t");
    }

    if (value1_1 >= RightPush)
    {
        Serial.println("o\t");
    }


//か行
    if (digitalRead(K_PIN) == LOW)
    {
        Serial.println("ka\t");
    }

    if (value1_2 <= LeftPush)
    {
      Serial.println("ki\t");
    }

    if (value1_2 >= RightPush)
    {
        Serial.println("ke\t");
    }

    if (value1_3 <= LeftPush)
    {
        Serial.println("ku\t");
    }

    if (value1_3 >= RightPush)
    {
        Serial.println("ko\t");
    }
   

//さ行
    if (digitalRead(S_PIN) == LOW)
    {
        Serial.println("sa\t");
    }

    if (value1_4 <= LeftPush)
    {
        Serial.println("si\t");
    }

    if (value1_4 >= RightPush)
    {
        Serial.println("se\t");
    }

    if (value1_5 <= LeftPush)
    {
        Serial.println("su\t");
    }

    if (value1_5 >= RightPush)
    {
        Serial.println("so\t");
    }




//た行

    if (digitalRead(T_PIN) == LOW)
    {
        Serial.println("ta\t");
    }

    if (value2_2 <= LeftPush)//横

    {
        Serial.println("ti\t");
    }

    if (value2_2 >= RightPush)
    {

        Serial.println("te\t");
    }

    if (value1_7 <= LeftPush)
    {
        Serial.println("tu\t");
    }

    if (value1_7 >= RightPush)
    {
        Serial.println("to\t");
    }


//な行
    if (digitalRead(N_PIN) == LOW)
    {
        Serial.println("na\t");
    }
  
    if (value2_0 <= LeftPush)
    {
        Serial.println("ni\t");
    }

    if (value2_0>= 2000)
    {
        Serial.println("ne\t");
    }

    if (value1_6 <= 600)
    {
        Serial.println("nu\t");
    }

    if (value1_6 >= 3500)
    {
        Serial.println("no\t");
    }

  
//は行
    if (digitalRead(H_PIN) == LOW)
    {
        Serial.println("ha\t");
    }

    if (value2_1 <= LeftPush)
    {
        Serial.println("hi\t");
    }

    if (value2_1>= RightPush)
    {
        Serial.println("he\t");
    }

    if (value2_3 <= LeftPush)
    {
        Serial.println("hu\t");
    }

    if (value2_3 >= RightPush)
    {
        Serial.println("ho\t");
    }




//ま行

    if (digitalRead(M_PIN) == LOW)
    {
        Serial.println("ma\t");
    }

    if (value2_4 <= LeftPush)
    {
        Serial.println("mi\t");
    }

    if (value2_4>= RightPush)
    {
        Serial.println("me\t");
    }

    if (value2_5 <= LeftPush)
    {
        Serial.println("mu\t");
    }

    if (value2_5 >= RightPush)
    {
        Serial.println("mo\t");
    }
  

//や行
    if (digitalRead(Y_PIN) == LOW)
    {
        Serial.println("ya\t");
    }
  
    if (value2_6 <= LeftPush)
    {
        Serial.println("(\t");
    }

    if (value2_6>= RightPush)
    {
        Serial.println(")\t");
    }

    if (value2_7 <= LeftPush)
    {
        Serial.println("yu\t");
    }

    if (value2_7 >= RightPush)
    {
        Serial.println("yo\t");
    }




//ら行

    if (digitalRead(R_PIN) == LOW)
    {
        Serial.println("ra\t");
    }

    if (value3_0 <= 100)
    {
        Serial.println("ri\t");
    }

    if (value3_0>= RightPush)
    {
        Serial.println("re\t");
    }

    if (value3_1 <= LeftPush)
    {
        Serial.println("ru\t");
    }

    if (value3_1 >= RightPush)
    {
        Serial.println("ro\t");
    }

  
//わ行
    if (digitalRead(W_PIN) == LOW)
    {
        Serial.println("wa\t");
    }

    if (value3_4 <= LeftPush)
    {
        Serial.println("wo\t");
    }

    if (value3_4>= RightPush)
    {
        Serial.println("-\t");
    }

    if (value3_5 <= LeftPush)
    {
        Serial.println("nn\t");
    }

    if (value3_5 >= RightPush)
    {
        Serial.println("~\t");
    }


//句読点ども

    if (digitalRead(MK_PIN) == LOW)
    {
        Serial.println(",\t");
    }

    if (value3_6 <= LeftPush)
    {
        Serial.println(".\t");
    }

    if (value3_6>= RightPush)
    {
        Serial.println("!\t");
    }
  
    if (value3_7 <= LeftPush)
    {
        Serial.println("?\t");
    }
  
    if (value3_7 >= RightPush)
    {
        Serial.println("…\t");
    }   



  delay(300); // 待機
}


// MCP3208からデータを読み取る関数
int readMCP3208(int csPin, int channel) {
  if (channel < 0 || channel > 7) {
    return -1; // チャンネルが無効な場合
  }

  digitalWrite(csPin, LOW); // 指定されたCSピンをLOWに設定して通信開始

  // MCP3208へのコマンド送信
  byte command = 0b00000110 | ((channel & 0x04) >> 2); // スタートビットとシングルエンド設定
  SPI.transfer(command);
  byte result1 = SPI.transfer((channel & 0x03) << 6);  // チャンネルビット送信
  byte result2 = SPI.transfer(0x00);                  // データの受信
  digitalWrite(csPin, HIGH); // 指定されたCSピンをHIGHに戻して通信終了

  // 12ビットの結果を計算
  int value = ((result1 & 0x0F) << 8) | result2;
  return value;
}
