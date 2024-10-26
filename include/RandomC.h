#ifndef RANDOM_WRAPPER_H
#define RANDOM_WRAPPER_H

#ifdef __cplusplus
#include "Random.hpp"
typedef Random random_t;
#else
typedef void random_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

random_t *random_new();
random_t *random_new_seeded(unsigned int seed);
void random_reseed(random_t *gen, unsigned int seed);
void random_free(random_t *gen);

// Function declarations for the C wrappers
int random_binomial(random_t *gen, int t, double p);
double random_cauchy(random_t *gen, double a, double b);
double random_chi_squared(random_t *gen, double n);
double random_exponential(random_t *gen, double lambda);
double random_extreme_value(random_t *gen, double a, double b);
double random_fisher_f(random_t *gen, double m, double n);
double random_gamma(random_t *gen, double alpha, double beta);
int random_geometric(random_t *gen, double p);
double random_lognormal(random_t *gen, double m, double s);
int random_negative_binomial(random_t *gen, int k, double p);
double random_normal(random_t *gen, double mean, double stddev);
int random_poisson(random_t *gen, double mean);
double random_student_t(random_t *gen, double n);
int random_uniform_int(random_t *gen, int a, int b);
double random_uniform_real(random_t *gen, double a, double b);
double random_weibull(random_t *gen, double a, double b);

// Shuffles a list of n integers
void random_shuffle(random_t *gen, int *arr, int n);
void random_shuffle_long(random_t* gen, long* arr, long n);
// Selects r integers from [0..n) without replacement and stores them in results
void random_sample(random_t *gen, int n, int r, int *results);
void random_sample_long(random_t* gen, long n, long r, long* results);

#ifdef __cplusplus
}
#endif

#endif // RANDOM_WRAPPER_H
