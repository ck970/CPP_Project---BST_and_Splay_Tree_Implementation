#include <ctime>

#include "Node.h"



Node::Node()

{

    data = 0;
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
    grandparent = NULL;

}

Node::Node(int value)
{

    data = value;
    leftChild = rightChild = parent = grandparent = NULL;

}

Node::Node(Node* copyNode)
{

	this->data = copyNode->data;
	this->leftChild = copyNode->leftChild;
	this->rightChild = copyNode->rightChild;
	this->parent = copyNode->parent;
	this->grandparent = copyNode->grandparent;
}