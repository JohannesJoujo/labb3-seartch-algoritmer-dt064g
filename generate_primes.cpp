//
// Created by Johannes Joujo on 2023-05-24.
//

#include "generate_primes.h"

void siev_of_e(size_t sz,std::vector<bool>&vec){

    vec[0]=false;
    vec[1]=false;
    auto i=2;
    while (i < sz/2){
        auto divisor= i*2;
        while(divisor<sz){
            vec[divisor]= false;
            divisor+=i;
        }
        i++;
        while(vec[i] == false){
            i++;
        }
    }
}

std::vector<int> prime_num(std::vector<bool>&vec){
    std::vector<int> new_vec;
    size_t sz=vec.size();
    siev_of_e(sz,vec);
    for (int i = 0; i <sz; i++) {
        if(vec[i]==true){
            new_vec.push_back(i);
        }
    }
    return new_vec;
}
