//Author: Giacomo Lorenzi
//A binary search tree class
/*
#pragma once

#include "word_info.h"
using namespace std;

//One node of the BST (Binary Search Tree)
struct node
{
    string identifierName;
    int lineNumber = 0;
    string whatIs;
    string identifierType;
    int timesReferenced = 0;
    int data;
    node* left; //Pointer to the left child
    node* right; //Pointer to the right child
};

class BinaryTree
{
public:
    BinaryTree(); //Creates an empty tree
    ~BinaryTree(); //Destructor
    void insert(word_info& new_word); //Inserts a new word
    std::string print_tree(); //Returns a string representation of the tree

private:
    node* root; //The root node of the tree

    void insert_helper(node** root, word_info& new_word); //private insert helper
    std::string print_tree_helper(node* root); //private print tree helper
};
*/