//
// Created by Иван Насекин on 06.02.2026.
//
#include <iostream>

void printValue(const int* ptr) {
  std::cout << *ptr << '\n';
};

void printValueRef(const int& ptr) {
  std::cout << ptr << '\n';
};

void tryModify(const int* ptr) {
  // *ptr = 200; error: read-only variable is not assignable
};

void setValue(int* ptr, int newValue) {
  *ptr = newValue;
};