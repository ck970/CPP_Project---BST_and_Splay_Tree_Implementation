#include "Splay.h"


SplayTree::SplayTree()
{   

	root = new Node(0);
}
 
// Parameterized Constructor definition.

SplayTree::SplayTree(int value)
{

	root->data = value;

}


SplayTree::~SplayTree()
{

	deleteTree(root);
}




void SplayTree::deleteTree(Node* passedNode)
{

	if (passedNode == NULL) return; 
  
    /* first delete both subtrees */
    
    deleteTree(passedNode->leftChild); 
    deleteTree(passedNode->rightChild); 
      
    /* then delete the node */
    delete passedNode;
}



void SplayTree::zig(Node* passedNode)
{   

	count++;

	Node *passedParent = passedNode->parent;

	/*

	This function contains conditional statements for which child of the parent node
	the passed node actually is, and performs a temporary node switch similar to 
	the BST delete function but simply rearranges without deletion
	
	*/ 

    if (passedParent->leftChild == passedNode)
    {
        Node *A = passedNode->rightChild;
        
        passedNode->parent = NULL;
        passedNode->rightChild = passedParent;
        
        passedParent->parent = passedNode;
        passedParent->leftChild = A;
        
        if (A != NULL) A->parent = passedParent;
    }

    else
    {
        Node *A = passedNode->leftChild;
        
        passedNode->parent = NULL;
        passedNode->leftChild = passedParent;
        
        passedParent->parent = passedNode;
        passedParent->rightChild = A;
        
        if (A != NULL) A->parent = passedParent;
    }

}

void SplayTree::zig_zig(Node* passedNode)
{   

	count++;


	/*

	This function contains conditional statements for which child of the parent node
	the passed node actually is, as well as which child the parent node is of the grandparent
	and performs a temporary node switch similar to the zig function just with an additional
	node switch
	
	*/ 


	Node *passedParent = passedNode->parent;
    Node *passedGrandParent = passedParent->parent;

    if (passedParent->leftChild == passedNode)
    {
        Node *A = passedNode->rightChild;
        Node *B = passedParent->rightChild;
        
        passedNode->parent = passedGrandParent->parent;
        passedNode->rightChild = passedParent;
        
        passedParent->parent = passedNode;
        passedParent->leftChild = A;
        passedParent->rightChild = passedGrandParent;
        
        passedGrandParent->parent = passedParent;
        passedGrandParent->leftChild = B;
        
        
        if (passedNode->parent != NULL)
        {
            if (passedNode->parent->leftChild == passedGrandParent) passedNode->parent->leftChild = passedNode;

            else passedNode->parent->rightChild = passedNode;
        }
        
        if (A != NULL) A->parent = passedParent;
        
        if (B != NULL) B->parent = passedGrandParent;
    }

    else
    {
        Node *A = passedParent->leftChild;
        Node *B = passedNode->leftChild;
        
        passedNode->parent = passedGrandParent->parent;
        passedNode->leftChild = passedParent;
        
        passedParent->parent = passedNode;
        passedParent->leftChild = passedGrandParent;
        passedParent->rightChild = B;
        
        passedGrandParent->parent = passedParent;
        passedGrandParent->rightChild = A;
        
        if (passedNode->parent != NULL)
        {
            if (passedNode->parent->leftChild == passedGrandParent) passedNode->parent->leftChild = passedNode;
            else passedNode->parent->rightChild = passedNode;
        }
        
        if (A != NULL) A->parent = passedGrandParent;
        
        if (B != NULL) B->parent = passedParent;
    }



}

void SplayTree::zig_zag(Node* passedNode)
{   

	count++;

	/*

	This function contains conditional statements for which child of the parent node
	the passed node actually is, as well as which child the parent node is of the grandparent
	and performs several temporary node switches similar to the zig-zag function but with a
	switch with the opposite grandparent
	
	*/ 

	Node *passedParent = passedNode->parent;
    Node *passedGrandParent = passedParent->parent;

    if (passedParent->rightChild == passedNode)
    {
        Node *A = passedNode->leftChild;
        Node *B = passedNode->rightChild;
        
        passedNode->parent = passedGrandParent->parent;
        passedNode->leftChild = passedParent;
        passedNode->rightChild = passedGrandParent;
        
        passedParent->parent = passedNode;
        passedParent->rightChild = A;
        
        passedGrandParent->parent = passedNode;
        passedGrandParent->leftChild = B;
        
        if (passedNode->parent != NULL)
        {
            if (passedNode->parent->leftChild == passedGrandParent) passedNode->parent->leftChild = passedNode;

            else passedNode->parent->rightChild = passedNode;
        }
        
        if (A != NULL) A->parent = passedParent;
        
        if (B != NULL) B->parent = passedGrandParent;
    }
    else
    {
        Node *A = passedNode->leftChild;
        Node *B = passedNode->rightChild;
        
        passedNode->parent = passedGrandParent->parent;
        passedNode->leftChild = passedGrandParent;
        passedNode->rightChild = passedParent;
        
        passedParent->parent = passedNode;
        passedParent->leftChild = B;
        
        passedGrandParent->parent = passedNode;
        passedGrandParent->rightChild = A;
        
        if (passedNode->parent != NULL)
        {
            if (passedNode->parent->leftChild == passedGrandParent) passedNode->parent->leftChild = passedNode;

            else passedNode->parent->rightChild = passedNode;
        }
        
        if (A != NULL) A->parent = passedGrandParent;
        
        if (B != NULL) B->parent = passedParent;
    }



}

