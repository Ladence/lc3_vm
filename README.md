# Little Computer 3 Virtual Machine

[![CodeFactor](https://www.codefactor.io/repository/github/ladence/lc3_vm/badge)](https://www.codefactor.io/repository/github/ladence/lc3_vm)
[![CMake Build Matrix](https://github.com/Ladence/lc3_vm/actions/workflows/ci.yml/badge.svg)](https://github.com/Ladence/lc3_vm/actions/workflows/ci.yml)
## Description
My virtual machine for Little Computer 3 (Assembly language) written on C++

## ISA
LC3 supports 16-bit instructions, you can see them by the [link](https://justinmeiners.github.io/lc3-vm/supplies/lc3-isa.pdf)

## Testing
This project is being covered by GTest (supplied as conan requirement)

## Build & Run

Make sure that you have installed `conan` package manager 
1. Clone project
2. mkdir build && cd build/
3. conan install ..
4. cmake ..
5. make
6. bin/lc3_vm [path to example iso]