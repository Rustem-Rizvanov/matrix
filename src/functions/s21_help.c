#include "../s21_matrix.h"

void separate_matr(matrix_t *A, matrix_t *res, int x, int y) {
  for (int i = 0, r = 0; r < A->rows; r++) {
    if (r == x) continue;
    for (int j = 0, c = 0; c < A->columns; c++) {
      if (c == y) continue;
      res->matrix[i][j] = A->matrix[r][c];
      j++;
    }
    i++;
  }
}

int check_matr(matrix_t *A) {
  return ((A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0)
              ? 0
              : 1);
}