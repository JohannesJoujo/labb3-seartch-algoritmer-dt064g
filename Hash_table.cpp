//
// Created by Johannes Joujo on 2023-06-07.
//
#include "Hash_table.h"
size_t hash(int key, size_t size){
    return key % size;
}

void insert(std::vector<node*>& hashtable, int data, size_t size) {
    size_t index = hash(data, size);

    node* newNode = new node();
    newNode->data = data;
    newNode->next = hashtable[index];
    hashtable[index] = newNode;
}

void insertSortedVector(std::vector<int>& sortedVector, std::vector<node*>& hashtable, size_t size) {
    for (int data : sortedVector) {
        insert(hashtable, data, size);
    }
}

bool search(const std::vector<node*>& hashtable, int data, size_t size){
    size_t index= hash(data,size);
    const node* current_node= hashtable[index]; //starting point of searching
    while(current_node!= nullptr){
        if(current_node->data==data){
            return true;
        }
        current_node=current_node->next;
    }
    return false;
}
