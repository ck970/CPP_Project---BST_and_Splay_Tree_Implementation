/*
 *  main.cpp
 *
 *  COSC 160 Fall 2022
 *  Project 3
 *
 *  Due on: October 14, 2022
 *
 *  Author: Connor Ketchum ck970
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention textbooks.
 *
 *  I affirm that the files submitted are the correct files that I want to be graded.
 *  I have double-checked the submission and am certain that the zip file was
 *  correctly created and contains the correct files for this assignment.
 */

#include "BST.h"
#include "Splay.h"


int main(int argc, const char * argv[])
{
	try
	{

		if (argc < 2)
			throw invalid_argument("Please pass input file as cmd line arg");

		BST BSTree;

		SplayTree ST;

		ifstream inputFile;

    	inputFile.open(argv[1]);

    	string trashString = "";
    	string stringInput;

    	int trashCount = 0;
    	// This variable keeps track of the separating '$' character between each set of numbers in the input file


    	bool hasPrinted = false;
    	// This variable just makes sure that when printing the tree before removal, it only prints once

		std::chrono::time_point<std::chrono::system_clock> start, end;

		start = std::chrono::system_clock::now();

    	while (inputFile >> stringInput)
    	{


    		if(stringInput == "$"){

    			trashCount++;
    		} 

    		else if (trashCount == 0){

    			int newInt = stoi(stringInput);
    			// turns the string read in from the input file into an int value that can be used as a parameter for class methods

    			BSTree.insert(BSTree.root, newInt);
    		}


	    	else if(trashCount == 1){

	    		while(!hasPrinted)
	    		{
	    			cout << endl << endl << "Binary Search Tree structure before removals: ";

	    			BSTree.display();
	    			hasPrinted = true;
	    		}


	   			int newInt = stoi(stringInput);

	    		BSTree.search(newInt);
	    	}

	    	else if(trashCount == 2){

	    		int newInt = stoi(stringInput);

	    		BSTree.remove(BSTree.root, newInt);


	    	}

    	}

		end = std::chrono::system_clock::now();

		cout << endl << endl << "Binary Search Tree structure after removals: ";

		BSTree.display();

		cout << endl;
		BSTree.traversalCount();

		std::chrono::duration<double> BST_elapsed_nanoseconds = ((end - start) * pow(10,9));

		cout << endl << endl;


		cout << "Binary Search Tree Total Time: " << BST_elapsed_nanoseconds.count() << " nanoseconds." << endl;

		cout << endl << endl;

		cout << "---------------------------------------------------------------------------";
		cout << "----------------------------------" << endl << endl;

    	inputFile.open(argv[1]);

    	inputFile.clear();
    	inputFile.seekg(0);

    	trashString = "";
    	stringInput = "";
    	trashCount = 0;
    	hasPrinted = false;


		std::chrono::time_point<std::chrono::system_clock> start2, end2;

		start2 = std::chrono::system_clock::now();

    	while (inputFile >> stringInput)
    	{


    		if(stringInput == "$"){

    			trashCount++;
    		} 

    		else if (trashCount == 0){

    			int newInt = stoi(stringInput);

    			ST.insert(newInt);
    		}


	    	else if(trashCount == 1){

	    		while(!hasPrinted)
	    		{
	    			cout << endl << endl << "Splay Tree structure before removals: ";

	    			ST.display(ST.root);
	    			
	    			cout<<"]";

	    			hasPrinted = true;
	    			cout << endl << endl;
	    		}


	   			int newInt = stoi(stringInput);

	    		ST.search(newInt);
	    	}

	    	else if(trashCount == 2){

	    		int newInt = stoi(stringInput);

	    		ST.remove(newInt);


	    	}

    	}

    	end2 = std::chrono::system_clock::now();


    	cout << endl << "Splay Tree structure after removals: ";

		ST.display(ST.root);

		cout<<"]";

		cout << endl << endl;

		ST.traversalCount();

		cout << endl << endl;



		// // Throws an error if no input file is passed as argument.


		std::chrono::duration<double> ST_elapsed_nanoseconds = ((end2 - start2) * pow(10,9));

		cout << "Splay Tree Total time: " << ST_elapsed_nanoseconds.count() << " nanoseconds." << endl;

		cout << endl << endl;

    	// Calculates total time taken to complete searches and converts time from
    	// seconds to nanoseconds.


    	if (BST_elapsed_nanoseconds > ST_elapsed_nanoseconds)
    	{

    		cout << "A Splay Tree is faster for this data." << endl;
    	}

    	else if (BST_elapsed_nanoseconds < ST_elapsed_nanoseconds)
    	{

    		cout << "A Binary Search Tree is faster for this data." << endl;
    	}

    	else 
    	{

    		cout << "The two tree structures are equally efficient for this file." << endl;
    	}

    	// // Above code simply outputs whichever tree searched for the values faster after
    	// // comparing the total time values.

    	cout << endl;

    	

	}// END try block

	catch(...)
	{
		cout << endl << "\tError\n";
	}// END catch block

return 0;

}// END int main()







