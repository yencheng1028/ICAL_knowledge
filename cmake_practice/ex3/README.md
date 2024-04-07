## ex3

本範例示範，利用資料夾拆開，`lib function`跟 `main function` 

從`ex3/lib/CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.2)
project(calc)
add_library(calc calc.cpp)
```

- 其中`project(calc)`指定project名稱，之後可以作為參考變數
- `add_library(<name> [<source> .....])` 可以將程式做成函式庫，做完就會變成`lib<name>.a`檔



 從`ex3/test/CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.2)

project(App)
include_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(app main.cpp)
target_link_libraries(app calc)
```

- `include_directories(${CMAKE_SOURCE_DIR}/lib)`，其中`${CMAKE_SOURCE_DIR}`指的是下`cmake `這個指令的指定目錄，那`include_directories(${CMAKE_SOURCE_DIR}/lib})`代表.h檔的目錄。
- `target_link_libraries(app calc)`指定app 要和哪些函式庫做連結



從`ex3/CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.2)
project(Ex3)

add_subdirectory(lib)
add_subdirectory(test)
```

- `add_subdirectory`告訴cmake還有執行子目錄下的CMakeLists.txt