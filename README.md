# 元ネタ
2016年のエイプリルフールにgoogle japanが発表した物理フリックキーボードを作成しました。以下が動画リンクとサイトです\
[![Google 日本語入力物理フリックバージョン](https://github.com/user-attachments/assets/aec5b6de-97ed-4d39-81aa-129b392df61c)](https://youtu.be/5LI1PysAlkU?si=t8umUnH_9durJIMJ)

https://blog.google/intl/ja-jp/products/android-chrome-play/2016_04_furikku/

# 作ろうとしたきっかけ
物理フリックキーボードを作ろうと思ったきっかけは学園祭でした。学園祭ではクラス作品を展示していて、そこで学校の金で物理フリックキーボードを作れるのではと思い、制作をしました。

# 制作
制作は主にgoogle japanが公開しているgithubを参考にして作りました。\
https://github.com/google/mozc-devices/tree/master/mozc-furikku

## 使用部品
- Maker Nano * 1
- Leonardo Pro Micro * 1
- ジョイスティック * 12
- CHERRY MX メカニカルスイッチ * 8
- MCP3208 * 3
- ユニバーサル基板 * 2
- Connectors

## 作り方
### 操作基板
1. ジョイスティックとスイッチをユニバーサル基板に配置してはんだ付けします。ジョイスティックを詰め込みすぎるとフリックするときに隣に干渉してしますので少し間隔を開けて配置します。
2. スイッチの5VとGNDをすべてつなぎます。

### 裏側基板
1. MCP3208,Maker Nano,Leonardo Pro Microを配置します。
2. 操作基板のジョイスティックの出力をそれぞれMCP3208の対応するピンとつなぎます。
3. MCP3208とMaker Nanoをつなぎます。
4. 操作基板のスイッチの出力をLeonardo Pro Microにつなぎます。

基板ができたらarduinoにプログラムを入れます。\
物理フリックキーボードと接続されたパソコンでa.pyをを実行すると入力ができるようになります。\
最後に木などで適当なケースを作ります
