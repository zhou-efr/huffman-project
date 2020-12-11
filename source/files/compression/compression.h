#ifndef HUFFMAN_PROJECT_COMPRESSION_H
#define HUFFMAN_PROJECT_COMPRESSION_H

#include "../HT/HuffmanTree.h"

/**
 * This function compresses a given file
 * @param target is the file we want to compress
 * @return whether the function success or not
 */
int compression(char *target);

/**
 *
 * @param target : path to the compressed file
 * @param arbre : path to the saved tree
 * @param uncompressChar : path to the file where the output will be write
 * @return whether the function success or not
 */
int decompression(char* target, char *arbre, char *uncompressChar);

#endif //HUFFMAN_PROJECT_COMPRESSION_H
