//
// Created by Johannes Joujo on 2023-06-06.
//
#include "Sekvensiell_seartch.h"

int sekvensiell_seartch(std::vector<int>&vec, int target){
    for(int i=0;i<vec.size();i++){
        if(vec[i]==target){
            return i;
        }
    }
    return -1;
}
