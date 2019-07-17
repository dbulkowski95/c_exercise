#include <criterion/criterion.h>
#include "add.h"

<<<<<<< HEAD
Test(simpleTestSuite, simpleTest)
{
	double c = add(1,2);
	cr_assert(true, "This test will always pass.");
}
=======
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
>>>>>>> [task] C exercise
