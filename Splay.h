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
 

#ifndef SPLAY_H
#define SPLAY_H


class SplayTree {


    void zig(Node*);
    void zig_zig(Node*);
    void zig_zag(Node*);


    void splay(Node*);


 
    public:
        
    	int count = 0;

        Node *root;

        SplayTree();

        ~SplayTree();
     
        SplayTree(int);

        void insert(int);

        void display();

        void display(Node*);

        void traversalCount();

        Node* search(int);

        Node* minLeaf(Node*);

        Node* maxLeaf(Node*);

        Node* remove(int);

        void deleteTree(Node*);

   
};

#endif