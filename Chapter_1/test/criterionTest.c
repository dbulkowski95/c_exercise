#include <criterion/criterion.h>
#include <criterion/types.h>
#include <signal.h>

#include "../inc/test.h"

#ifdef _WIN32
# include <windows.h>
# define sleep(x)    Sleep(x * 1000)
#else
# include <unistd.h>
#endif

//Test(simpleTestSuite, add)
//{
//	double c = add(1,2);
//	cr_expect(c == 3, "This test will always pass.");
//}

//Test(simpleTestSuite, trueAssert)
//{
//	printf("ASSERT TRUE PRZED\n");
//	cr_assert(true, "This test will always pass.");
//	printf("ASSERT TRUE PO\n");
//}

//Test(simpleTestSuite, falseAssert)
//{
//	printf("ASSERT PRZED\n");
//	cr_assert(false, "This test will always fail.");
//	printf("ASSERT PO\n");
//}
//
//Test(simpleTestSuite, trueExpect)
//{
//	printf("EXPECT TRUE PRZED\n");
//	cr_expect(true, "This test will always pass.");
//	printf("EXPECT TRUE PO\n");
//}
////
//Test(simpleTestSuite, falseExpect)
//{
//	printf("EXPECT PRZED\n");
//	cr_expect(false, "This test will always fail.");
//	printf("EXPECT PO\n");
//}
//
//Test(simpleTestSuite, initAndFinish, .init = setup, .fini = finish)
//{
//	printf("\nTEST CASE BODY\n");
//}
//
//Test(simpleTestSuite, failing)
//{
//	crash();
//}
//
//Test(simpleTestSuite, passing, .signal = SIGSEGV)
//{
//	crash();
//}
//
TestSuite(suite_name, .init = setup, .fini = finish);
//
//Test(suite_name, test_1, .description = "Just a failing test")
//{
//	printf("\ninside test\n");
//}
//
//Test(suite_name, test_2, .timeout = 0.5)
//{
//	for ( long int i = 0; i < 1000000000000; i++) { sleep(1); }
//	printf("\ninside test\n");
//}
//
Test(suite_name, skipped, .description = "This one is skipped", .disabled = false)
{

}
