# cmake_test

那大致上了解cmake 在完什麼把戲的時候，那我們來開始看學長們寫的模板。

首先感謝學長已經幫我們打好CMakeLists.txt 的模板，這個部份我要講解如何使用這個模板。

首先到`GitLab` clone 育仁學長的專案

```shell
git clone git@gitlab.ical.tw:e8035669/cmake_template.git
rm -rf .git*
vim .gitignore
```

刪完之後記得到`.gitignore`寫要忽略的檔案，__千萬記得要寫__，因為git不能放__執行檔__，至於`.gitignore`如何使用以及用來做什麼的就麻煩各位去看git的相關書籍囉！！！

那接下來說明專案最外層的`cmake_test/CMakeLists.txt`

首先要講解的就是第40行，一般來說我們通常會把自己寫的code放在`./lib`的資料夾裡，如果想額外建資料像我有額外建一個`Calc`的資料夾放其他的code

再來44行，整支專案的主程式會放在`./util`的資料夾中，那在CMakeLists.txt 就把要編譯的主程式資料夾寫上去即可

32行，`./deps`這個資料夾的用意是用來放其他人寫的函式庫用的，譬如說最近應該很多人有用到御熊學長寫的`Serial`這個函式庫，那在載入他的專案到這個資料夾方法有很多種，最簡單也最不推薦又最笨的方法就是直接複製一份到這個資料夾裡頭，那比較好的方法就是使用`git 的 submodule`至於他在做什麼呢？就是學長寫的程式有可能會更新，那不可能我們要拿到新的版本要重新複製一份下來改吧，那`git submodule`就可以想更新就可以更新了。那以御熊學長的Serial舉例

```shell
cd deps  #進入deps的資料夾中（如果在cmake_test的資料夾中）
git submodule add git@gitlab.ical.tw:b1065144/serial.git
```



接下來我們來看`./lib`裡的CMakeLists.txt

- 第一個要改的地方在第4行的地方，這決定了函式庫的名字，也就是先前我說的`lib<name>.a` 
- 第二的地方在第6行，把在這裡寫的`.h`加進來



接著來看`./util跟./test`

- 第一個部份就是第四行`PROJECT_NAME`
- 第二個部份就是第六行的`PROJECT_DEPS`，注意這個部份會又順序性的問題以serial做舉例好了

