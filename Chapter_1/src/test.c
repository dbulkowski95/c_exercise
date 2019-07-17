#include "../inc/test.h"
static dupa dupa1 =
{
		.doubleZmienna = 2.0,
		.zmienna = 3
};
double add(double a, double b)
{
	return a + b;
}

void setup(void)
{
    puts("\nRuns before the test");
	printf("dupa init = %d\n"
			"dupa init = %f\n",
			dupa1.zmienna,
			dupa1.doubleZmienna);
}

void finish(void)
{
    puts("\nRuns after the test");
    dupa1.zmienna = 0;
    dupa1.doubleZmienna = 0.0;
	printf("dupa finish = %d\n"
			"dupa finish = %f\n",
			dupa1.zmienna,
			dupa1.doubleZmienna);
}

void crash(void)
{
    int *ptr = NULL;
    *ptr = 42;
}
