//Author: Simon Powers
//A binary search tree class

#pragma once

#include "word_info.h"

//One node of the BST (Binary Search Tree)
struct diocan
{
    diocan *left; //Pointer to the left child
    diocan *right; //Pointer to the right child
    word_info data; //Stores the word_info struct 
};

class BST
{
    public:
        BST(); //Creates an empty tree
        ~BST(); //Destructor
        void insert(word_info & new_word); //Inserts a new word
        std::string print_tree(); //Returns a string representation of the tree

    private:
        diocan *root; //The root node of the tree

        void insert_helper(diocan **root, word_info & new_word); //private insert helper
        std::string print_tree_helper(diocan *root); //private print tree helper
};