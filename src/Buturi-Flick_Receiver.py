# -*- coding: utf-8 -*-
import serial
import pyautogui
import time

# COMポートとボーレートの設定
COM_PORT = "COM5"  # 使用するCOMポートを指定
BAUD_RATE = 9600   # デバイスと一致するボーレート

try:
    # シリアルポートを開く
    ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {COM_PORT} at {BAUD_RATE} baud.")
except serial.SerialException as e:
    print(f"Failed to connect to {COM_PORT}: {e}")
    exit()

# メインループ
try:
    while True:
        # シリアルポートからデータを読み取る
        if ser.in_waiting > 0:  # データが受信されているか確認
            data = ser.readline().decode('utf-8').strip()  # UTF-8でデコード
            print(f"Received: {data}")  # デバッグ用に受信データを表示

            # 日本語を含む文字列を入力エミュレート
            for char in data:
                pyautogui.write(char)
                time.sleep(0.05)  # 少し間隔を空けてキー入力をエミュレート
except KeyboardInterrupt:
    print("\nProgram stopped by user.")
finally:
    ser.close()  # シリアルポートを閉じる
    print("Serial port closed.")
