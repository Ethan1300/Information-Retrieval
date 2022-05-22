// This program was written by ETHAN FONG
// on 26-03-2022
//
// Implementation of the File Index ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#include "fileIndex.h"
 

fIndex FileIndexNew(void) {
    fIndex f = malloc(sizeof(*f));
    f->entries = NULL;
    f->nofWords = 0;
    return f;
}

void AddWordEntry(fIndex f, FileList word, bool isNewWord) {
    if (isNewWord) {
        if (f->entries == NULL) {
            f->entries = malloc(sizeof(struct WordEntry));
            f->entries->word = word;
            f->entries->next = NULL;
        } else {
            wEntry temp = f->entries;
            f->entries = malloc(sizeof(struct WordEntry));
            f->entries->word = word;
            f->entries->next = temp;
        }
    }
    f->nofWords++;
}

void FreeFileIndex(fIndex f) {
    if (f->entries != NULL) {
        wEntry head = f->entries;
        while (head != NULL) {
            f->entries = head->next;
            free(head);
            head = f->entries;
        }
    }
    free(f);
}




