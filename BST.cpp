//
//  BST.cpp
//  Data Structures
//
//  Created by Danny Gletner on 2/9/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//
#include "BST.h"

/*
 * Driver for insert.
 * Encapsulates root.
 */
void BST::insert(const int &item){
    insert(item, root);
}

/*
 * Inserts an item into the tree.
 * item is the object of the Node to be inserted
 * current is the current Node being accessed to compare values for good placement*/
void BST::insert(const int &item, Node* &current){
    if(current == NULL){
        current = new Node{item, NULL, NULL};
    }
    else if(item < current->object){
        count++;
        insert(item, current->left);
    }
    else if(item > current->object){
        count++;
        insert(item, current->right);
    }
}

/*
 * Driver for remove.
 * Encapsulates root.
 */
void BST::remove(const int &item){
    remove(item, root);
}

/*
 * Removes a Node from the tree.
 * item is the object of the Node to be removed
 * current is the current Node being searched for the target
 */
void BST::remove(const int &item, Node* &current){
    if(current == NULL) return;
    else if(item > current->object){
        count++;
        remove(item, current->right);
    }
    else if(item < current->object){
        count++;
        remove(item, current->left);
    }
    else if(current->left != NULL && current->right != NULL){
        count++;
        current->object = findMin(current->right)->object;
        remove(current->object, current->right);
    }
    else{
        count++;
        Node* oldNode = current;
        current = (current->left != NULL) ? current->left : current->right;
        delete oldNode;
    }
}

/*
 * Driver for findMax
 * Encapsulates root.
 */
void BST::findMax(){
   findMax(root);
}

/*
 * Finds the Node with the maximum value in the tree from a designated Node.
 * current is the Node to begin searching from
 */
Node* BST::findMax(Node* current) const{
    if(current != NULL){
        while(current->right != NULL)
            current = current->right;
    }
    return current;
}

/*
 * Driver for findMin.
 * Encapsulates root.
 */
void BST::findMin(){
    findMin(root);
}

/*
 * Finds the Node with the smallest value in the tree from a designated Node
 * current is the Node to begin searching from
 */
Node* BST::findMin(Node* current) const{
    if(current == NULL)
        return NULL;
    if(current->left == NULL)
        return current;
    return findMin(current->left); 
}

/*
 * Driver for search.
 * Ecapsulates root.
 */
bool BST::search(const int &item){
    return search(item, root);
}

/*
 * Searches for a target Node in the tree.
 * item is the object of the Node to be found
 * current is the current Node being searched
 */
bool BST::search(const int &item, Node* &current){
    if(current == NULL) return false;
    else if(item > current->object){
        count++;
        return search(item, current->right);
    }
    else if(item < current->object){
        count++;
        return search(item, current->left);
    }
    else return true;
}

/*
 * Driver for printInternal
 * Encapsulates root.
 */
void BST::printInternal(){
    printInternal(root);
}

/*
 * Prints the contents of the tree.
 * root is the root of the tree
 */
void BST::printInternal(Node* root){
    cout << "[" << root->object;
    if(root->left != NULL || root->right != NULL){
       if(root->left != NULL)
            printInternal(root->left);
        if(root->right != NULL)
            printInternal(root->right);
    }
    cout << "]";
}
