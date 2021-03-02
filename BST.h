//
//  BST.hpp
//  Data Structures
//
//  Created by Danny Gletner on 2/9/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int object;
    Node* left;
    Node* right;
    
};

class BST{
public:
    BST() {root = nullptr; count = 0;}
    void insert(const int &item);
    void remove(const int &item);
    bool search(const int &item);
    void findMax();
    void findMin();
    void printInternal();
    int getCount() {return count;}
private:
    void insert(const int &item, Node* &current);
    void remove(const int &item, Node* &current);
    bool search(const int &item, Node* &current);
    Node* findMax(Node* current) const;
    Node* findMin(Node* current) const;
    void printInternal(Node* root);
    
    Node* root;
    int count;
    
};



#endif /* BST_hpp */
