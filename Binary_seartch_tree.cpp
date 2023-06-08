//
// Created by Johannes Joujo on 2023-06-06.
//
#include "Binary_seartch_tree.h"


Node* insert(Node *root,int value){
    if(root== nullptr){
        root=new Node();
        root->data=value;
        root->left= nullptr;
        root->right= nullptr;
    }
    else if(value<root->data){
        root->left= insert(root->left,value);
    } else{
        root->right= insert(root->right,value);
    }
    return root;
}

Node* creat_BST(std::vector<int>&vec){
    Node*root= nullptr;
    for(const int &element: vec){
        root=insert(root, element);
    }
    return root;
}

Node* seartch_BST(Node*root,int target){
    if(root== nullptr || root->data==target){
        return root;
    }
    if(target < root->data){
        seartch_BST(root->left,target);
    }
    return seartch_BST(root->right, target);
}

