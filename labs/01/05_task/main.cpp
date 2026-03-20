//
// Created by Иван Насекин on 07.02.2026.
//

#include "matrix_utils.h"

int main() {
  int rows = 3;
  int cols = 4;
  auto matrix = createMatrix(rows, cols);

  fillMatrix(matrix, rows, cols);
  printMatrix(matrix, rows, cols);
  resizeMatrix(matrix, rows, cols, 5, 6);
  printMatrix(matrix, rows, cols);
  freeMatrix(matrix, rows);

  return 0;
}