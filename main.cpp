#include <iostream>
#include "generate_primes.h"

int main() {
    std::vector<bool>vec(100);
    for (int i = 0; i < vec.size(); i++) {
        vec[i]=true;
        std::cout<< vec[i];
    }
    std::cout<<"\n\n";
    auto prime_vector=prime_num(100,vec);

    for (int i = 0; i < vec.size(); ++i) {
        std::cout<< vec[i];
    }
    std::cout<<"\n\n";

    for (int i = 0; i < prime_vector.size(); ++i) {
        std::cout<< prime_vector[i]<<", ";
    }
    return 0;
}
