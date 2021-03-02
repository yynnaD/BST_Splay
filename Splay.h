//
//  Splay.hpp
//  project2
//
//  Created by Danny Gletner on 2/24/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#ifndef Splay_h
#define Splay_h

#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

class Splay{
public:
    Splay() {root = NULL; count = 0;}
    bool search(const int &item);
    void insert(const int &item);
    void remove(const int &item);
    void findMax();
    void findMin();
    void printInternal();
    int getCount() {return count;}
private:
    void printInternal(Node* root);
    void insert(const int &item, Node* &current);
    Node* remove(const int &item, Node* &current);
    bool search(const int &item, Node* &current);
    Node* findMax(Node* current) const;
    Node* findMin(Node* current) const;
    Node* splay(Node* &root, const int &item);
    Node* zigLeft(Node* &parent);
    Node* zigRight(Node* &parent);
   
    Node* root;
    int count;
};

#endif /* Splay_h */
