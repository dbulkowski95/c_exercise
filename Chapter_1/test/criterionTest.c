#include <criterion/criterion.h>
#include <criterion/types.h>
#include <signal.h>
#include <criterion/theories.h>
#include "../inc/test.h"

#ifdef _WIN32
# include <windows.h>
# define sleep(x)    Sleep(x * 1000)
#else
# include <unistd.h>
#endif

/*Difference between assert and expect*/
Test(simpleTestSuite, trueAssert)
{
	printf("ASSERT TRUE BEFORE\n");
	cr_assert(true, "This test will always pass.");
	printf("ASSERT TRUE AFTER\n");
}

Test(simpleTestSuite, falseAssert)
{
	printf("\nASSERT BEFORE\n");
	cr_assert(false, "This test will always fail.");
	printf("ASSERT AFTER\n");
}

Test(simpleTestSuite, trueExpect)
{
	printf("EXPECT TRUE BEFORE\n");
	cr_expect(true, "This test will always pass.");
	printf("EXPECT TRUE AFTER\n");
}
//
Test(simpleTestSuite, falseExpect)
{
	printf("EXPECT BEFORE\n");
	cr_expect(false, "This test will always fail.");
	printf("EXPECT AFTER\n");
}

/*Passes if Condition is false*/
Test(simpleTestSuite, cr_assert_not)
{
	cr_assert_not(1 != 1, "This test will always fail.");
}

//  cr_expect_eq	 [Passes if Actual is equal to Expected]
Test(simpleTestSuite, cr_expect_eq)
{
	cr_expect_eq(1,1, "This test will always pass.");
	// cr_expect_neq [Passes if Actual is not equal to Unexpected]
	// cr_expect_lt  [Passes if Actual is less than Reference]
	// cr_expect_gt  [Passes if Actual is greater than Reference]
	// cr_expect_geg [Passes if Actual is greater or equal to Reference]
}

Test(simpleTestSuite, cr_assert_float_eq)
{
	// cr_assert_float_eq [Passes if Actual is equal to Expected with a tolerance of Epsilon]
	cr_assert_float_eq(1,1.7, 0.5, "This test will always fail.");
	// cr_assert_float_neq [Passes if Actual is not equal to Unexpected with a tolerance of Epsilon]
}

Test(simpleTestSuite, cr_assert_str_empty)
{
	// cr_assert_str_empty     [Passes if Value is an empty string]
	// cr_assert_str_not_empty [Passes if Value is not an empty string]
	// cr_assert_str_eq        [Passes if Actual is lexicographically equal to Expected]
	// cr_assert_str_neq       [Passes if Actual is not lexicographically equal to Unexpected]
	// cr_assert_str_lt		   [Passes if Actual is lexicographically less than Reference]
	// cr_assert_str_leq	   [Passes if Actual is lexicographically less or equal to Reference]
	//cr_assert_str_gt 		   [Passes if Actual is lexicographically greater than Reference]
	//cr_assert_str_geq        [Passes if Actual is lexicographically greater or equal to Reference]
	char str[10] = "david";
	char str1[10] = "ala";
	cr_assert_str_not_empty(str, "This test will always pass.");
	cr_expect_str_lt(str, str1);
}

Test(simpleTestSuite, cr_assert_arr_eq)
{
	// cr_assert_arr_eq        [Passes if Actual is byte-to-byte equal to Expected]
	// cr_assert_arr_neq	   [Passes if Actual is not byte-to-byte equal to Expected]
#define SIZE 3
	int tab[SIZE] = {1,2,3};
	int tab1[SIZE] = {1,2,3};
	cr_assert_arr_eq(tab, tab1, SIZE * sizeof (int));
}
Test(simpleTestSuite, assert_null)
{
	// cr_assert_not_null 	   [Passes if Value is not NULL]
	int* ptr_p = NULL;
	cr_assert_not_null(ptr_p, "This test will always pass.");
}

Test(simpleTestSuite, assert_null_with_addr)
{
	// cr_assert_null		   [Passes if Value is NULL]
	int a = 7;
	int* ptr_p = &a;
	cr_assert_null(ptr_p, "This test will always fail.");
}

Test(simpleTestSuite, assert_not_null)
{
	// cr_assert_not_null 	   [Passes if Value is not NULL]
	int a = 7;
	int* ptr_p = &a;
	cr_assert_not_null(ptr_p, "This test will always pass.");
}


/* struct criterion_test_extra_data [Contains all the options that can be set for a test,
 * through the Test and TestSuite macros, or other means]
 *
 * void (*init)(void) 	[The setup test fixture]
 * void (*fini)(void)	[The teardown test fixture]
 * int signal			[The expected signal to be raised by the test]
 * 		* SIGSEGV		[STATUS_ACCESS_VIOLATION, STATUS_DATATYPE_MISALIGNMENT...]
 * 		* SIGILL		[STATUS_ILLEGAL_INSTRUCTION, STATUS_PRIVILEGED_INSTRUCTION...]
 * 		* SIGINT		[STATUS_CONTROL_C_EXIT]
 * 		* SIGFPE		[STATUS_FLOAT_DENORMAL_OPERAND, STATUS_FLOAT_DIVIDE_BY_ZERO...]
 * 		* SIGALRM		[STATUS_TIMEOUT]
 * exit_code			[The expected exit status to be returned by the test]
 * disabled				[If true, skips the test]
 * description			[The long description of a test]
 * timeout				[The timeout for the test, in seconds]
 * data					[Extra user data]*/

Test(simpleTestSuite, initAndFinish, .init = setup, .fini = finish)
{
	printf("\nTEST CASE BODY\n");
}

Test(simpleTestSuite, failing, .disabled = true)
{
	crash();
}

Test(simpleTestSuite, passing, .signal = SIGSEGV)
{
	crash();
}
//
TestSuite(suite_name, .init = setup, .fini = finish);
//
Test(suite_name, test_1, .description = "Just a failing test")
{
	structForTest.varDouble = -3.14;
	structForTest.varInt = 7;
	printf("var inside test = %d\n"
			"var inside test = %f\n",
			structForTest.varInt,
			structForTest.varDouble);
	printf("\ninside test\n");
}
//
//
Test(suite_name, test_2, .timeout = 0.5)
{
	for ( long int i = 0; i < 10; i++) { sleep(10); }
}

Test(suite_name, test_3, .timeout = 2)
{
	sleep(1);
	printf("\ninside test\n");
}

Test(sample, testCriterion)
{
    cr_expect(0);
    cr_assert(1);
}

ReportHook(PRE_INIT)(struct criterion_test *test)
{
    printf("testing %s in category %s\n", test->name, test->category);
}

ReportHook(POST_TEST)(struct criterion_test_stats *stats) {
    printf("Asserts: [%d passed, %d failed, %d total]\n",
            stats->passed_asserts, stats->failed_asserts, stats->passed_asserts + stats->failed_asserts);
}

ReportHook(PRE_ALL)(struct criterion_test_set *tests) {
    (void) tests;
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    puts("criterion_init");
}

ReportHook(POST_ALL)(struct criterion_global_stats *stats) {
    (void) stats;
    puts("criterion_fini");
}

Test(misc, skipping)
{
    cr_skip_test();
    cr_assert_fail("Skip before failing");
}

