// This program was written by ETHAN FONG
// on 26-03-2022
//
// Implementation of the Inverted Index Tree ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "tree.h"

InvertedIndexBST TreeNodeNew(char *word) {
    InvertedIndexBST new = malloc(sizeof(*new));
    new->word = malloc((strlen(word) + 1) * sizeof(char));
    strncpy(new->word, word, strlen(word) + 1);
    new->fileList = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}

InvertedIndexBST TreeSearch(InvertedIndexBST t, char* word) {
    if (t == NULL) {
        // tree is empty
        return NULL;
    }
    int cmp = strcmp(word, t->word);
    if (cmp < 0) {
        return TreeSearch(t->left, word);
    } else if (cmp > 0) {
        return TreeSearch(t->right, word);
    }    
    return t;
}


InvertedIndexBST TreeInsert(InvertedIndexBST t, char *word,
                            InvertedIndexBST *ptr) {
    if (t == NULL) {
        // tree is empty
        InvertedIndexBST new = TreeNodeNew(word);
        // set pointer to point to new node
        *ptr = new;
        return new;
    }
    int cmp = strcmp(word, t->word);
    if (cmp < 0) {
        t->left = TreeInsert(t->left, word, ptr);
    } else if (cmp > 0) {
        t->right = TreeInsert(t->right, word, ptr);
    } else if (cmp == 0) {
        // InvertedIndexNode of given word already exists
        // set pointer to point to pre-existing node
        *ptr = t;
    }
    return t;
}


void TreeNodePrint(InvertedIndexBST t, FILE *out) {
    if (t == NULL) {
        return;
    }
    TreeNodePrint(t->left, out);
    fprintf(out, "%s ", t->word); 
    for (FileList curr = t->fileList; curr != NULL; curr = curr->next) {
        fprintf(out, "%s (%.7lf) ", curr->filename, curr->tf);
    }
    fprintf(out, "\n");
    TreeNodePrint(t->right, out);
}




