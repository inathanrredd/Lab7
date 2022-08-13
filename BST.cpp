#include <iostream>
#include "BST.h"

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface * BST::getRootNode() const {
    return this->root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data) {
    cout << "Adding " << data << endl;
    return insert(data, this->root);
}

bool BST::insert(int data, Node *&node) {
    if (node==NULL) {
        node = new Node(data);
        return true;
    }
    else if (node->getData() == data) {
        return false;
    }
    else if (data > node->getData()) {
        return insert(data,node->getRight());
    }
    else {
        return insert(data, node->getLeft());
    }
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data) {
    cout << "Removing " << data << endl;
    return remove(data, this->root);
}


bool BST::remove(int data, Node *&node) {
    // cout << "Node->right = " << node->right << endl;
    // cout << "Node->left = " << node->left << endl;

    if (node==NULL) {
        cout << "The integer is not in the tree" << endl;
        return false;
    }
    else if (node->getData() == data) {
        if (node->left == NULL && node->right == NULL) { //it is a leaf node
            //cout << "It is a leaf node" << endl;
            delete node;
            node = NULL;
            return true;
        }
        else if (node->right == NULL) { // it has no right subtree
            //cout << "it has no right subtree" << endl;
            Node *left = node->left;
            delete node;
            node = left;
            return true;
        }
        else if (node->left == NULL) { // it has no left subtree
            //cout << "it has no left subtree" << endl;
            Node *right = node->right;
            delete node;
            node = right;
            return true;
        }
        else {
            cout << "It has subtrees on both sides" << endl;
            node->data = rightmost(node->left);


            return true;
        }
    }
    else if (data > node->getData()) {
        return remove(data, node->getRight());
    }
    else {
        return remove(data, node->getLeft());
    }
}

int BST::rightmost(Node *&node) {
    if (node->right == NULL) {
        int rightmost = node->getData();
        if (node->left != NULL) {
            Node *left = node->left;
            delete node;
            node = left;
        }
        else {
            delete node;
            node = NULL;
        }
        return rightmost;
    }
    else {
        return rightmost(node->right);
    }
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear() {
    removeAll(this->root);
}

void BST::removeAll(Node *&node) {
    if (node == NULL) {
        return;
    }
    if (node->getLeft() != NULL) {
        removeAll(node->getLeft());
    }
    if (node->getRight() != NULL) {
        removeAll(node->getRight());
    }
    if (node != NULL) {
        delete node;
        node = NULL;
    }
}