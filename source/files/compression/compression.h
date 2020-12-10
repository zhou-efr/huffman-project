#ifndef HUFFMAN_PROJECT_COMPRESSION_H
#define HUFFMAN_PROJECT_COMPRESSION_H

#include "../HT/HuffmanTree.h"

/**
 * This function compresses a given file
 * @param target is the file we want to compress
 */
int compression(char *target);

/**
 *
 * @param target
 * @param arbre
 * @param uncompressChar
 * @return
 */
int decompression(char* target, char *arbre, char *uncompressChar);

#endif //HUFFMAN_PROJECT_COMPRESSION_H