void SplayTree::splay(Node* passedNode)
{   

	//This splay function just figures out which of the three main splay functions need to be executed
	// to get the passed node to the root for any of the primary functions.


	while (passedNode->parent != NULL)
    {

        Node *passedParent = passedNode->parent;
        Node *passedGrandParent = passedParent->parent;

        if (passedGrandParent == NULL) zig(passedNode);

        else if (passedGrandParent->leftChild == passedParent && passedParent->leftChild == passedNode) zig_zig(passedNode);

        else if (passedGrandParent->rightChild == passedParent && passedParent->rightChild == passedNode) zig_zig(passedNode);

        else zig_zag(passedNode);
    }

    this->root = passedNode;

}



Node* SplayTree::search(int value)
{

	//This function is almost exactly the same as the BST::search with just additional
	//pointer variables to help with the splay operations

	Node *temp = NULL;
    Node *currentNode = this->root;
    Node *previous = NULL;

    while (currentNode != NULL)
    {

        previous = currentNode;

        if (value < currentNode->data)
        {

        	currentNode = currentNode->leftChild;
       	 	count++;
       	}

        else if (value > currentNode->data) 
        {
        	currentNode = currentNode->rightChild;
        	count++;
        }

        else
        {

            temp = currentNode;
            count++;
            break;
        }
    }

    if (temp != NULL) 
    {
    	splay(temp);
    }

    else if (previous != NULL) 
    {
    	splay(previous);
    }

    return temp;

}



void SplayTree::insert(int value)
{

    if (root->data == 0)
    {

        root = new Node(value);

        return;
    }

    //If the tree is empty, the above code
    // simply makes the value the new root of the tree

    Node *currentNode = this->root;

    //The above code starts the insertion from the root

    while (currentNode != NULL)
    {

        if (value < currentNode->data)
        {

            if (currentNode->leftChild == NULL)
            {
                Node *newNode = new Node(value);

                currentNode->leftChild = newNode;

                newNode->parent = currentNode;

                splay(newNode);
                return;

            }

            else currentNode = currentNode->leftChild;
            count++;

            // The above code searches for a spot for the new node,
            // allocates memory for it, and then splays it to the top
            // to actually insert it into the tree
        }

        else if (value > currentNode->data)
        {
            if (currentNode->rightChild == NULL)
            {
                Node *newNode = new Node(value);

                currentNode->rightChild = newNode;

                newNode->parent = currentNode;

                splay(newNode);
                return;
            }

            else 
            {
                    
                currentNode = currentNode->rightChild;
                count++;

            }
        }

        else
        {
            splay(currentNode);
            return;

            //If the value is already in the tree, that value is splayed
            // to the root
        }
    }
}


Node* SplayTree::minLeaf(Node* passedNode)
{
	Node* currentNode = passedNode;

	while(currentNode && currentNode->leftChild != NULL)
	{

		currentNode = currentNode->leftChild;
		count++;
	}

	return currentNode;

}



Node* SplayTree::maxLeaf(Node* passedNode)
{

	Node* currentNode = passedNode;

	while(currentNode && currentNode->rightChild != NULL)
	{

		currentNode = currentNode->rightChild;
		count++;
	}

	return currentNode;

}


Node* SplayTree::remove(int value)
{

	// This function is very similar to the BST::remove function,
	// just with additional pointers to help when splaying nodes
	// to the top to actually remove them from the tree


	Node *deleteNode = search(value);

    if (deleteNode == NULL)
    {

        return deleteNode;
    }

    Node *left = deleteNode->leftChild;
    Node *right = deleteNode->rightChild;

    if (left == NULL && right == NULL)
    {

        this->root = NULL;
    }

    else if (left == NULL)
    {

        Node *min = minLeaf(right);
        splay(min);
    }

    else if (right == NULL)
    {

        Node *max = maxLeaf(left);
        splay(max);
    }

    else
    {

        Node *max = maxLeaf(left);
        splay(max);
        max->rightChild = right;
        right->parent = max;
    }


    delete deleteNode;
}




void SplayTree::display(Node* currentNode)
{


	if (currentNode != NULL){

		cout << currentNode->data;

		if (currentNode->leftChild != NULL)
		{

			cout << " [";

			display(currentNode->leftChild);
			cout << "]";
		}

		if (currentNode->rightChild != NULL)
		{
			cout << " [";
		 	display(currentNode->rightChild);
			cout << "]";
		}
	}


}



void SplayTree::traversalCount()
{
	cout << endl << "Splay Tree Traversal Count: " << count << endl;
}
