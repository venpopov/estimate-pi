 #!/usr/bin/env bash
   
 files=$(ls *.cpp)
 clang++ -std=c++17 -O2 $files -o main.out
