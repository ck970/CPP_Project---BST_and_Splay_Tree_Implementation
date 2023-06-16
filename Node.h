#ifndef NODE_H
#define NODE_H



class Node 
{
	public:

		int data; 
	 
		Node *parent;

		Node *grandparent;
	 
		Node *leftChild;
	 
		Node *rightChild;

		Node();

		Node(int data);

		Node(Node*);
	
};



#endif