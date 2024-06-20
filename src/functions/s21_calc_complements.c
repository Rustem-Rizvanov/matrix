#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (check_matr(A) && result) {
    if (A->rows == A->columns) {
      res = s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        double x = 0;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->rows; j++) {
            matrix_t tmp = {0};
            s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
            separate_matr(A, &tmp, i, j);
            s21_determinant(&tmp, &x);
            result->matrix[i][j] = pow(-1, i + j) * x;
            s21_remove_matrix(&tmp);
          }
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