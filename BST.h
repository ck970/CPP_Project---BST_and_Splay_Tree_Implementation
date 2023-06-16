#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>
#include <chrono>
#include <math.h>

using namespace std;
using std::istream;
using namespace std::chrono;

#include "Node.h"
 

#ifndef BST_H
#define BST_H



class BST {


 
public:

	int count = 0;
    // traversal count tracker

    Node *root;

    BST();

    ~BST();
 
    BST(int);

    Node* insert(Node*, int);

    void display();

    void display(Node*);

    void traversalCount();

    void search(int);

    Node* minLeaf(Node*);

    Node* maxLeaf(Node*);

    Node* remove(Node*, int);

    void deleteTree(Node*);

};

#endif