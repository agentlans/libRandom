#include <iostream>
#include <stdexcept>

#include "RandomC.h"

random_t *random_new() { return new Random(); }
random_t *random_new_seeded(unsigned int seed) { return new Random(seed); }

void random_reseed(random_t *gen, unsigned int seed) { gen->seed(seed); }

void random_free(random_t *gen) { delete reinterpret_cast<Random *>(gen); }

int random_binomial(random_t *gen, int t, double p) {
  try {
    return gen->binomial(t, p);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0;
  }
}

double random_cauchy(random_t *gen, double a, double b) {
  try {
    return gen->cauchy(a, b);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

double random_chi_squared(random_t *gen, double n) {
  try {
    return gen->chi_squared(n);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

double random_exponential(random_t *gen, double lambda) {
  try {
    return gen->exponential(lambda);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

double random_extreme_value(random_t *gen, double a, double b) {
  try {
    return gen->extreme_value(a, b);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

double random_fisher_f(random_t *gen, double m, double n) {
  try {
    return gen->fisher_f(m, n);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

double random_gamma(random_t *gen, double alpha, double beta) {
  try {
    return gen->gamma(alpha, beta);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

int random_geometric(random_t *gen, double p) {
  try {
    return gen->geometric(p);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0;
  }
}

double random_lognormal(random_t *gen, double m, double s) {
  try {
    return gen->lognormal(m, s);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

int random_negative_binomial(random_t *gen, int k, double p) {
  try {
    return gen->negative_binomial(k, p);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0;
  }
}

double random_normal(random_t *gen, double mean, double stddev) {
  try {
    return gen->normal(mean, stddev);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

int random_poisson(random_t *gen, double mean) {
  try {
    return gen->poisson(mean);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0;
  }
}

double random_student_t(random_t *gen, double n) {
  try {
    return gen->student_t(n);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

int random_uniform_int(random_t *gen, int a, int b) {
  try {
    return gen->uniform_int(a, b);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0;
  }
}

double random_uniform_real(random_t *gen, double a, double b) {
  try {
    return gen->uniform_real(a, b);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

double random_weibull(random_t *gen, double a, double b) {
  try {
    return gen->weibull(a, b);
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 0.0;
  }
}

// Shuffles a list of n integers
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
