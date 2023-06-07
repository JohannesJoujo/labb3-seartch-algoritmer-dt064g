//
// Created by Johannes Joujo on 2023-06-07.
//

#ifndef SEARTCH_TIME_CALC_H
#define SEARTCH_TIME_CALC_H
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

double avg(std::vector<double>&vec){
    double sum=std::accumulate(vec.begin(), vec.end(),0.0);
    double avg_time=sum/vec.size();
    return avg_time;
}

double standardavvikelse(std::vector<double>&vec){
    auto N=vec.size();
    auto time=avg(vec);
    //std::cout<<"time is: "<<time<<"\n";
    auto time_diff=0.0;
    for(auto e:vec){
        time_diff += pow((e - time),2);
    }
    double lhs=(1.0/(N-1));
    //std::cout<<"avvikelse: "<<sqrt(lhs*time_diff)<<"\n";
    return sqrt(lhs*time_diff)/sqrt(N);
}
#endif //SEARTCH_TIME_CALC_H
