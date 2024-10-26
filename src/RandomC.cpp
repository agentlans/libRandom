#include <iostream>
#include <stdexcept>

#include "RandomC.h"

random_t *random_new() {
    return new Random();
}

random_t *random_new_seeded(unsigned int seed) {
    return new Random(seed);
}

void random_reseed(random_t *gen, unsigned int seed) {
    gen->seed(seed);
}

void random_free(random_t *gen) {
    delete reinterpret_cast<Random *>(gen);
}

int random_binomial(random_t *gen, int t, double p, int* err) {
    try {
        int result = gen->binomial(t, p);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0;
    }
}

double random_cauchy(random_t *gen, double a, double b, int* err) {
    try {
        double result = gen->cauchy(a, b);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

double random_chi_squared(random_t *gen, double n, int* err) {
    try {
        double result = gen->chi_squared(n);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

double random_exponential(random_t *gen, double lambda, int* err) {
    try {
        double result = gen->exponential(lambda);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

double random_extreme_value(random_t *gen, double a, double b, int* err) {
    try {
        double result = gen->extreme_value(a, b);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

double random_fisher_f(random_t *gen, double m, double n, int* err) {
    try {
        double result = gen->fisher_f(m, n);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

double random_gamma(random_t *gen, double alpha, double beta, int* err) {
    try {
        double result = gen->gamma(alpha, beta);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

int random_geometric(random_t *gen, double p, int* err) {
    try {
        int result = gen->geometric(p);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0;
    }
}

double random_lognormal(random_t *gen, double m, double s, int* err) {
    try {
        double result = gen->lognormal(m, s);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

int random_negative_binomial(random_t *gen, int k, double p, int* err) {
    try {
        int result = gen->negative_binomial(k, p);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0;
    }
}

double random_normal(random_t *gen, double mean, double stddev, int* err) {
    try {
        double result = gen->normal(mean, stddev);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

int random_poisson(random_t *gen, double mean, int* err) {
    try {
        int result = gen->poisson(mean);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0;
    }
}

double random_student_t(random_t *gen, double n, int* err) {
    try {
        double result = gen->student_t(n);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

int random_uniform_int(random_t *gen, int a, int b, int* err) {
    try {
        int result = gen->uniform_int(a, b);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0;
    }
}

double random_uniform_real(random_t *gen, double a, double b, int* err) {
    try {
        double result = gen->uniform_real(a, b);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

double random_weibull(random_t *gen, double a, double b, int* err) {
    try {
        double result = gen->weibull(a, b);
        if (err) *err = 0;
        return result;
    } catch (const std::invalid_argument &e) {
        if (err) *err = 1;
        return 0.0;
    }
}

void random_shuffle(random_t* gen, int* arr, int n) {
    gen->shuffle(arr, n);
}

void random_sample(random_t* gen, int n, int r, int* results) {
    gen->sample(n, r, results);
}

void random_shuffle_long(random_t* gen, long* arr, long n) {
    gen->shuffle(arr, n);
}

void random_sample_long(random_t* gen, long n, long r, long* results) {
    gen->sample(n, r, results);
}
