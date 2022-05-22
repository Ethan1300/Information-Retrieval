// This program was written by ETHAN FONG
// on 26-03-2022
//
// Helper functions

#ifndef HELPER_H
#define HELPER_H

#include "invertedIndex.h"
#include "tfIdfList.h"
#include "fileList.h"
#include "tree.h"

/*******************************************************************************
********************************************************************************
********************************************************************************
*************************                          *****************************
*************************        FUNCTIONS         *****************************
*************************                          *****************************
********************************************************************************
********************************************************************************
*******************************************************************************/

/*Normalises a given string

    Takes a word.
    Returns a normalised word.

    Normalisation involves: 
    - converting all letters to lowercase
    - removing certain punctuation marks from the ends of words
*/
void normalise(char *word);

/*Determines whether a given character is 'removeable'

    Takes a character.
    Returns true if the character is 'removeable'.
    Returns false if the character is not 'removeable'.

    'Removeable' refers to the list of characters that must be removed from the 
    ends of words per the definition of normalisation
*/
_Bool isRemoveable(char c);

/*Adds TfIdfNodes for all of the files that contain a given word to a given list

    Takes a pointer to the head of an ordered list, a inverted index tree, the 
    word being searched and the size number of files in the collection as an
    int.
    Returns a modified list.
*/
TfIdfList doSearchOne(TfIdfList l, InvertedIndexBST tree, char *searchWord, 
                      int D);


#endif

