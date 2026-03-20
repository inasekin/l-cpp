//
// Created by Иван Насекин on 06.02.2026.
//

#include <iostream>
#include "modifiers.h"

void modifyByValue(int x) {
  std::cout << "Внутри modifyByValue:" << '\n';
  std::cout << "Адрес x: " << &x << ", значение x: " << x << '\n';

  x = 999;

  std::cout << "После изменения (внутри функции): x = " << x << '\n';
};

void modifyByPointer(int* x) {
  std::cout << "Внутри modifyByPointer:" << '\n';
  std::cout << "Адрес x: " << x << ", значение x: " << *x << '\n';

  *x = 999;

  std::cout << "После изменения (внутри функции): x = " << *x << '\n';
};

void modifyByReference(int& x) {
  std::cout << "Внутри modifyByReference:" << '\n';
  std::cout << "Адрес x: " << &x << ", значение x: " << x << '\n';

  x = 999;

  std::cout << "После изменения (внутри функции): x = " << x << '\n';
};
