## ex2

本篇範例使用CMake以最簡單的方式，結合兩個檔案。那為了使`ex2/src`的資料夾下不會有原始碼以外的檔案我們先在`ex2/`建立`build`資料夾，並且使用CMake製作Makefile並以make進行編譯

```shell
#in ex2
mkdir build
cd build
cmake ../src
make
```

執行完即可看到執行擋在build資料夾

接著我們來看`CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 2.6)

project(ex2)
add_executable(ex2 main.cpp calc.cpp)
```

所以只要將相關的`.c`檔加入`add_executable(<exe file name> ....)`即可做連結，就不用像`gcc`編譯一樣打那麼多指令



