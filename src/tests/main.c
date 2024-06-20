#include <check.h>

#line 1 "tests.check"
#include <time.h>

#include "s21_matrix.h"

START_TEST(create_matrix_OK) {
#line 9
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(rand() % 100, rand() % 100, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix__err_1) {
#line 16
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-rand() % 100, rand() % 100, &A),
                   INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix__err_2) {
#line 21
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(rand() % 100, -rand() % 100, &A),
                   INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix__err_3) {
#line 26
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-rand() % 100, -rand() % 100, &A),
                   INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix__err_4) {
#line 31
  srand(time(NULL));
  ck_assert_int_eq(s21_create_matrix(-rand() % 100, rand() % 100, NULL),
                   INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_eq_matrix__fail_1) {
#line 37
  srand(time(NULL));
  matrix_t A;
  s21_create_matrix(10, 10, &A);
  matrix_t B;
  s21_create_matrix(10, 10, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_OK) {
#line 53
  srand(time(NULL));
  matrix_t A;
  s21_create_matrix(10, 10, &A);
  matrix_t B;
  s21_create_matrix(10, 10, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix__fail_2) {
#line 53
  srand(time(NULL));
  matrix_t A;
  s21_create_matrix(10, 10, &A);
  matrix_t B;
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_OK_1) {
#line 71
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  s21_create_matrix(10, 10, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_sum_matrix_OK_2) {
#line 92
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 20, &A);
  s21_create_matrix(10, 20, &B);
  s21_create_matrix(10, 20, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_sum_matrix_OK_3) {
#line 113
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 1, &B);
  s21_create_matrix(10, 1, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      B.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_sum_matrix__err_1) {
#line 133
  matrix_t A, B, RES;
  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 2, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &RES), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix__err_2) {
#line 141
  matrix_t A, B, RES;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(1, 50, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &RES), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix__err_3) {
#line 149
  matrix_t B, RES;
  s21_create_matrix(1, 50, &B);
  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &RES), INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix__err_5) {
#line 155
  matrix_t A, B;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(10, 50, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_OK_1) {
#line 166
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  s21_create_matrix(10, 10, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_sub_matrix_OK_2) {
#line 187
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 20, &A);
  s21_create_matrix(10, 20, &B);
  s21_create_matrix(10, 20, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_sub_matrix_OK_3) {
#line 208
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 1, &B);
  s21_create_matrix(10, 1, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      B.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_sub_matrix__err_1) {
#line 228
  matrix_t A, B, RES;
  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 2, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix__err_2) {
#line 236
  matrix_t A, B, RES;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(1, 50, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix__err_3) {
#line 244
  matrix_t B, RES;
  s21_create_matrix(1, 50, &B);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &RES), INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix__err_5) {
#line 251
  matrix_t A, B;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(10, 50, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_OK_1) {
#line 262
  matrix_t A, RES, REAL;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &REAL);
  double n = (rand() % 1000 + 100) * 2;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] * n;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, n, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_mult_number_OK_2) {
#line 262
  matrix_t A, RES, REAL;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &REAL);
  double n = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] * n;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, n, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_mult_matrix_OK_1) {
#line 282
  matrix_t A, B, RES, REAL;

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &B), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &REAL), 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100;
    }
  }
  for (int i = 0; i < REAL.rows; i++) {
    for (int j = 0; j < REAL.columns; j++) {
      REAL.matrix[i][j] = 0;
      for (int m = 0; m < B.rows; m++)
        REAL.matrix[i][j] += A.matrix[i][m] * B.matrix[m][j];
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_mult_matrix_OK_2) {
#line 282
  matrix_t A, B, REAL;

  ck_assert_int_eq(s21_create_matrix(3, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &B), 0);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &REAL), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_OK_1) {
#line 314
  matrix_t A, RES, REAL;

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &REAL), 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100;
      REAL.matrix[j][i] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(s21_calc_complements_OK2) {
#line 333
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 1.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_OK3) {
#line 346
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_OK0) {
#line 365
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_OK1) {
#line 384
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[0][2] = -20.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  C.matrix[1][2] = 8.0;
  C.matrix[2][0] = -8.0;
  C.matrix[2][1] = -2.0;
  C.matrix[2][2] = 4.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements__err_1) {
#line 413
  matrix_t a = {0};
  matrix_t b = {0};
  ck_assert_int_eq(s21_calc_complements(&a, &b), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_calc_complements__err_2) {
#line 420
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &b), CALC_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_calc_complements_OK4) {
#line 428
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;
  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;
  matrix_t res = {0};
  s21_calc_complements(&m, &res);
  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_calc_complements_OK5) {
#line 460
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &b), CALC_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_inverse_matrix_OK1) {
#line 469
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 44300.0 / 367429.0;
  C.matrix[0][1] = -236300.0 / 367429.0;
  C.matrix[0][2] = 200360.0 / 367429.0;
  C.matrix[1][0] = 20600.0 / 367429.0;
  C.matrix[1][1] = 56000.0 / 367429.0;
  C.matrix[1][2] = -156483.0 / 367429.0;
  C.matrix[2][0] = 30900.0 / 367429.0;
  C.matrix[2][1] = 84000.0 / 367429.0;
  C.matrix[2][2] = -51010.0 / 367429.0;
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_OK2) {
#line 498
  matrix_t A = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B = {0};
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_OK3) {
#line 528
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_double_eq_tol(result.matrix[0][0], 1.0 / m.matrix[0][0], 1e-6);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_OK4) {
#line 528
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 0;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_OK5) {
#line 528
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(2, 1, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(s21_determinant_OK1) {
#line 543
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_OK2) {
#line 557
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_OK3) {
#line 573
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  ck_assert_int_eq(s21_determinant(&m, &res), OK);
  ck_assert_double_eq_tol(res, 2480, 1e-6);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_OK4) {
  matrix_t m = {0};
  s21_create_matrix(2, 3, &m);
  double res = 0;
  ck_assert_int_eq(s21_determinant(&m, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("MATRIX");
  TCase *tc1_1 = tcase_create("s21_create_matrix");
  TCase *tc1_2 = tcase_create("s21_eq_matrix");
  TCase *tc1_3 = tcase_create("s21_sum_matrix");
  TCase *tc1_4 = tcase_create("s21_sub_matrix");
  TCase *tc1_5 = tcase_create("s21_mult_number");
  TCase *tc1_6 = tcase_create("s21_mult_matrix");
  TCase *tc1_7 = tcase_create("s21_transpose");
  TCase *tc1_8 = tcase_create("s21_calc_complements");
  TCase *tc1_9 = tcase_create("s21_determinant");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_loop_test(tc1_1, create_matrix_OK, 0, 10);
  tcase_add_test(tc1_1, create_matrix__err_1);
  tcase_add_test(tc1_1, create_matrix__err_2);
  tcase_add_test(tc1_1, create_matrix__err_3);
  tcase_add_test(tc1_1, create_matrix__err_4);
  suite_add_tcase(s1, tc1_2);
  tcase_add_test(tc1_2, s21_eq_matrix__fail_1);
  tcase_add_test(tc1_2, s21_eq_matrix__fail_2);
  tcase_add_test(tc1_2, s21_eq_matrix_OK);
  suite_add_tcase(s1, tc1_3);
  tcase_add_test(tc1_3, s21_sum_matrix_OK_1);
  tcase_add_test(tc1_3, s21_sum_matrix_OK_2);
  tcase_add_test(tc1_3, s21_sum_matrix_OK_3);
  tcase_add_test(tc1_3, s21_sum_matrix__err_1);
  tcase_add_test(tc1_3, s21_sum_matrix__err_2);
  tcase_add_test(tc1_3, s21_sum_matrix__err_3);
  tcase_add_test(tc1_3, s21_sum_matrix__err_5);
  suite_add_tcase(s1, tc1_4);
  tcase_add_test(tc1_4, s21_sub_matrix_OK_1);
  tcase_add_test(tc1_4, s21_sub_matrix_OK_2);
  tcase_add_test(tc1_4, s21_sub_matrix_OK_3);
  tcase_add_test(tc1_4, s21_sub_matrix__err_1);
  tcase_add_test(tc1_4, s21_sub_matrix__err_2);
  tcase_add_test(tc1_4, s21_sub_matrix__err_3);
  tcase_add_test(tc1_4, s21_sub_matrix__err_5);
  suite_add_tcase(s1, tc1_5);
  tcase_add_loop_test(tc1_5, s21_mult_number_OK_1, 0, 10);
  tcase_add_loop_test(tc1_5, s21_mult_number_OK_2, 0, 10);
  suite_add_tcase(s1, tc1_6);
  tcase_add_loop_test(tc1_6, s21_mult_matrix_OK_1, 0, 10);
  tcase_add_test(tc1_6, s21_mult_matrix_OK_2);
  suite_add_tcase(s1, tc1_7);
  tcase_add_loop_test(tc1_7, s21_transpose_OK_1, 0, 10);
  suite_add_tcase(s1, tc1_8);
  tcase_add_test(tc1_8, s21_calc_complements_OK0);
  tcase_add_test(tc1_8, s21_calc_complements_OK1);
  tcase_add_test(tc1_8, s21_calc_complements_OK2);
  tcase_add_test(tc1_8, s21_calc_complements_OK3);
  tcase_add_test(tc1_8, s21_calc_complements_OK4);
  tcase_add_test(tc1_8, s21_calc_complements_OK5);
  tcase_add_test(tc1_8, s21_calc_complements__err_1);
  tcase_add_test(tc1_8, s21_calc_complements__err_2);
  tcase_add_test(tc1_8, s21_inverse_matrix_OK1);
  tcase_add_test(tc1_8, s21_inverse_matrix_OK2);
  tcase_add_test(tc1_8, s21_inverse_matrix_OK3);
  tcase_add_test(tc1_8, s21_inverse_matrix_OK4);
  tcase_add_test(tc1_8, s21_inverse_matrix_OK5);
  suite_add_tcase(s1, tc1_9);
  tcase_add_test(tc1_9, s21_determinant_OK1);
  tcase_add_test(tc1_9, s21_determinant_OK2);
  tcase_add_test(tc1_9, s21_determinant_OK3);
  tcase_add_test(tc1_9, s21_determinant_OK4);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}