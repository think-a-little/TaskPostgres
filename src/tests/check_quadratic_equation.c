#include <check.h>
#include <stdio.h>

#include "../headers/quadratic_equation.h"

START_TEST(eq_test_0) {
  {
    Answer answer = solve_equation(-1, 1, 1);
    ck_assert_int_eq(2, answer.root_count);
    ck_assert_double_eq_tol(answer.x[0], -0.618, 0.0001);
    ck_assert_double_eq_tol(answer.x[1], 1.618, 0.0001);
    free(answer.x);
  }
}
END_TEST

START_TEST(eq_test_1) {
  {
    Answer answer = solve_equation(1, 2, 1);
    ck_assert_int_eq(1, answer.root_count);
    ck_assert_double_eq_tol(answer.x[0], -1., 0.0001);
    free(answer.x);
  }
}
END_TEST

START_TEST(eq_test_2) {
  {
    Answer answer = solve_equation(1, 1, 1);
    ck_assert_int_eq(0, answer.root_count);
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf = 0;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, eq_test_0);
  tcase_add_test(tc1_1, eq_test_1);
  tcase_add_test(tc1_1, eq_test_2);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}