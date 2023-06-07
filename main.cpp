#include <iostream>
#include <fstream>
#include "generate_primes.h"
#include "Sekvensiell_seartch.h"
#include "Binarysearch.h"
#include "Binary_seartch_tree.h"
#include "Hash_table.h"
#include "time_calc.h"
#include <random>

void sekvensiell_seartch_test(std::vector<int>&prime_vector, int target);
void binary_seartch_test(std::vector<int>&prime_vector, int target);
void BST_test(Node*root,int target);
void free_mem(std::vector<node*> hashtable,size_t reserved_size);
int generate_random_int(int min, int max);
void resize_vec(std::vector<bool>&, size_t);
void hash_test(const std::vector<node*>& hashtable, int data, size_t size);

int main() {
    int sample=1000;
    int size_of_vec=50000;
    std::vector<double> time_vec(0);
    std::vector<bool>vec(size_of_vec, true);
/*
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

*/

    int choose_option=10;
    while (choose_option >= 5){
        std::cout<<"Your options are:\n";
        std::cout<<"[1] for sekventiell search\n[2] for binary search\n[3] for binary search tree\n[4] for hash table\n ";
        std::cin>>choose_option;
    }

    std::ofstream file("Find.txt", std::ios::app);

    switch (choose_option) {
        double avrage_avikelse;
        double avrage_time;
        int tries;

        case 1:
            tries=size_of_vec;
            file<<"sekventiell_seartch\n\tN\tT[ms]\tStdev[ms]\tSamples\n";
            for(int j=0;j<10;j++){
                resize_vec(vec,tries);
                auto prime_vector=prime_num(vec);
                int size_of_prime=prime_vector.size();

                for(int i=0;i<sample;i++){
                    int target=generate_random_int(0,size_of_prime);
                    auto start = std::chrono::steady_clock::now();
                    sekvensiell_seartch_test(prime_vector,target);
                    auto end = std::chrono::steady_clock::now();
                    time_vec.push_back(std::chrono::duration<double, std::milli>(end - start).count());
                }
                avrage_avikelse= standardavvikelse(time_vec);
                avrage_time= avg(time_vec);
                file<<"a"<<"\t"<<prime_vector.size()<<"\t"<<avrage_time<<"\t"<<avrage_avikelse<<"\t"<<sample<<"\n";
                time_vec.clear();
                //time_vec.resize(size);
                tries=tries + size_of_vec;
            }
            break;
        case 2:
            tries=size_of_vec;
            file<<"binary_seartch\nN\tT[ms]\tStdev[ms]\tSamples\n";
            for(int j=0;j<10;j++){
                resize_vec(vec,tries);
                auto prime_vector=prime_num(vec);
                int size_of_prime=prime_vector.size();

                for(int i=0;i<sample;i++){
                    int target=generate_random_int(0,size_of_prime);
                    auto start = std::chrono::steady_clock::now();
                    binary_seartch_test(prime_vector, target);
                    auto end = std::chrono::steady_clock::now();
                    time_vec.push_back(std::chrono::duration<double, std::milli>(end - start).count());
                }
                avrage_avikelse= standardavvikelse(time_vec);
                avrage_time= avg(time_vec);
                file<<"b"<<"\t"<<prime_vector.size()<<"\t"<<avrage_time<<"\t"<<avrage_avikelse<<"\t"<<sample<<"\n";
                time_vec.clear();
                //time_vec.resize(size);
                tries=tries + size_of_vec;
            }
            break;

        case 3:
            tries=size_of_vec;
            file<<"binary_seartch_tree\nN\tT[ms]\tStdev[ms]\tSamples\n";
            for(int j=0;j<10;j++){
                resize_vec(vec,tries);
                auto prime_vector=prime_num(vec);
                int size_of_prime=prime_vector.size();
                Node* root=creat_BST(prime_vector);

                for(int i=0;i<sample;i++){
                    int target=generate_random_int(0,size_of_prime);

                    auto start = std::chrono::steady_clock::now();
                    BST_test(root,target);
                    auto end = std::chrono::steady_clock::now();
                    time_vec.push_back(std::chrono::duration<double, std::milli>(end - start).count());
                }
                avrage_avikelse= standardavvikelse(time_vec);
                avrage_time= avg(time_vec);
                file<<"c"<<"\t"<<prime_vector.size()<<"\t"<<avrage_time<<"\t"<<avrage_avikelse<<"\t"<<sample<<"\n";
                time_vec.clear();
                //time_vec.resize(size);
                tries=tries + size_of_vec;

            }
            break;

        case 4:
            tries=size_of_vec;
            file<<"hash_table\nN\tT[ms]\tStdev[ms]\tSamples\n";
            for(int j=0;j<10;j++){
                resize_vec(vec,tries);
                auto prime_vector=prime_num(vec);
                int size_of_prime=prime_vector.size();
                size_t reserved_size = 35000;
                std::vector<node*> hashtable(reserved_size, nullptr);
                insertSortedVector(prime_vector, hashtable, reserved_size);

                for(int i=0;i<sample;i++){
                    int target=generate_random_int(0,size_of_prime);
                    auto start = std::chrono::steady_clock::now();
                    hash_test(hashtable, target, reserved_size);
                    auto end = std::chrono::steady_clock::now();
                    time_vec.push_back(std::chrono::duration<double, std::milli>(end - start).count());
                }
                avrage_avikelse= standardavvikelse(time_vec);
                avrage_time= avg(time_vec);
                file<<"d"<<"\t"<<prime_vector.size()<<"\t"<<avrage_time<<"\t"<<avrage_avikelse<<"\t"<<sample<<"\n";
                time_vec.clear();
                //time_vec.resize(size);
                free_mem(hashtable,reserved_size);
                tries=tries + size_of_vec;
            }
            break;
        default:
            std::cout << "Error! The operator is not correct";
            break;
    }
    file.close();

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

/*
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
    */
    return 0;
}

void sekvensiell_seartch_test(std::vector<int>&prime_vector, int target){
    int index = sekvensiell_seartch(prime_vector, target);
    /*
    if (index != -1) {
        std::cout << "\n\nTarget element " << target << " found at index " << index <<"\n\n";
    } else {
        std::cout << "\n\nTarget element " << target << " not found in the array." <<"\n\n";
    }*/
}
void binary_seartch_test(std::vector<int>&prime_vector, int target){
    int index = bianary_search(prime_vector, target);
    /*
    if (index != -1) {
        std::cout << "\n\nTarget element " << target << " found at index " << index <<"\n\n";
    } else {
        std::cout << "\n\nTarget element " << target << " not found in the array." <<"\n\n";
    }*/
}
void BST_test(Node*root,int target){
    Node* index=seartch_BST(root,target);
    /*
    if (index != nullptr) {
        std::cout << "\n\nElement " << target << " found in the binary search tree.\n\n" << std::endl;
    } else {
        std::cout << "\n\nElement " << target << " not found in the binary search tree.\n\n" << std::endl;
    }*/
}

void hash_test(const std::vector<node*>& hashtable, int data, size_t size){
    bool found = search(hashtable, data, size);
    /*
    if (found) {
        std::cout << "Element " << data << " found in the hash table." << std::endl;
    } else {
        std::cout << "Element " << data << " not found in the hash table." << std::endl;
    }*/
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

void resize_vec(std::vector<bool>&vec, size_t size){
    vec.resize(size);
    for (int i = 0; i < vec.size(); i++) {
        vec[i]=true;
    }
}
int generate_random_int(int min, int max) {
    std::random_device rd;  // Obtain a random number from the hardware
    std::mt19937 gen(rd()); // Seed the generator

    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}
