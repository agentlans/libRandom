#ifndef RANDOMC_H
#define RANDOMC_H

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

int random_binomial(random_t *gen, int t, double p, int* err);
double random_cauchy(random_t *gen, double a, double b, int* err);
double random_chi_squared(random_t *gen, double n, int* err);
double random_exponential(random_t *gen, double lambda, int* err);
double random_extreme_value(random_t *gen, double a, double b, int* err);
double random_fisher_f(random_t *gen, double m, double n, int* err);
double random_gamma(random_t *gen, double alpha, double beta, int* err);
int random_geometric(random_t *gen, double p, int* err);
double random_lognormal(random_t *gen, double m, double s, int* err);
int random_negative_binomial(random_t *gen, int k, double p, int* err);
double random_normal(random_t *gen, double mean, double stddev, int* err);
int random_poisson(random_t *gen, double mean, int* err);
double random_student_t(random_t *gen, double n, int* err);
int random_uniform_int(random_t *gen, int a, int b, int* err);
double random_uniform_real(random_t *gen, double a, double b, int* err);
double random_weibull(random_t *gen, double a, double b, int* err);

void random_shuffle(random_t* gen, int* arr, int n);
void random_sample(random_t* gen, int n, int r, int* results);
void random_shuffle_long(random_t* gen, long* arr, long n);
void random_sample_long(random_t* gen, long n, long r, long* results);

#ifdef __cplusplus
}
#endif

#endif // RANDOMC_H

