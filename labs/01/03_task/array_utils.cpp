//
// Created by Иван Насекин on 06.02.2026.
//

#include "array_utils.h"
#include <iomanip>
#include <iostream>

void fillArray(int* arr, int size) {
  for(int i = 0; i < size; i++) {
    std::cout << std::left << std::setw(5) << i
          << std::setw(25) << (i + 1) * 7
          << std::setw(25) << &arr[i]
          << std::setw(25) << arr + i;
    if (i == 0) {
      std::cout << std::setw(25) << '-' << '\n';
    } else {
      std::cout << std::setw(25) << reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(&arr[i-1]) << '\n';
    }

    arr[i] = (i + 1) * 7;
  }
};