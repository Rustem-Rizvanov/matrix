#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (check_matr(A) && check_matr(B) && result) {
    if (A->rows == B->rows && A->columns == B->columns) {
      res = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}