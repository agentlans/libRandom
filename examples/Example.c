#include "RandomC.h"

// gcc Example.c ../build/libRandomLib_static.a -I../include/ -lstdc++ -lm

#include <stdio.h>

int main() {
	// New random generator
	random_t* ran = random_new();

	// Generate random normally-distributed value
	double x = random_normal(ran, 0, 1);
	printf("%f\n", x);

	// Sample 3 integers from [0,10) without replacement
	int foo[3];
	random_sample(ran, 10, 3, foo);
	for (int i = 0; i < 3; ++i) {
		printf("%d\n", foo[i]);
	}

	// Clean up
	random_free(ran);
}
