#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows && res; i++) {
      for (int j = 0; j < A->columns && res; j++) {
        res =
            fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-7 ? SUCCESS : FAILURE;
      }
    }
  } else {
    res = FAILURE;
  }
  return res;
}