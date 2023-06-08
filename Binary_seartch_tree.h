//
// Created by Johannes Joujo on 2023-06-06.
//

#ifndef SEARTCH_BINARY_SEARTCH_TREE_H
#define SEARTCH_BINARY_SEARTCH_TREE_H
#include "Node.h"
#include <vector>

Node* insert(Node *root,int value);
Node* creat_BST(std::vector<int>&vec);
Node* seartch_BST(Node*root,int target);
#endif //SEARTCH_BINARY_SEARTCH_TREE_H
