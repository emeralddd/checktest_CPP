# Check test using CPP

## Setting: conf/*

### tests.txt

Number of tests will be tested!

### compare.txt

First line, write the path of file .OUT

Second line, write the path of file .ANS

### gcc.txt

If you can use `g++.exe` command in CMD, just write `!`

But if you can't, write the path to `g++.exe`, normally at `C:\Program Files\CodeBlocks\MinGW\bin\g++.exe`

## Source

### MAIN.cpp

This is the main file, only edit if you know what you are doing.

### genInp.cpp

Write the generate input file code!

### genOut.cpp

Write the correct code to solve the problem! Remember to write to `.ans` file!

### sourceCode.cpp

Write the code you want to check!

## To start, just compile and debug the MAIN.cpp