//
// Created by Иван Насекин on 07.02.2026.
//

#include "array_utils.h"

#include <iostream>
#include <ostream>

void printElements(int* arr, int size) {
  std::cout << arr << '\n';
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << '\n';
  }
}

int main() {
  int arraySize = 3;
  int* data = new int[arraySize]{1, 2, 3};

  printElements(data, arraySize);
  modifyElementsOnly(data, arraySize);
  printElements(data, arraySize);
  fakeByValue(data, arraySize);
  printElements(data, arraySize);
  reallocateArray(data, arraySize);
  printElements(data, arraySize);

  delete[] data;

  return 0;
}