#include <Keyboard.h>
const int switchPin = 2; // A6ピンをスイッチ入力に使用
const int switchState = HIGH; // スイッチが押されていないときの状態
int lastButtonState = HIGH;
int t = 150;

void setup() {
  pinMode(switchPin, INPUT_PULLUP); // A6ピンを入力モードに設定し、プルアップ抵抗を有効にする
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  Serial.begin(9600); // シリアル通信を初期化
}

void loop() {
  if (digitalRead(switchPin) == LOW) { // スイッチが押されたとき
    Serial.println("2が押されました!");

    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('z');
    delay(100);
    Keyboard.releaseAll();
    while (!digitalRead(2)) {}

    delay(t); // チャタリング防止のためのディレイ
  }

  if (digitalRead(3) == LOW) { // スイッチが押されたとき
    Serial.println("3が押されました!");

    Keyboard.write(KEY_LEFT_ARROW);
    delay(t); // チャタリング防止のためのディレイ

  }

  if (digitalRead(4) == LOW) { // スイッチが押されたとき
    Serial.println("4が押されました!");
    Keyboard.write(KEY_TAB);

    delay(t); // チャタリング防止のためのディレイ
  }

  if (digitalRead(5) == LOW) { // スイッチが押されたとき
    Serial.println("5が押されました!");
    delay(t); // チャタリング防止のためのディレイ
  }

  if (digitalRead(6) == LOW) { // スイッチが押されたとき

    Serial.println("6が押されました!");

    Keyboard.write(KEY_BACKSPACE);
    delay(t); // チャタリング防止のためのディレイ
  }

  if (digitalRead(7) == LOW) { // スイッチが押されたとき
    Serial.println("7が押されました!");
    Keyboard.write(KEY_RIGHT_ARROW);
    delay(t); // チャタリング防止のためのディレイ
  }

  if (digitalRead(8) == LOW) { // スイッチが押されたとき
    Serial.println("8が押されました!");

    Keyboard.write(' ');
    delay(t); // チャタリング防止のためのディレイ
  }

  if (digitalRead(9) == LOW) { // スイッチが押されたとき
    Serial.println("9が押されました!");

    Keyboard.write(KEY_RETURN);
    delay(t); // チャタリング防止のためのディレイ
  }



  
}