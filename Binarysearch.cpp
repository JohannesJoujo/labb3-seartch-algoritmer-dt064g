//
// Created by Johannes Joujo on 2023-06-06.
//
#include "Binarysearch.h"

int bianary_search(std::vector<int>&vec, int target){
    int left = 0;
    int right = vec.size() - 1;

    while(left<right){
        int mid= left + (right-left)/2;
        if(vec[mid]==target){
            return mid;
        }
        if(vec[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
