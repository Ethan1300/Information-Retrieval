// This program was written by ETHAN FONG
// on 26-03-2022
//
// Helper functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#include "helper.h"

void normalise(char *word) {
    int i;
    // start the loop at the final character of the string
    // loop until reach first non-removeable character, this will be the new
    // final character of the string
    for (i = strlen(word) - 1; i >= 0 && isRemoveable(word[i]); i--) {    
    }
    word[i + 1] = '\0';
    for (i = 0; word[i] != '\0'; i++) {
        // Change all uppercase letters to lowercase letters
        if (isupper(word[i]) != 0) {
            word[i] = word[i] - 'A' + 'a';
        }
    }
    return;
}

bool isRemoveable(char c) {
    if (c == '.' || c == ',' || c == ';'|| c == ':' || c == '?' || c == '*') {
        return true;
    } else {
        return false;
    }
}

TfIdfList doSearchOne(TfIdfList l, InvertedIndexBST tree, char *searchWord, 
                      int D) {
    InvertedIndexBST searchNode = TreeSearch(tree, searchWord);
    if (searchNode == NULL) {
        // there exist no files that contain the search word
        return l;
    }
    double N = D;
    double size = FileListSize(searchNode);
    double idf = N / size;
    idf = log10(idf);
    double tfidf;
    
    // loop through the InvertedIndexNode of the search word and add a TfIdfNode
    // for each FileNode in the fileList
    FileList curr;
    for (curr = searchNode->fileList; curr != NULL; curr = curr->next) {
        tfidf = idf * curr->tf;
        l = TfIdfInsert(l, curr, tfidf);
    }
    return l;
}