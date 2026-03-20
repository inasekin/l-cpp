//
// Created by Иван Насекин on 07.02.2026.
//

#include "matrix_utils.h"
#include <iostream>

int ** createMatrix(int rows, int cols) {
  int** rowsM = new int*[rows]{};

  for (int i = 0; i < rows; i++) {
    rowsM[i] = new int[cols]{};
  }

  return rowsM;
};

void fillMatrix(int** matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = i * j;
    }
  }
};

void printMatrix(int** matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
};

void freeMatrix(int** matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;
};

void resizeMatrix(int**& matrix, int& rows, int& cols, int newRows, int newCols) {
  auto newMatrix = createMatrix(newRows, newCols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      newMatrix[i][j] = matrix[i][j];
    }
  }

  freeMatrix(matrix, rows);
  rows = newRows;
  cols = newCols;
  matrix = newMatrix;
};