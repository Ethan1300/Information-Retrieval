// This program was written by ETHAN FONG
// on 26-03-2022
//
// Interface to the TfIdf List ADT

#ifndef TFIDF_LIST_H
#define TFIDF_LIST_H

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

/*Inserts a TfIdfNode into the given TfIdfNode list in descending order of 
  tfidf.
    
    Takes a pointer to the head of an ordered list, a FileNode pointer and 
    a the tfidf being inserted.
    Returns the modified list.

    In the case that the tfidf given in the function argument matches that of
    an existing TfIdfNode in the list, the new node will be inserted in 
    alphabetical order of filename. 
    In the case that the filename as given by the filename of the FileNode f
    matches that of an existing TfIdfnode in the list, the tfidfs will be
    summed together and the node will be reinserted in order.
*/
TfIdfList TfIdfInsert(TfIdfList l, FileList f, double tfidf);

/*Deletes a TfIdfNode in a TfIdfList as part of the reinsertion process
  described in TfIdfInsert.

    Takes a pointer to the head of an ordered list, a FileNode pointer and 
    the tfidf being inserted.
    Returns the modified list

    Assumes list l is not empty
    Assumes list l contains target node
    Assumes node does not equal l (the head of the list)
*/
TfIdfList TfIdfDeleteNode (TfIdfList l, TfIdfList node);

/*Creates a new TfIdfNode

    Takes a filename and a tfidf double
    Returns a TfIdfNode pointer

    Sets the filename of the new TfIdfNode to the given filename
    Sets the tfIdfSum of the new TfIdfNode to the given double
    Sets the next of the new TfIdfNode to NULL
*/
TfIdfList TfIdfNew(char *filename, double tfIdfSum);

/*Determines whether a given TfIdfNode qualifies to be the node immediately
  after a new TfIdfNode yet to be inserted such that the given ordered list
  remains ordered.

    Takes a pointer to the head of an ordered list, a FileNode pointer and 
    a tfidf double.
    Returns true: 
    if the tfidf of the current node is less than the given tfidf
    OR
    the tfidf of the current node is equal to the given tfidf and the filename
    of the current node comes after the filename of the given Filenode 
    alphabetically.
    Returns false otherwise.
*/
_Bool InOrderCondition(TfIdfList l, FileList f, double tfidf);

#endif