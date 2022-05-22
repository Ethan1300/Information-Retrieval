// This program was written by ETHAN FONG
// on 26-03-2022
//
// Inverted Index initialisation and search operations

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "invertedIndex.h"
#include "fileIndex.h"
#include "tree.h"
#include "fileList.h"
#include "helper.h"
#include "tfIdfList.h"


// Part 1

InvertedIndexBST generateInvertedIndex(char *collectionFilename) {
    // t will be returned as the root of the inverted index
    InvertedIndexBST t = NULL;		
    FILE *inColl = fopen(collectionFilename, "r");
    // nodePtr is initialised by TreeInsert function below
    InvertedIndexBST *nodePtr = malloc(sizeof(*nodePtr));
    char fileName[MAX_WORD + 1];
    // While loop to read every filename in the collection file
    while (fscanf(inColl, "%s", fileName) == 1) {
        fIndex f = FileIndexNew();
        FILE *inFile = fopen(fileName, "r");
        char word[MAX_WORD + 1];
        // While loop to read every word in the current file
        while (fscanf(inFile, "%s", word) == 1) {
            normalise(word);
            if (word[0] == '\0') {
                // if the normalised word is empty, skip to the next word
                continue;
            }
            // setting nodePtr
            // - TreeInsert sets *nodePtr to point to the InvertedIndexNode
            //   corresponding to the current word
            t = TreeInsert(t, word, nodePtr);
            bool isNewWord = true;
            // Inserting File Node
            // - FileListInsert inserts into the file list of the Inverted Index
            //   node pointed to by nodePtr
            FileList l = FileListInsert(*nodePtr, &isNewWord, fileName);
            AddWordEntry(f, l, isNewWord);
        }
        fclose(inFile);
        // file index is used to return to every file node of the current file
        for (wEntry curr = f->entries; curr != NULL; curr = curr->next) {
            // tf of a file node is divided by the total word count of a file
            curr->word->tf = curr->word->tf / f->nofWords;
        }
        FreeFileIndex(f);
    }
    fclose(inColl);
    free(nodePtr);
    return t;
}

void printInvertedIndex(InvertedIndexBST tree, char *filename) {
    FILE *out = fopen(filename, "w");
    TreeNodePrint(tree, out);
    fclose(out);
}

void freeInvertedIndex(InvertedIndexBST tree) {
    if (tree != NULL) {
        freeInvertedIndex(tree->left);
        freeInvertedIndex(tree->right);
        FreeFileList(tree);
        free(tree->word);
        free(tree);
    }
}

// Part 2

TfIdfList searchOne(InvertedIndexBST tree, char *searchWord, int D) {
    TfIdfList l = NULL;
    l = doSearchOne(l, tree, searchWord, D);
    return l;
}

TfIdfList searchMany(InvertedIndexBST tree, char *searchWords[], int D) {
    TfIdfList l = NULL;
    for (int i = 0; searchWords[i] != NULL; i++) {
        l = doSearchOne(l, tree, searchWords[i], D);
    }
    return l;
}

void freeTfIdfList(TfIdfList list) {
    if (list == NULL) {
        return;
    }
    TfIdfList temp = list->next;
    for (TfIdfList curr = list; curr != NULL; curr = temp) {
        temp = curr->next;
        free(curr->filename);
        free(curr);
    }
}

