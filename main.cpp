//
//  main.cpp
//  Data Structures
//
//  Created by Danny Gletner on 2/12/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#include "main.h"

/*
 * Main function. Takes in a file of data, adds it to a BST and Splay Tree respectively.
 * Performs a series of operations on the data and compares runtime and total comparisons of each.
 */
int main(int argc, const char * argv[]){
    ifstream inFile;
    string filename = argv[1];
    string foo = "";
    int item = 0;
    int insertSize = 0;
    int searchSize = 0;
    int removeSize = 0;
    BST bst;
    Splay splay;
    
    inFile.open(filename.c_str());
    if(!inFile){
        cout << "ERROR: File open unsuccessful" << endl;
        exit(EXIT_FAILURE);
    }
    
    while(inFile >> foo){
        if(foo == "$") break;
        insertSize++;
    }
    while(inFile >> foo){
        if(foo == "$") break;
        searchSize++;
    }
    while(inFile >> foo){
        if(inFile.bad()) break;
        removeSize++;
    }
    inFile.close();
    
    inFile.open(filename.c_str());
    if(!inFile){
        cout << "ERROR: File open unsuccessful" << endl;
        exit(EXIT_FAILURE);
    }
    
    /*BST Operations*/
    auto startBST = chrono::high_resolution_clock().now();
    for(int i = 0; i < insertSize; i++){
        inFile >> item;
        bst.insert(item);
    }
    inFile >> foo;
    
    cout << "BST Initial Tree Structure: ";
    bst.printInternal(); cout << endl;
    
    for(int i = 0; i < searchSize; i++){
        inFile >> item;
        bst.search(item);
    }
    inFile >> foo;
    
    for(int i = 0; i < removeSize; i++){
        inFile >> item;
        bst.remove(item);
    }
    auto finishBST = chrono::high_resolution_clock().now();
    double runtimeBST = chrono::duration_cast<std::chrono::nanoseconds>(finishBST-startBST).count();
    inFile.close();
    
    cout << "BST Final Tree Structure: ";
    bst.printInternal(); cout << endl;
    cout << "---------------------" << endl;
    cout << "Operations finished in " << fixed << setprecision(2) << runtimeBST << " nanoseconds." << endl;
    cout << "Traversal Count for all operations: " << bst.getCount() << endl << endl;
    
    /********* END BST **********/
    
    inFile.open(filename.c_str());
    if(!inFile){
        cout << "ERROR: File open unsuccessful" << endl;
        exit(EXIT_FAILURE);
    }
    
    /*Splay Operations*/
    auto startSplay = chrono::high_resolution_clock().now();
    for(int i = 0; i < insertSize; i++){
        inFile >> item;
        splay.insert(item);
    }
    inFile >> foo;
    
    cout << "Splay Initial Tree Structure: ";
    splay.printInternal(); cout << endl;
    
    for(int i = 0; i < searchSize; i++){
        inFile >> item;
        splay.search(item);
    }
    inFile >> foo;
    
    for(int i = 0; i < removeSize; i++){
        inFile >> item;
        splay.remove(item);
    }
    auto finishSplay = chrono::high_resolution_clock().now();
    double runtimeSplay = chrono::duration_cast<std::chrono::nanoseconds>(finishSplay-startSplay).count();
    
    cout << "Splay Final Tree Structure: ";
    splay.printInternal(); cout << endl;
    cout << "---------------------" << endl;
    cout << "Operations finished in " << fixed << setprecision(2) << runtimeSplay << " nanoseconds." << endl;
    cout << "Traversal Count for all operations: " << splay.getCount() << endl << endl;
    
    if(runtimeBST > runtimeSplay)
        cout << "Splay was faster by " << runtimeBST - runtimeSplay << " nanoseconds!" << endl;
    else
        cout << "BST was faster by " << runtimeSplay - runtimeBST << " nanoseconds!" << endl;
    
    if(bst.getCount() > splay.getCount())
        cout << "Splay took " << bst.getCount() - splay.getCount() << " less traversals!" << endl;
    else
        cout << "BST took " << splay.getCount() - bst.getCount() << " less traversals!" << endl;
    cout << endl;
}
