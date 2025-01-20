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



  pinMode(CS_PIN_3, OUTPUT);



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



  // データをシリアルモニタに出力

//   Serial.print("MCP3208_1 Channel 0: ");

//   Serial.print(value1_0);

//   Serial.print("\tChannel 1: ");

//   Serial.println(value1_1);

//   Serial.print("          Channel 2: ");

//   Serial.print(value1_2);

//   Serial.print("\tChannel 3: ");

//   Serial.println(value1_3);

//   Serial.print("          Channel 4: ");

//   Serial.print(value1_4);

//   Serial.print("\tChannel 5: ");

//   Serial.println(value1_5);

//   Serial.print("          Channel 6: ");

//   Serial.print(value1_6);

//   Serial.print("\tChannel 7: ");

//   Serial.println(value1_7);



//   Serial.print("MCP3208_2 Channel 0: ");

//   Serial.print(value2_0);

//   Serial.print("\tChannel 1: ");

//   Serial.println(value2_1);

//   Serial.print("          Channel 2: ");

//   Serial.print(value2_2);

//   Serial.print("\tChannel 3: ");

//   Serial.println(value2_3);

//   Serial.print("          Channel 4: ");

//   Serial.print(value2_4);

//   Serial.print("\tChannel 5: ");

//   Serial.println(value2_5);

//   Serial.print("          Channel 6: ");

//   Serial.print(value2_6);

//   Serial.print("\tChannel 7: ");

//   Serial.println(value2_7);



//   Serial.print("MCP3208_3 Channel 0: ");

//   Serial.print(value3_0);

//   Serial.print("\tChannel 1: ");

//   Serial.println(value3_1);

//   Serial.print("          Channel 2: ");

//   Serial.print(value3_2);

//   Serial.print("\tChannel 3: ");

//   Serial.println(value3_3);

//   Serial.print("          Channel 4: ");

//   Serial.print(value3_4);

//   Serial.print("\tChannel 5: ");

//   Serial.println(value3_5);

//   Serial.print("          Channel 6: ");

//   Serial.print(value3_6);

//   Serial.print("\tChannel 7: ");

//   Serial.println(value3_7);



//あ行

    if (digitalRead(A_PIN) == LOW)

    {

        Serial.println("a\t");

    }

    if (value1_0 <= LeftPush)//横

    {

        Serial.println("i\t");

        Vowel_temp = "null";

        Conso_temp = "i";

    }

    if (value1_0 >= RightPush)

    {

        Serial.println("e\t");

        Vowel_temp = "null";

        Conso_temp = "e";

    }



    if (value1_1 <= LeftPush)

    {

        Serial.println("u\t");

        Vowel_temp = "null";

        Conso_temp = "u";

    }

    if (value1_1 >= RightPush)

    {

        Serial.println("o\t");

        Vowel_temp = "null";

        Conso_temp = "o";

    }



    



//か行

    if (digitalRead(K_PIN) == LOW)

    {

        Serial.println("ka\t");

    }

    if (value1_2 <= LeftPush)//横

    {

        Serial.println("ki\t");

        Vowel_temp = "k";

        Conso_temp = "i";

    }

    if (value1_2 >= RightPush)

    {

        Serial.println("ke\t");

        Vowel_temp = "k";

        Conso_temp = "e";

    }



    if (value1_3 <= LeftPush)

    {

        Serial.println("ku\t");

        Vowel_temp = "k";

        Conso_temp = "u";

    }

    if (value1_3 >= RightPush)

    {

        Serial.println("ko\t");

        Vowel_temp = "k";

        Conso_temp = "o";

    }

    // if (digitalRead(K_PIN) == LOW)

    // {

    //     Serial.print("ka\t");

    // }

    

//さ行

    if (digitalRead(S_PIN) == LOW)

    {

        Serial.println("sa\t");

    }

    if (value1_4 <= LeftPush)//横

    {

        Serial.println("si\t");

        Vowel_temp = "s";

        Conso_temp = "i";

    }

    if (value1_4 >= RightPush)

    {

        Serial.println("se\t");

        Vowel_temp = "s";

        Conso_temp = "e";

    }



    if (value1_5 <= LeftPush)

    {

        Serial.println("su\t");

        Vowel_temp = "s";

        Conso_temp = "u";

    }

    if (value1_5 >= RightPush)

    {

        Serial.println("so\t");

        Vowel_temp = "s";

        Conso_temp = "o";

    }




//た行

    if (digitalRead(T_PIN) == LOW)

    {

        Serial.println("ta\t");

    }

    if (value2_2 <= LeftPush)//横

    {

        Serial.println("ti\t");

        Vowel_temp = "t";

        Conso_temp = "i";

    }

    if (value2_2 >= RightPush)

    {

        Serial.println("te\t");

        Vowel_temp = "t";

        Conso_temp = "e";

    }



    if (value1_7 <= LeftPush)

    {

        Serial.println("tu\t");

        Vowel_temp = "t";

        Conso_temp = "u";

    }

    if (value1_7 >= RightPush)

    {

        Serial.println("to\t");

        Vowel_temp = "t";

        Conso_temp = "o";

    }

    // if (digitalRead(T_PIN) == LOW)

    // {

    //     Serial.print("ta\t");

    // }



