#include <criterion/criterion.h>
#include "add.h"

Test(simpleTestSuite, add)
{
	double c = add(1,2);
	cr_expect(c == 3, "This test will always pass.");
}

Test(simpleTestSuite, true)
{
	cr_assert(true, "This test will always pass.");
}

Test(simpleTestSuite, fail)
{
	cr_assert(false, "This test will always fail.");
}
