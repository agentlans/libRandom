#include "Random.hpp"

#include <chrono>
#include <stdexcept>

// Optional: generate seeds using BSD's generator
#ifdef BSD_HEADERS
extern "C" {
#include <bsd/stdlib.h> // Need to install libbsd-dev on Ubuntu
}
#endif

// Returns a seed for the random number generator
unsigned int get_seed() {
#ifdef BSD_HEADERS
  return arc4random();
#else
  // Use the system time as a seed
  return std::chrono::system_clock::now().time_since_epoch().count();
#endif
}

void Random::seed() { seed(get_seed()); }

void Random::seed(unsigned int s) { generator.seed(s); }

Random::Random() { seed(); }

Random::Random(unsigned int s) { seed(s); }

/**
 * @brief Generates a random variate from a Bernoulli distribution.
 *
 * This function generates a random boolean value from a Bernoulli distribution
 * with the specified probability of success.
 *
 * @param p The probability of returning true. Must be in the range [0, 1].
 *
 * @return A random variate from the Bernoulli distribution (true or false).
 *
 * @throws std::invalid_argument If p is not in the range [0, 1].
 */
bool Random::bernoulli(double p) {
  if (p < 0 || p > 1)
    throw std::invalid_argument("Probability must be in the range [0, 1]");
  std::bernoulli_distribution d(p);
  return d(generator);
}

/**
 * @brief Generates a random variate from a binomial distribution.
 *
 * This function generates a random integer from a binomial distribution
 * with the specified number of trials and probability of success.
 *
 * @param t The number of trials (upper bound of possible values).
 * @param p The probability of success for each trial. Must be in the range [0,
 * 1].
 *
 * @return A random variate from the binomial distribution.
 *
 * @throws std::invalid_argument If p is not in the range [0, 1].
 */
int Random::binomial(int t, double p) {
  if (p < 0 || p > 1)
    throw std::invalid_argument("Probability must be in the range [0, 1]");
  std::binomial_distribution<int> d(t, p);
  return d(generator);
}

/**
 * @brief Generates a random variate from a Cauchy distribution.
 *
 * This function generates a random number from a Cauchy distribution
 * with the specified location and scale parameters.
 *
 * @param a The location of the peak of the distribution.
 * @param b The scale of the distribution. Must be positive (b > 0).
 *
 * @return A random variate from the Cauchy distribution.
 *
 * @throws std::invalid_argument If b <= 0.
 */
double Random::cauchy(double a, double b) {
  if (b <= 0)
    throw std::invalid_argument("Scale parameter must be positive");
  std::cauchy_distribution<double> d(a, b);
  return d(generator);
}

/**
 * @brief Generates a random variate from a chi-squared distribution.
 *
 * This function generates a random number from a chi-squared distribution
 * with the specified number of degrees of freedom.
 *
 * @param n The number of degrees of freedom. Must be positive (n > 0).
 *
 * @return A random variate from the chi-squared distribution.
 *
 * @throws std::invalid_argument If n <= 0.
 */
double Random::chi_squared(double n) {
  if (n <= 0)
    throw std::invalid_argument("Degrees of freedom must be positive");
  std::chi_squared_distribution<double> d(n);
  return d(generator);
}

/**
 * @brief Generates a random variate from an exponential distribution.
 *
 * This function generates a random number from an exponential distribution
 * with the specified rate parameter.
 *
 * @param lambda The average rate of occurrence. Must be positive (lambda > 0).
 *
 * @return A random variate from the exponential distribution.
 *
 * @throws std::invalid_argument If lambda <= 0.
 */
double Random::exponential(double lambda) {
  if (lambda <= 0)
    throw std::invalid_argument("Rate parameter must be positive");
  std::exponential_distribution<double> d(lambda);
  return d(generator);
}

