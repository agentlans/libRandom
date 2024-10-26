#include "Random.hpp"
#include "RandomC.h"

#include <iostream>

// g++ Example.c -I../include -L../build -lRandomLib_shared
// LD_LIBRARY_PATH=../build ./a.out

int main() {
  Random r;
  std::cout << r.uniform_real(0, 1) << std::endl;

  random_t *ran = random_new_seeded(1234);
  std::cout << random_uniform_real(ran, 0, 1) << std::endl;
  random_free(ran);

  std::vector<int> foo;
  r.sample(3, 3, foo);
  for (int i = 0; i < 3; ++i) {
    std::cout << "This is " << i << " " << foo[i] << std::endl;
  }
}
