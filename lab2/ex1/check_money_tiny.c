#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "money.h"

Money *five_dollars;
Money *null_dollars;

void setup(void) {
    five_dollars = money_create(5, "USD");
}

void setup_lt0(void) {
    null_dollars = money_create(-1, "USD");
}

void teardown_lt0(void) {
    money_free(null_dollars);
}

void teardown(void) {
    money_free(five_dollars);
}

START_TEST(test_money_create_amount) {
    ck_assert_double_eq(money_amount(five_dollars), 5);
}
END_TEST

START_TEST(test_money_create_amount_lt0) {
    ck_assert_ptr_null(null_dollars);
}
END_TEST

START_TEST(test_money_currency) {
    ck_assert_str_eq(money_currency(five_dollars), "USD");
}
END_TEST

Suite * money_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_core_lt0;

    s = suite_create("Money");

    tc_core = tcase_create("Core");
    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_money_create_amount);
    tcase_add_test(tc_core, test_money_currency);
    suite_add_tcase(s, tc_core);

    tc_core_lt0 = tcase_create("Negative amount");
    tcase_add_checked_fixture(tc_core_lt0, setup_lt0, teardown_lt0);
    tcase_add_test(tc_core_lt0, test_money_create_amount_lt0);
    suite_add_tcase(s, tc_core_lt0);

    return s;
}


int main(void) {
    double number_failed;
    Suite *s;
    SRunner *sr;

    s = money_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
