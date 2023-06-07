//
// Created by Johannes Joujo on 2023-06-07.
//

#ifndef SEARTCH_HASH_TABLE_H
#define SEARTCH_HASH_TABLE_H

#include <iostream>
#include <vector>
#include <memory>

struct node{
    int data;
    node *next;
};

size_t hash(int key, size_t size);
void insert(std::vector<node*>& hashtable, int data, size_t size);
bool search(const std::vector<node*>& hashtable, int data, size_t size);
void insertSortedVector(std::vector<int>& sortedVector, std::vector<node*>& hashtable, size_t size);
#endif //SEARTCH_HASH_TABLE_H
