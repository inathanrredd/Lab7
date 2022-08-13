#pragma once

#include <iostream>
#include "NodeInterface.h"
#include "BTNode.h"

using namespace std;

class Node : public NodeInterface {

public:
	int data;
	Node* left;
	Node* right;

	Node(const int the_data,
		 Node* left_val = NULL,
		 Node* right_val = NULL ) :
		 data(the_data), left(left_val), right(right_val) {
    }
	~Node() {
	}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;
	Node *&getRight();
	Node *&getLeft();

};