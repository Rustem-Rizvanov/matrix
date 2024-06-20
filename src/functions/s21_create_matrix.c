#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int res = 0;
  if (rows > 0 && columns > 0 && result != NULL) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double*)malloc(columns * sizeof(double));
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
  } else {
    res = 1;
  }
  return res;
}