#ifndef HUFFMAN_PROJECT_DECOMPRESSION_H
#define HUFFMAN_PROJECT_DECOMPRESSION_H

#include "files/HT/HuffmanTree.h"

void b_decompression(char *target, Tree *tree);
int isZero(char a);
void uncompress(char* target, Tree* arbre);

#endif //HUFFMAN_PROJECT_DECOMPRESSION_H
