#include "../inc/test.h"
structForTestS structForTest =
{
		.varDouble = 2.0,
		.varInt = 3
};

double add(double a, double b)
{
	return a + b;
}

void setup(void)
{
    puts("\nRuns before the test");
	printf("var init = %d\n"
			"var init = %f\n",
			structForTest.varInt,
			structForTest.varDouble);
}

void finish(void)
{
    puts("\nRuns after the test");
    structForTest.varInt = 0;
    structForTest.varDouble = 0.0;
	printf("var finish = %d\n"
			"var finish = %f\n",
			structForTest.varInt,
			structForTest.varDouble);
}

void crash(void)
{
    int *ptr = NULL;
    *ptr = 42;
}
