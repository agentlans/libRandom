#include <iostream>
#include <vector>
#include "Random.hpp"

// g++ Example.cpp -I../include -L../build -lRandomLib_shared
// LD_LIBRARY_PATH=../build ./a.out

int main() {
    // Create a Random object
    Random rng;

    // Seed the random number generator
    rng.seed();

    // Demonstrate various distribution functions
    std::cout << "Bernoulli(0.7): " << rng.bernoulli(0.7) << std::endl;
    std::cout << "Binomial(10, 0.5): " << rng.binomial(10, 0.5) << std::endl;
    std::cout << "Normal(0, 1): " << rng.normal(0, 1) << std::endl;
    std::cout << "Uniform Int(1, 10): " << rng.uniform_int(1, 10) << std::endl;
    std::cout << "Uniform Real(0, 1): " << rng.uniform_real(0, 1) << std::endl;

    // Demonstrate shuffle
    std::vector<int> vec = {1, 2, 3, 4, 5};
    rng.shuffle(vec.begin(), vec.end());
    std::cout << "Shuffled vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Demonstrate sample
    std::vector<int> sample_results;
    rng.sample(10, 5, sample_results);
    std::cout << "Sample 5 from 10: ";
    for (int num : sample_results) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
