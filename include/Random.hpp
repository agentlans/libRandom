#ifndef _RANDOMCLASS
#define _RANDOMCLASS

#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Random {
public:
  Random();
  Random(unsigned int s);
  void seed();               // initializes generator with random seed
  void seed(unsigned int s); // initializes generator with given seed

  bool bernoulli(double p);
  int binomial(int t, double p);
  double cauchy(double a, double b);
  double chi_squared(double n);
  double exponential(double lambda);
  double extreme_value(double a, double b);
  double fisher_f(double m, double n);
  double gamma(double alpha, double beta);
  int geometric(double p);
  double lognormal(double m, double s);
  int negative_binomial(int k, double p);
  double normal(double mean, double stddev);
  int poisson(double mean);
  double student_t(double n);
  int uniform_int(int a, int b);
  double uniform_real(double a, double b);
  double weibull(double a, double b);

  // Randomly permute the elements in the range
  template <class Iterator>
  void shuffle(Iterator first, Iterator last);
  template <class T>
  void shuffle(T* arr, size_t n);

  // Select r integers from [0,n) without replacement
  template <class Integer>
  void sample(Integer n, Integer r, std::vector<Integer>& results);
  template <class Integer>
  void sample(Integer n, Integer r, Integer* results);
private:
  std::default_random_engine generator;
};

// Implementations of the templated methods

template <class Iterator>
void Random::shuffle(Iterator first, Iterator last) {
	std::shuffle(first, last, generator);
}

template <class T>
void Random::shuffle(T* arr, size_t n) {
	std::shuffle(arr, arr+n, generator);
}

template <class Integer>
void Random::sample(Integer n, Integer r, std::vector<Integer>& results) {
	results.resize(r);
	sample(n, r, results.data());
}

template <class Integer>
void Random::sample(Integer n, Integer r, Integer* results) {
	if (r*(r+1)/2.0 < n) {
		// Sparse sampling
		std::unordered_set<Integer> s;
		while (s.size() < r) {
			Integer x = uniform_int(0, n-1);
			if (s.count(x) == 0) {
				s.insert(x);
			}
		}
		std::copy(s.begin(), s.end(), results);
	} else {
		// Dense sampling
		Integer numer = r;
		Integer denom = n;
		Integer i = 0;
		Integer k = 0;
		while (numer > 0) {
			bool x = bernoulli(float(numer)/denom);
			if (x) {
				results[i++] = k;
				numer--;
			}
			denom--;
			k++;
		}
		shuffle(results, results+r);
	}
}

#endif
