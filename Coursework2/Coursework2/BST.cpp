//Author: Simon Powers
//Implementation of a binary search tree class

#include "BST.h"
#include <iostream>
using namespace std;

//Creates an empty tree
BST::BST()
{
    root = nullptr;
}

//Destructor
BST::~BST()
{
    //TODO
    //Call a private delete tree helper method
}

//Inserts a new word
void BST::insert(word_info & new_word)
{
    insert_helper(&root, new_word);
}

//Returns a string representation of the tree in alphabetical order (in order)
string BST::print_tree()
{
    //TODO -- call helper method.
    return "";
}

//Private insert helper
//Parameters: root -- the root node of the tree; new_word, a struct with word info to insert
void BST::insert_helper(diocan **root, word_info & new_word)
{
    if(*root == nullptr)
    {
        *root = new diocan();
        (*root)->left = nullptr;
        (*root)->right = nullptr;
        (*root)->data = new_word;
    }
    else
    {
        if(new_word.word < (*root)->data.word)
        {
            //The new word comes before root alphabetically, so go left.
            insert_helper(&((*root)->left), new_word);
        }
        else
        {
            //The new word comes after root alphabetically, so go right.
            insert_helper(&((*root)->right), new_word);
        }
    }

}

//Private print_tree helper
//Returns a string representation of the tree in alphabetical order
string BST::print_tree_helper(diocan *root)
{
    //To be implemented
    //Print the left node, print the root, then print the right node, ret
    return ""; 
}
