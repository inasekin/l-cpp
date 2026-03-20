//
// Created by Иван Насекин on 07.02.2026.
//

#pragma once

int** createMatrix(int rows, int cols);

void fillMatrix(int** matrix, int rows, int cols);

void printMatrix(int** matrix, int rows, int cols);

void freeMatrix(int** matrix, int rows);

void resizeMatrix(int**& matrix, int& rows, int& cols, int newRows, int newCols);