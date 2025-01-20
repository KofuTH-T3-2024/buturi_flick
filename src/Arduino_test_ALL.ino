//ジョイスティックの入力を調べるプログラム
#include <SPI.h>

// MCP3208のCSピン設定
const int CS_PIN_1 = 10; // MCP3208の1つ目のCSピン
const int CS_PIN_2 = 9;  // MCP3208の2つ目のCSピン
const int CS_PIN_3 = 8;  // MCP3208の3つ目のCSピン

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
  Serial.print("MCP3208_1 Channel 0: ");
  Serial.print(value1_0);
  Serial.print("\tChannel 1: ");
  Serial.println(value1_1);
  Serial.print("          Channel 2: ");
  Serial.print(value1_2);
  Serial.print("\tChannel 3: ");
  Serial.println(value1_3);
  Serial.print("          Channel 4: ");
  Serial.print(value1_4);
  Serial.print("\tChannel 5: ");
  Serial.println(value1_5);
  Serial.print("          Channel 6: ");
  Serial.print(value1_6);
  Serial.print("\tChannel 7: ");
  Serial.println(value1_7);

  Serial.print("MCP3208_2 Channel 0: ");
  Serial.print(value2_0);
  Serial.print("\tChannel 1: ");
  Serial.println(value2_1);
  Serial.print("          Channel 2: ");
  Serial.print(value2_2);
  Serial.print("\tChannel 3: ");
  Serial.println(value2_3);
  Serial.print("          Channel 4: ");
  Serial.print(value2_4);
  Serial.print("\tChannel 5: ");
  Serial.println(value2_5);
  Serial.print("          Channel 6: ");
  Serial.print(value2_6);
  Serial.print("\tChannel 7: ");
  Serial.println(value2_7);

  Serial.print("MCP3208_3 Channel 0: ");
  Serial.print(value3_0);
  Serial.print("\tChannel 1: ");
  Serial.println(value3_1);
  Serial.print("          Channel 2: ");
  Serial.print(value3_2);
  Serial.print("\tChannel 3: ");
  Serial.println(value3_3);
  Serial.print("          Channel 4: ");
  Serial.print(value3_4);
  Serial.print("\tChannel 5: ");
  Serial.println(value3_5);
  Serial.print("          Channel 6: ");
  Serial.print(value3_6);
  Serial.print("\tChannel 7: ");
  Serial.println(value3_7);

  delay(500); // 0.5秒待機
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