/**
 * @brief Generates a random variate from an extreme value distribution.
 *
 * This function generates a random number from an extreme value distribution
 * with the specified location and scale parameters.
 *
 * @param a The location parameter of the distribution.
 * @param b The scale parameter of the distribution. Must be positive (b > 0).
 *
 * @return A random variate from the extreme value distribution.
 *
 * @throws std::invalid_argument If b <= 0.
 */
double Random::extreme_value(double a, double b) {
  if (b <= 0)
    throw std::invalid_argument("Scale parameter must be positive");
  std::extreme_value_distribution<double> d(a, b);
  return d(generator);
}

/**
 * @brief Generates a random variate from a Fisher-F distribution.
 *
 * This function generates a random number from a Fisher-F distribution
 * with the specified degrees of freedom for numerator and denominator.
 *
 * @param m The numerator's degrees of freedom. Must be positive (m > 0).
 * @param n The denominator's degrees of freedom. Must be positive (n > 0).
 *
 * @return A random variate from the Fisher-F distribution.
 *
 * @throws std::invalid_argument If m <= 0 or n <= 0.
 */
double Random::fisher_f(double m, double n) {
  if (m <= 0 || n <= 0)
    throw std::invalid_argument("Degrees of freedom must be positive");
  std::fisher_f_distribution<double> d(m, n);
  return d(generator);
}

/**
 * @brief Generates a random variate from a gamma distribution.
 *
 * This function generates a random number from a gamma distribution
 * with the specified shape and scale parameters.
 *
 * @param alpha The shape parameter of the distribution. Must be positive (alpha
 * > 0).
 * @param beta The scale parameter of the distribution. Must be positive (beta >
 * 0).
 *
 * @return A random variate from the gamma distribution.
 *
 * @throws std::invalid_argument If alpha <= 0 or beta <= 0.
 */
double Random::gamma(double alpha, double beta) {
  if (alpha <= 0 || beta <= 0)
    throw std::invalid_argument("Shape and scale parameters must be positive");
  std::gamma_distribution<double> d(alpha, beta);
  return d(generator);
}

/**
 * @brief Generates a random variate from a geometric distribution.
 *
 * This function generates a random integer from a geometric distribution
 * with the specified probability of success.
 *
 * @param p The probability of success. Must be in the range (0, 1].
 *
 * @return A random variate from the geometric distribution.
 *
 * @throws std::invalid_argument If p <= 0 or p > 1.
 */
int Random::geometric(double p) {
  if (p <= 0 || p > 1)
    throw std::invalid_argument("Probability must be in the range (0, 1]");
  std::geometric_distribution<int> d(p);
  return d(generator);
}

/**
 * @brief Generates a random variate from a lognormal distribution.
 *
 * This function generates a random number from a lognormal distribution
 * with the specified mean and standard deviation of the underlying
 * normal distribution.
 *
 * @param m The mean of the underlying normal distribution.
 * @param s The standard deviation of the underlying normal distribution.
 *          Must satisfy the condition: s > 0.
 *
 * @return A random variate from the lognormal distribution.
 *
 * @throws std::invalid_argument If s <= 0.
 */
double Random::lognormal(double m, double s) {
  if (s <= 0)
    throw std::invalid_argument("Standard deviation must be positive");
  std::lognormal_distribution<double> d(m, s);
  return d(generator);
}

/**
 * @brief Generates a random variate from a negative binomial distribution.
 *
 * This function generates a random integer from a negative binomial
 * distribution with the specified number of unsuccessful trials and probability
 * of success.
 *
 * @param k The number of unsuccessful trials that stops the count.
 * @param p The probability of success. Must satisfy the condition: 0 <= p <= 1.
 *
 * @return A random variate from the negative binomial distribution.
 *
 * @throws std::invalid_argument If p < 0 or p > 1.
 */
int Random::negative_binomial(int k, double p) {
  if (p < 0 || p > 1)
    throw std::invalid_argument("Probability must be between 0 and 1");
  std::negative_binomial_distribution<int> d(k, p);
  return d(generator);
}

