#include "BST.h"



// Default Constructor definition.
BST::BST()
{   


	root = new Node(0);
}
 
// Parameterized Constructor definition.

BST::BST(int value)
{

	root->data = value;

}

BST::~BST()
{

	deleteTree(root);
}


void BST::deleteTree(Node* passedNode){

	if (passedNode == NULL) return; 
  

    deleteTree(passedNode->leftChild); 
    deleteTree(passedNode->rightChild); 
      

    delete passedNode;
}




Node* BST::insert(Node* nodeIn, int key)
{
    count++;

	if (root->data == 0)
	{

		root->data = key;

	}

	else if (nodeIn == NULL)
	{

		Node * toAdd = new Node(key);
		return toAdd;
	}

	else
	{

		if (key > nodeIn->data) 
		{
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        	nodeIn->rightChild = insert(nodeIn->rightChild, key);

    	}

    	else
    	{

    		nodeIn->leftChild = insert(nodeIn->leftChild, key);
    		

    	}
	}
}


void BST::display()
{
	cout << "[";
	display(root);
	cout << "]" << endl;

	//This function just outputs the surrounding brackets around the tree
}


void BST::display(Node* currentNode)
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

	//This function just keeps track of the correct bracket outputs for each node in the tree



}


void BST::search(int value){

	Node* currentNode = root;

	while(currentNode != NULL && value != currentNode->data)

	{
		
		if(value > currentNode->data)
		{
			currentNode = currentNode->rightChild;
			count++;

		}

		else
		{
			currentNode = currentNode->leftChild;
			count++;
		}
	}

	//This function just searches through either side of the tree depending on whether
	// the given value is less than or greater than the currentNode's value

}



Node* BST::minLeaf(Node* passedNode)
{
	Node* currentNode = passedNode;

	while(currentNode && currentNode->leftChild != NULL)
	{

		currentNode = currentNode->leftChild;
		count++;
	}

	return currentNode;

	//This function just goes to the minimum child or descendant of a given node

}


Node* BST::maxLeaf(Node* passedNode)
{

	Node* currentNode = passedNode;

	while(currentNode && currentNode->rightChild != NULL)
	{

		currentNode = currentNode->rightChild;
		count++;
	}

	return currentNode;

	//This function just goes to the maximum child or descendant of a given node

}





Node* BST::remove(Node* root, int value){

	count++;

	if (root == NULL) return root;

	// If the passed node is already null, then that null node is returned and breaks out of the method
	//Helps to check for empty tree or repeat deletions


	//The rest of the code is simply conditional statements for each possible situation of
	// the children of the passed node

    if (value < root->data){

        root->leftChild = remove(root->leftChild, value);

    }

    else if (value > root->data){

    	root->rightChild = remove(root->rightChild, value);

    }

   else
   {
      if (root->leftChild == NULL && root->rightChild != NULL)
      {
        Node *temp = root->rightChild;
        free(root);
        return temp;

        //This creates a temporary node to keep track of the closest value child's value
        // and replaces the deleted node with that child
      }

      else if (root->rightChild == NULL && root->leftChild != NULL)
      {
        Node *temp = root->leftChild;
        free(root);
        return temp;
      }


      if (root->leftChild != NULL)
      {
	      Node *temp = maxLeaf(root->leftChild);
	      root->data = temp->data;
	      root->leftChild = remove(root->leftChild, temp->data);

	      //This code finds the maximum descendant closest in value to the original deleted node
	      // and replaces the deleted node with that descendant

      }
      else if (root->rightChild != NULL)
      {

      	Node *temp = minLeaf(root->rightChild);
      	root->data = temp->data;
        root->rightChild = remove(root->rightChild, temp->data);

        //This code finds the minimum descendant closest in value to the original deleted node
	      // and replaces the deleted node with that descendant

      }


   }

   return root;


}


void BST::traversalCount()
{
	cout << endl << "Binary Search Tree Traversal Count: " << count << endl;
}

