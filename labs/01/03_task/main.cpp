//
// Created by Иван Насекин on 06.02.2026.
//

#include "array_utils.h"

#include <iomanip>
#include <iostream>

void printHeaderTable(std::string title) {
  std::cout << title << " массив" << '\n';
  std::cout << std::left << std::setw(5) << "i"
            << std::setw(25) << "Значение"
            << std::setw(25) << "arr[i]"
            << std::setw(25) << "(arr + i)"
            << std::setw(25) << "Разница" << '\n';
}

int main() {
  int staticArr[5];
  int* dynamicArr = new int[5];

  printHeaderTable("Статический");
  fillArray(staticArr, 5);
  std::cout << '\n';

  printHeaderTable("Динамический");
  fillArray(dynamicArr, 5);
  std::cout << '\n';

  std::cout << "sizeof(staticArr) = " << sizeof(staticArr) << " байт" << '\n';
  std::cout << "sizeof(dynamicArr) = " << sizeof(dynamicArr) << " байт" << '\n';


  delete[] dynamicArr;

  return 0;
}