/**
 * @brief Generates a random variate from a normal distribution.
 *
 * This function generates a random number from a normal distribution
 * with the specified mean and standard deviation.
 *
 * @param mean The mean of the distribution (expected value).
 * @param stddev The standard deviation of the distribution. Must satisfy the
 * condition: stddev > 0.
 *
 * @return A random variate from the normal distribution.
 *
 * @throws std::invalid_argument If stddev <= 0.
 */
double Random::normal(double mean, double stddev) {
  if (stddev <= 0)
    throw std::invalid_argument("Standard deviation must be positive");
  std::normal_distribution<double> d(mean, stddev);
  return d(generator);
}

/**
 * @brief Generates a random variate from a Poisson distribution.
 *
 * This function generates a random integer from a Poisson distribution
 * with the specified mean.
 *
 * @param mean The expected number of events in the interval. Must satisfy the
 * condition: mean > 0.
 *
 * @return A random variate from the Poisson distribution.
 *
 * @throws std::invalid_argument If mean <= 0.
 */
int Random::poisson(double mean) {
  if (mean <= 0)
    throw std::invalid_argument("Mean must be positive");
  std::poisson_distribution<int> d(mean);
  return d(generator);
}

/**
 * @brief Generates a random variate from a Student's t-distribution.
 *
 * This function generates a random number from a Student's t-distribution
 * with the specified degrees of freedom.
 *
 * @param n The degrees of freedom. Must satisfy the condition: n > 0.
 *
 * @return A random variate from the Student's t-distribution.
 *
 * @throws std::invalid_argument If n <= 0.
 */
double Random::student_t(double n) {
  if (n <= 0)
    throw std::invalid_argument("Degrees of freedom must be positive");
  std::student_t_distribution<double> d(n);
  return d(generator);
}

/**
 * @brief Generates a random variate from a uniform integer distribution.
 *
 * This function generates a random integer from a uniform distribution
 * in the range [a, b], where both a and b are inclusive.
 *
 * @param a The lower bound of the range the distribution can generate
 * (inclusive).
 * @param b The upper bound of the range the distribution can generate
 * (inclusive). Must satisfy the condition: a < b.
 *
 * @return A random variate from the uniform integer distribution in the range
 * [a, b].
 *
 * @throws std::invalid_argument If a >= b.
 */
int Random::uniform_int(int a, int b) {
  if (a >= b)
    throw std::invalid_argument("Lower bound must be less than upper bound");
  std::uniform_int_distribution<int> d(a, b);
  return d(generator);
}

/**
 * @brief Generates a random variate from a uniform real distribution.
 *
 * This function generates a random real number from a uniform distribution
 * in the range [a, b), where a is inclusive and b is exclusive.
 *
 * @param a The lower bound of the range the distribution can generate
 * (inclusive).
 * @param b The upper bound of the range the distribution can generate
 * (exclusive). Must satisfy the condition: a <= b.
 *
 * @return A random variate from the uniform real distribution in the range [a,
 * b).
 *
 * @throws std::invalid_argument If a > b.
 */
double Random::uniform_real(double a, double b) {
  if (a > b)
    throw std::invalid_argument(
        "Lower bound must be less than or equal to upper bound");
  std::uniform_real_distribution<double> d(a, b);
  return d(generator);
}

/**
 * @brief Generates a random variate from a Weibull distribution.
 *
 * This function generates a random number from a Weibull distribution
 * with the specified shape and scale parameters.
 *
 * @param a The shape of the distribution. Must satisfy the condition: a > 0.
 * @param b The scale of the distribution. Must satisfy the condition: b > 0.
 *
 * @return A random variate from the Weibull distribution.
 *
 * @throws std::invalid_argument If a <= 0 or b <= 0.
 */
double Random::weibull(double a, double b) {
  if (a <= 0 || b <= 0)
    throw std::invalid_argument("Shape and scale parameters must be positive");
  std::weibull_distribution<double> d(a, b);
  return d(generator);
}
