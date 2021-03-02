//
//  Splay.cpp
//  project2
//
//  Created by Danny Gletner on 2/24/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#include "Splay.h"

/*
 * A function to splay a Node to the position of a Node designated as the root.
 * root is the Node in the position to be splayed to
 * item is the object of the node to be splayed
 */
Node* Splay::splay(Node* &root, const int &item){
    /* object found at root */
    if(root == NULL || root->object == item) return root;
    
    /*Item will be in left subtree*/
    if(root->object > item){
        if(root->left == NULL) return root; //item not in tree
        
        /*Left Zig Zig required (left, left)*/
        if(root->left->object > item){
            /*Continue searching from this "root"*/
            if(root->left->left == NULL) return root;
            
            root->left->left = splay(root->left->left, item);
            
            /*Zig (on parent)*/
            root = zigLeft(root);
        }
        /*Zig Zag required (left, right)*/
        else if(root->left->object < item){
            /*Recursively marks this spot, continue searching from this "root"*/
            root->left->right = splay(root->left->right, item);
            
            /*Zag*/
            if(root->left->right != NULL)
                root->left = zigRight(root->left);
        }
        /*Zig*/
        return root = zigLeft(root);
    }
    /*Item will be in right subtree*/
    else {
        if(root->right == NULL) return root; //item not in tree
        
        /*Zag Zig from here (right, left)*/
        if(root->right->object > item){
            /*Continue searching from this "root"*/
            root->right->left = splay(root->right->left, item);
            
            /*Zig*/
            if(root->right->left != NULL)
                root->right = zigLeft(root->right);
        }
        /*Zag Zag from here (right, right)*/
        else if(root->right->object < item){
            if(root->right->right == NULL) return root;
            
            root->right->right = splay(root->right->right, item);
            /*Zag (on parent)*/
            root = zigRight(root);
        }
        /*Zag*/
        return root = zigRight(root);
    }
}

/*
 * Performs one "Zig" operation on the left child of a parent Node.
 * parent is the parent of the target Node
 */
Node* Splay::zigLeft(Node* &parent){
    Node* target = parent->left;
    parent->left = target->right;
    target->right = parent;
    count++;
    return target;
}

/*
 * Performs one "Zag" operation on the right child of a parent Node
 * parent is the parent of the target Node
 */
Node* Splay::zigRight(Node* &parent){
    Node* target = parent->right;
    parent->right = target->left;
    target->left = parent;
    count++;
    return target;
}

/*
 * Driver function for search.
 * Hides access to root of tree.
 */
bool Splay::search(const int &item){
    return search(item, root);
}

/*
 * Searches for a Node in the tree and splays it to the root
 * item is the object of the Node to be searched for
 * current is the current Node being searched
 */
bool Splay::search(const int &item, Node *&current){
    if(current == NULL) return false;
    else if(current->object > item)
        search(item, current->left);
    else if(current->object < item)
        return search(item, current->right);
    else
        splay(root, item); return true;
}

/*
 * Driver function for insert.
 * Hides access to root of tree.
 */
void Splay::insert(const int &item){
    insert(item, root);
}

/*
 * Creates a Node and inserts it to the correct part of the tree,
 * then splays the node to the root.
 * item is the object of the Node to be added
 * current is the current Node being checked to determine placement of the new Node
 */
void Splay::insert(const int &item, Node* &current){
    if(current == NULL){
        current = new Node{item, NULL, NULL};
        root = splay(root, item);
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
void Splay::remove(const int &item){
    root = remove(item, root);
}

/*
 * Splays a target Node to the root and removes it from the tree.
 * Find the largest value in the left subtree to become the new root.
 * item is the object of the Node to be removed
 */
Node* Splay::remove(const int &item, Node* &current){
    Node* temp;
    if(root == NULL)
        return NULL;
    
    root = splay(root, item);
    
    if(item != root->object)
        return root;
    
    if(root->left == NULL){
        temp = root;
        root = root->right;
    }
    else{
        temp = root;
        
        //gets maximum node in left tree and splays to root
        root = splay(root->left, findMax(root->left)->object);
        root->right = temp->right;
    }
    delete temp;
    return root;
    
}

/*
 * Finds the maximum value object in the tree from a designated Node.
 * current is the Node to start searching from
 */
Node* Splay::findMax(Node* current) const{
    if(current != NULL){
        while(current->right != NULL)
            current = current->right;
    }
    return current;
}

/*
 * Driver for printInternal.
 * Hides access to root of tree.
 */
void Splay::printInternal(){
    printInternal(root);
}

/*
 * Prints out the contents of the tree.
 */
void Splay::printInternal(Node* root){
    cout << "[" << root->object;
    if(root->left != NULL || root->right != NULL){
        if(root->left != NULL)
            printInternal(root->left);
        if(root->right != NULL)
            printInternal(root->right);
    }
    cout << "]";
}
