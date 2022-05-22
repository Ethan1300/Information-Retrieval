// This program was written by ETHAN FONG
// on 26-03-2022
//
// Implementation of the File List ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "fileList.h"

FileList FileListInsert(InvertedIndexBST t, bool *isNewWord, char *fileName) {
    if (t->fileList == NULL) {
        // fileList of t is empty
        t->fileList = FileListNew(fileName);
        return t->fileList;
    }
    // check the head of the list
    FileList curr = t->fileList;
    if (strcmp(fileName, curr->filename) < 0) {
        // insert new node at the head of the list
        t->fileList = FileListNew(fileName);
        t->fileList->next = curr;
        return t->fileList;
    }  else if (strcmp(fileName, curr->filename) == 0) {
        // filename of the head of the list matches given filename
        // word has already been seen in file, so isNewWord is set to false
        *isNewWord = false;
        curr->tf++;
        return curr;
    } 
    // check the rest of the list
    while (curr->next != NULL && strcmp(fileName, curr->next->filename) > 0)  {
        curr = curr->next;
    }
    if (curr->next == NULL || strcmp(fileName, curr->next->filename) < 0) {
        // insert new node in alphabetical order
        FileList new = FileListNew(fileName);
        new->next = curr->next;
        curr->next = new;
        return new;
    } else {
        // filename of curr->next matches given filename
        // word has already been seen in file, so is NewWord is set to false 
        *isNewWord = false;
        curr->next->tf++;
        return curr->next;
    }   
}

FileList FileListNew(char *fileName) {
    FileList new = malloc(sizeof(*new));
    new->filename = malloc((strlen(fileName) + 1) * sizeof(char));
    strcpy(new->filename, fileName);
    new->tf = 1;
    new->next = NULL;
    return new;
}

int FileListSize(InvertedIndexBST t) {
    int size = 0;
    for (FileList curr = t->fileList; curr != NULL; curr = curr->next) {
        size++;
    }
    return size;
}

void FreeFileList(InvertedIndexBST t) {
    if (t->fileList != NULL) {
        FileList head = t->fileList;
        while (head != NULL) {
            t->fileList = head->next;
            free(head->filename);
            free(head);
            head = t->fileList;
        }
    }
}