#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  if (check_matr(A)) {
    if (A->rows == A->columns) {
      *result = calc_determinant(A);
    } else {
      res = 1;
    }
  } else {
    res = 2;
  }
  return res;
}

double calc_determinant(matrix_t *A) {
  double res = 0;
  if (A->rows == 1) {
    res = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->rows; i++) {
      separate_matr(A, &tmp, 0, i);
      res += pow(-1, i) * A->matrix[0][i] * calc_determinant(&tmp);
    }
    s21_remove_matrix(&tmp);
  }
  return res;
}