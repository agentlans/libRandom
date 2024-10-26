#include "RandomC.h"
#include <stdio.h>

// gcc Example.c ../build/libRandomLib_static.a -I../include/ -lstdc++ -lm

int main() {
    int err = 0;

    // New random generator
    random_t* ran = random_new();
    if (ran == NULL) {
        printf("Failed to create random generator\n");
        return 1;
    }

    // Generate random normally-distributed value
    double x = random_normal(ran, 0, 1, &err);
    if (err) {
        printf("Error generating normal distribution\n");
    } else {
        printf("Normal distribution result: %f\n", x);
    }

    // Sample 3 integers from [0,10) without replacement
    int foo[3];
    random_sample(ran, 10, 3, foo);
    printf("Sampled integers: ");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", foo[i]);
    }
    printf("\n");

    // Demonstrate error handling with invalid parameters
    double invalid_result = random_exponential(ran, -1, &err);
    if (err) {
        printf("Error occurred with invalid exponential distribution parameters\n");
    } else {
        printf("Exponential distribution result (should not see this): %f\n", invalid_result);
    }

    // Clean up
    random_free(ran);

    return 0;
}

