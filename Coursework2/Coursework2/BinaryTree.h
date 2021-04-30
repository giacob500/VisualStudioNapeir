//Author: Giacomo Lorenzi
//A binary search tree class

#pragma once
#include <string.h>
#include "identifier.h"

//One node of the BST (Binary Search Tree)
struct node
{
    node* left; //Pointer to the left child
    node* right; //Pointer to the right child
    identifier data;
};

class BinaryTree
{
public:
    BinaryTree(); //Creates an empty tree
    ~BinaryTree(); //Destructor
    void insert(identifier& new_identifier, std::string currentFunction); //Inserts a new word
    void update(std::string word, std::string currentFunction);
    void print_tree(); //Returns a string representation of the tree

private:
    node* root; //The root node of the tree
    void insert_helper(node** root, identifier& new_identifier, std::string currentFunction); //private insert helper
    void update_helper(node** root, std::string word, std::string currentFunction);
    void print_tree_helper(node* root); //private print tree helper
    void delete_tree(node* root); //private insert helper    
};
