// Author: Giacomo Lorenzi
// A binary search tree class

#pragma once
#include <string.h>
#include "identifier.h"

// One node of the BST (Binary Search Tree)
struct node
{
    node* left; // Pointer to the left child
    node* right; // Pointer to the right child
    identifier data; // Struct to store identifier attributes
};

// BST (Binary Search Tree)
class BinaryTree
{
public:
    BinaryTree(); // Constructor (creates an empty tree)
    ~BinaryTree(); // Destructor
    void insert(identifier& new_identifier); // Inserts a new identifier
    void update(std::string word, std::string currentFunction); // Check for identifier's references to update
    void print_tree(); // Prints a representation of the tree in alphabetical order

private:
    node* root; // The root node of the tree
    void insert_helper(node** root, identifier& new_identifier); // private insert helper
    void update_helper(node** root, std::string word, std::string currentFunction); // private update helper
    void print_tree_helper(node* root); // private print tree helper
    void delete_tree(node* root); // private delete
};