//な行

    if (digitalRead(N_PIN) == LOW)

    {

        Serial.println("na\t");

    }

    if (value1_6 >= 2000)//横

      if (value2_0 <= LeftPush)
        {

            Serial.println("ni\t");

            Vowel_temp = "null";

            Conso_temp = "i";

        }

    if (value2_0>= 2000)

    {

        Serial.println("ne\t");

        Vowel_temp = "null";

        Conso_temp = "e";

    }



    if (value1_6 <= 600)

    {

        Serial.println("nu\t");

        Vowel_temp = "null";

        Conso_temp = "u";

    }

    if (value1_6 >= 3500)

    {

        Serial.println("no\t");

        Vowel_temp = "null";

        Conso_temp = "o";

    }




//は行

    if (digitalRead(H_PIN) == LOW)

    {

        Serial.println("ha\t");

    }

    if (value2_1 <= LeftPush)//横

    {

        Serial.println("hi\t");

        Vowel_temp = "h";

        Conso_temp = "i";

    }

    if (value2_1>= RightPush)

    {

        Serial.println("he\t");

        Vowel_temp = "h";

        Conso_temp = "e";

    }



    if (value2_3 <= LeftPush)

    {

        Serial.println("hu\t");

        Vowel_temp = "h";

        Conso_temp = "u";

    }

    if (value2_3 >= RightPush)

    {

        Serial.println("ho\t");

        Vowel_temp = "h";

        Conso_temp = "o";

    }




//ま行

    if (digitalRead(M_PIN) == LOW)

    {

        Serial.println("ma\t");

    }

    if (value2_4 <= LeftPush)//横

    {

        Serial.println("mi\t");

        Vowel_temp = "m";

        Conso_temp = "i";

    }

    if (value2_4>= RightPush)

    {

        Serial.println("me\t");

        Vowel_temp = "m";

        Conso_temp = "e";

    }



    if (value2_5 <= LeftPush)

    {

        Serial.println("mu\t");

        Vowel_temp = "m";

        Conso_temp = "u";

    }

    if (value2_5 >= RightPush)

    {

        Serial.println("mo\t");

        Vowel_temp = "m";

        Conso_temp = "o";

    }




//や行

    if (digitalRead(Y_PIN) == LOW)

    {

        Serial.println("ya\t");

    }

    if (value2_6 <= LeftPush)//横

    {

        Serial.println("(\t");

        Vowel_temp = "null";

        Conso_temp = "(";

    }

    if (value2_6>= RightPush)

    {

        Serial.println(")\t");

        Vowel_temp = "null";

        Conso_temp = ")";

    }



    if (value2_7 <= LeftPush)

    {

        Serial.println("yu\t");

        Vowel_temp = "null";

        Conso_temp = "u";

    }

    if (value2_7 >= RightPush)

    {

        Serial.println("yo\t");

        Vowel_temp = "null";

        Conso_temp = "o";

    }




//ら行

    if (digitalRead(R_PIN) == LOW)

    {

        Serial.println("ra\t");

    }

    if (value3_0 <= 100)//横

    {

        Serial.println("ri\t");

        Vowel_temp = "null";

        Conso_temp = "i";

    }

    if (value3_0>= RightPush)

    {

        Serial.println("re\t");

        Vowel_temp = "null";

        Conso_temp = "e";

    }



    if (value3_1 <= LeftPush)

    {

        Serial.println("ru\t");

        Vowel_temp = "r";

        Conso_temp = "u";

    }

    if (value3_1 >= RightPush)

    {

        Serial.println("ro\t");

        Vowel_temp = "r";

        Conso_temp = "o";

    }





//わ行

    if (digitalRead(W_PIN) == LOW)

    {

        Serial.println("wa\t");

    }

    if (value3_4 <= LeftPush)//横

    {

        Serial.println("wo\t");

        Vowel_temp = "w";

        Conso_temp = "o";

    }

    if (value3_4>= RightPush)

    {

        Serial.println("-\t");

        Vowel_temp = "null";

        Conso_temp = "-";

    }



    if (value3_5 <= LeftPush)

    {

        Serial.println("nn\t");

        Vowel_temp = "null";

        Conso_temp = "nn";

    }

    if (value3_5 >= RightPush)

    {

        Serial.println("~\t");

        Vowel_temp = "null";

        Conso_temp = "~";

    }

    // if (digitalRead(W_PIN) == LOW)

    // {

    //     Serial.print("wa\t");

    // }



//句読点ども

    if (digitalRead(MK_PIN) == LOW)

    {

        Serial.println(",\t");

    }

    if (value3_6 <= LeftPush)//横

    {

        Serial.println(".\t");

        Vowel_temp = "null";

        Conso_temp = ".";

    }

    if (value3_6>= RightPush)

    {

        Serial.println("!\t");

        Vowel_temp = "null";

        Conso_temp = "!";

    }



    if (value3_7 <= LeftPush)

    {

        Serial.println("?\t");

        Vowel_temp = "null";

        Conso_temp = "?";

    }

    if (value3_7 >= RightPush)

    {

        Serial.println("…\t");

        Vowel_temp = "null";

        Conso_temp = "_";

    }

    // if (digitalRead(H_PIN) == LOW)

    // {

    //     Serial.print("ha\t");

    // }



    



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

