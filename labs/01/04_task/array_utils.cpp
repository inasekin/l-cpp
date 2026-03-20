//
// Created by Иван Насекин on 07.02.2026.
//

#include "array_utils.h"

void modifyElementsOnly(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i * size;
  }
};

void reallocateArray(int*& arr, int& size) {
  delete[] arr;
  size *= 2;
  int* newArr = new int[size];

  modifyElementsOnly(newArr, size);

  arr = newArr;
};

void fakeByValue(int* arr, int size) {
  arr = nullptr;
};