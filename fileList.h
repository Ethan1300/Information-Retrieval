// This header file was written by ETHAN FONG
// on 26-03-2022
//
// Interface for the File List ADT

#ifndef FILE_LIST_H
#define FILE_LIST_H

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

/*Inserts a new FileNode into an alphabetically sorted list

    Takes a pointer to the InvertedIndexNode being inserted into, a pointer to a
    boolean variable and the filename of the pending FileNode
    Returns a FileNode pointer

    If there is not a FileNode that matches the fileName given, FileListInsert 
    inserts a new FileListNode in alphabetical order into the fileList of the 
    given InvertedIndexNode t. 

    If there exists a FileNode that matches the fileName given, the address of 
    said node is returned and *isNewWord is set to FALSE. If instead, a new
    FileNode was created and inserted, the pointer to the new node is returned
    and *isNewWord remains unchanged (TRUE).
*/
FileList FileListInsert(InvertedIndexBST t, _Bool *isNewWord, char *fileName);

/*Creates a new FileNode

    Takes a filename
    Returns a FileNode pointer

    Sets the filename of the new FileNode to the given string
*/
FileList FileListNew(char *fileName);

/*Determines the number of files in the fileList of a given Inverted Index 
  node i.e. determines the number of files that contain the word corresponding
  to the given Inverted Index Node

    Takes an InvertedIndexNode pointer.
    Returns the size of the InvertedIndexNode's fileList as an int.
*/
int FileListSize(InvertedIndexBST t);

/*Frees all memory associated with the fileList of the given InvertedIndexNode

    Takes an InvertedIndexNode pointer
*/
void FreeFileList(InvertedIndexBST t);

#endif