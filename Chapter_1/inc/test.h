#include <stdio.h>
#include <stdlib.h>

typedef struct structForTestS
{
	int varInt;
	double varDouble;
}structForTestS;

double add(double a, double b);
void setup(void);
void finish(void);
void crash(void);

extern structForTestS structForTest;
