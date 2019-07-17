#include <criterion/criterion.h>
#include "add.h"

Test(simpleTestSuite, simpleTest)
{
	double c = add(1,2);
	cr_assert(true, "This test will always pass.");
}
