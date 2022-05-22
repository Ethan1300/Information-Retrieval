# Information Retrieval Makefile
#
CC = gcc
CFLAGS = -Wall -Werror -g

SUPPORTING_FILES = fileIndex.c fileIndex.h tree.c tree.h tfIdfList.c tfIdfList.h helper.c helper.h fileList.c fileList.h

.PHONY: all
all: exmp1/testInvertedIndex exmp2/testInvertedIndex

exmp1/testInvertedIndex: exmp1/testInvertedIndex.c invertedIndex.c $(SUPPORTING_FILES)
	$(CC) $(CFLAGS) -o exmp1/testInvertedIndex exmp1/testInvertedIndex.c invertedIndex.c $(SUPPORTING_FILES) -lm

exmp2/testInvertedIndex: exmp2/testInvertedIndex.c invertedIndex.c $(SUPPORTING_FILES)
	$(CC) $(CFLAGS) -o exmp2/testInvertedIndex exmp2/testInvertedIndex.c invertedIndex.c $(SUPPORTING_FILES) -lm

.PHONY: clean
clean:
	rm -f */testInvertedIndex

