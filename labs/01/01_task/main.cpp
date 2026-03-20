//
// Created by Иван Насекин on 06.02.2026.
//
#include <iostream>
#include "modifiers.h"

void demonstrateBasicDifferences() {
  int a = 10;

  std::cout << "Вызов modifyByValue(а):" << '\n';
  std::cout << "До вызова: a = " << a << ", адрес a: " << &a << '\n';
  modifyByValue(a);
  std::cout << "После вызов: a = " << a << '\n';
  std::cout << " " << '\n';
  std::cout << "Вызов modifyByPointer(а):" << '\n';
  std::cout << "До вызова: a = " << a << ", адрес a: " << &a << '\n';
  modifyByPointer(&a);
  std::cout << "После вызов: a = " << a << '\n';
  std::cout << " " << '\n';
  std::cout << "Вызов modifyByReference(а):" << '\n';
  std::cout << "До вызова: a = " << a << ", адрес a: " << &a << '\n';
  modifyByReference(a);
  std::cout << "После вызов: a = " << a << '\n';
}

int main() {
  demonstrateBasicDifferences();

  return 0;
}