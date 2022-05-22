// This program was written by ETHAN FONG
// on 26-03-2022
//
// Interface to the file index ADT
//
// The file index of a given file contains a list of words that the file 
// contains. The words are recorded in the form of pointers to the FileNode
// of the file in the InvertedIndexNode of the word. This allows access to all 
// the words present in a file for the purposes of calculating tf and for the
// sake of efficiency.

#ifndef FILE_INDEX_H
#define FILE_INDEX_H

#define MAX_WORD 100

#include "invertedIndex.h"



/*  The FileIndex contains a list of normalised words within a file (entries)
    and the total number of normalised words within a file (nofWords).
    The words are stored in the list in the form of WordEntry structs
*/
struct FileIndex {
    struct WordEntry *entries;
    int nofWords;
};

/*  Each WordEntry contains a pointer to an Inverted Index node that corresponds 
    to the word the WordEntry represents (word) and a pointer to the next 
    WordEntry in the list (next).
*/  
struct WordEntry {
    FileList word;
    struct WordEntry *next;
};

typedef struct WordEntry *wEntry;
typedef struct FileIndex *fIndex;

/*******************************************************************************
********************************************************************************
********************************************************************************
*************************                          *****************************
*************************        FUNCTIONS         *****************************
*************************                          *****************************
********************************************************************************
********************************************************************************
*******************************************************************************/

/*Creates a new FileIndex

    Returns a pointer to a FileIndex.
*/ 
fIndex FileIndexNew(void);

/*Adds a WordEntry to the entries list of a FileIndex in no particular order

    Takes a pointer to the FileIndex being modified, a FileNode pointer, and a 
    boolean variable.
    
    If isNewWord == TRUE:
    - a new WordEntry is inserted into the WordEntry list (entries) of FileIndex 
      f at the head of the list
    - the FileNode pointer of the new WordEntry is set to the FileNode pointer
      given in the argument
    - the number of total words in the file (nofWords) is increased by 1
    If isNewWord == FALSE:
    - the number of total words in the file (nofWords) is increased by 1
*/
void AddWordEntry(fIndex f, FileList word, _Bool isNewWord);

/*Frees all memory associated with a given FileIndex 

    Takes a pointer to the FileIndex being freed.
*/
void FreeFileIndex(fIndex f);



#endif