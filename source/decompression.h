#ifndef HUFFMAN_PROJECT_DECOMPRESSION_H
#define HUFFMAN_PROJECT_DECOMPRESSION_H

#include "files/HT/HuffmanTree.h"

void b_decompression(char *target, Tree *tree);
int isZero(char a);
int uncompressChar(char* target, char *arbre, char *uncompressChar);

#endif //HUFFMAN_PROJECT_DECOMPRESSION_H
