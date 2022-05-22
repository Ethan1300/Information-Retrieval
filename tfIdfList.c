// This program was written by ETHAN FONG
// on 26-03-2022
//
// Implementation of the TfIdf List ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#include "tfIdfList.h"

TfIdfList TfIdfInsert(TfIdfList l, FileList f, double tfidf) {
    bool insertAtHead = false;
    // Checking the head of the list
    if (l == NULL) {
        // list is empty
        return TfIdfNew(f->filename, tfidf);
    } else if (InOrderCondition(l, f, tfidf)) {
        // new tfidf is the largest tfidf
        insertAtHead = true;         
    if (strcmp(f->filename, l->filename) == 0) {
        // the head of the list has the same filename as the file being inserted
        // no reinsertion required, the head still has the largest tfidf
        l->tfIdfSum += tfidf;
        return l;
    }
    // Checking the rest of the list
    TfIdfList InOrderPtr = NULL;
    TfIdfList curr;
    for (curr = l; curr->next != NULL; curr = curr->next) {
        if (InOrderCondition(curr->next, f, tfidf) && InOrderPtr == NULL) {
            // If the list does not contain a node with a matching filename
            // the new node will be inserted after InOrderPtr
            InOrderPtr = curr;
        } 
        if (strcmp(f->filename, curr->next->filename) == 0) {
            // a node with a matching filename exists in the list
            // the tfidfs are summed
            tfidf += curr->next->tfIdfSum;
            // the node must be deleted and reinserted so that the list
            // remains ordered
            l = TfIdfDeleteNode(l, curr->next);
            return TfIdfInsert(l, f, tfidf);
        }
    }
    if (insertAtHead) {
        TfIdfList new = TfIdfNew(f->filename, tfidf);
        new->next = l;
        return new;
    }
    if (InOrderPtr == NULL) {
        // the are no nodes in the list with a matching filename and the given
        // tfidf is the smallest in the list
        // i.e. the new node must be inserted at the end
        InOrderPtr = curr;
    }
    // Inserting new node after the node specified by InOrderPtr
    TfIdfList temp = InOrderPtr->next;
    InOrderPtr->next = TfIdfNew(f->filename, tfidf);
    InOrderPtr->next->next = temp;
    return l;
}

bool InOrderCondition(TfIdfList l, FileList f, double tfidf) {
    double cond1 = tfidf - l->tfIdfSum;
    int cond2 = strcmp(f->filename, l->filename);
    return cond1 > 0 || (cond1 == 0 && cond2 < 0);
}

TfIdfList TfIdfDeleteNode (TfIdfList l, TfIdfList node) {
    for (TfIdfList curr = l; curr->next != NULL; curr = curr->next) {
        if (curr->next == node) {
            curr->next = curr->next->next;
            free(node->filename);
            free(node);
            break;
        }
    }
    return l;
}

TfIdfList TfIdfNew(char *filename, double tfIdfSum) {
    TfIdfList new = malloc(sizeof(*new));
    new->filename = malloc((strlen(filename) + 1) * sizeof(char));
    strcpy(new->filename, filename);
    new->tfIdfSum = tfIdfSum;
    new->next = NULL; 
    return new;
}
