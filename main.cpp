#include <iostream>
#include "generate_primes.h"
#include "Sekvensiell_seartch.h"
#include "Binarysearch.h"
#include "Binary_seartch_tree.h"
#include "Hash_table.h"
void sekvensiell_seartch_test(std::vector<int>&prime_vector, int target);
void binary_seartch_test(std::vector<int>&prime_vector, int target);
void BST_test(Node*root,int target);
void free_mem(std::vector<node*> hashtable,size_t reserved_size);
int main() {
    int size_of_vec=100;
    std::vector<bool>vec(size_of_vec, true);
    for (int i = 0; i < vec.size(); i++) {
        vec[i]=true;
        std::cout<< vec[i];
    }
    std::cout<<"\n\n";
    auto prime_vector=prime_num(vec);

    for (int i = 0; i < vec.size(); ++i) {
        std::cout<< vec[i];
    }
    std::cout<<"\n\n";

    for (int i = 0; i < prime_vector.size(); ++i) {
        std::cout<< prime_vector[i]<<", ";
    }


/*
    int target=89;
    sekvensiell_seartch_test(prime_vector,target);
*/

/*
    int target = 20;
    binary_seartch_test(prime_vector, target);
*/

/*
    int target=97;
    Node* root=creat_BST(prime_vector);
    BST_test(root,target);
*/


std::cout<<"\n\nHash table:\n\n";
    size_t reserved_size = 100;
    std::vector<node*> hashtable(reserved_size, nullptr);
    insertSortedVector(prime_vector, hashtable, reserved_size);

    int searchKey = 71;

    bool found = search(hashtable, searchKey, reserved_size);
    if (found) {
        std::cout << "Element " << searchKey << " found in the hash table." << std::endl;
    } else {
        std::cout << "Element " << searchKey << " not found in the hash table." << std::endl;
    }
    //display(hashtable, reserved_size);
    free_mem(hashtable,reserved_size);
    return 0;
}

void sekvensiell_seartch_test(std::vector<int>&prime_vector, int target){

    int index = bianary_search(prime_vector, target);
    if (index != -1) {
        std::cout << "\n\nTarget element " << target << " found at index " << index <<"\n\n";
    } else {
        std::cout << "\n\nTarget element " << target << " not found in the array." <<"\n\n";
    }
}
void binary_seartch_test(std::vector<int>&prime_vector, int target){

    int index = bianary_search(prime_vector, target);
    if (index != -1) {
        std::cout << "\n\nTarget element " << target << " found at index " << index <<"\n\n";
    } else {
        std::cout << "\n\nTarget element " << target << " not found in the array." <<"\n\n";
    }
}
void BST_test(Node*root,int target){
    Node* index=seartch_BST(root,target);
    if (index != nullptr) {
        std::cout << "\n\nElement " << target << " found in the binary search tree.\n\n" << std::endl;
    } else {
        std::cout << "\n\nElement " << target << " not found in the binary search tree.\n\n" << std::endl;
    }
}

void free_mem(std::vector<node*> hashtable,size_t reserved_size){
    for (size_t i = 0; i < reserved_size; i++) {
        node* curr = hashtable[i];
        while (curr != nullptr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}