// This header file was written by ETHAN FONG
// on 26-03-2022
//
// Interface for the Inverted Index Tree ADT

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include "fileList.h"
#include "invertedIndex.h"

/*******************************************************************************
********************************************************************************
********************************************************************************
*************************                          *****************************
*************************        FUNCTIONS         *****************************
*************************                          *****************************
********************************************************************************
********************************************************************************
*******************************************************************************/

/*Creates a new Inverted Index Node

    Takes a word
    Returns an InvertedIndexNode point
*/
InvertedIndexBST TreeNodeNew(char *word);

/*Searches an inverted index for the InvertedIndexNode that corresponds to the
  given word and returns its address

    Takes an inverted index tree t and a search word
    Returns an InvertedIndexNode pointer
*/
InvertedIndexBST TreeSearch(InvertedIndexBST t, char* word);

/*Inserts a new InvertedIndexNode into the given, alphabetically sorted, binary
  tree

    Takes an inverted index tree, a search word and a pointer to an
    InvertedIndexNode pointer
    Returns the inverted index tree

    TreeInsert will attempt to search the tree recursively for a 
    InvertedIndexNode that corresponds to the given word. If it does not find 
    such a node, it will create and insert a new node and return the modified 
    tree. In the case such a node is found, TreeInsert will return the 
    unmodified tree.

    In either case, the address of the InvertedIndexNode corresponding to the 
    given word will be stored in the InvertedIndexNode pointer pointed to by the 
    ptr argument.
*/
InvertedIndexBST TreeInsert(InvertedIndexBST t, char *word, InvertedIndexBST 
                            *ptr);

/*Prints an inverted index tree out into a file
    
    Takes an inverted index tree and a file pointer
*/
void TreeNodePrint(InvertedIndexBST t, FILE *out);


#endif