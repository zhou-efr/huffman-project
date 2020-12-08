#ifndef HUFFMAN_PROJECT_COMPRESSION_H
#define HUFFMAN_PROJECT_COMPRESSION_H

#include "../HT/HuffmanTree.h"

/**
 * This function compresses a given file
 * @param target is the file we want to compress
 */
int b_compression(char *target);

// /**
// * This funtion decompresses a given file thanks to a given HT
// * @param target is the file we want to decompress
// * @param tree is the key tree
// */
//void b_decompression(char *target, Tree *tree);
/**
 *
 * @param target
 * @param arbre
 * @param uncompressChar
 * @return
 */
int uncompressChar(char* target, char *arbre, char *uncompressChar);

#endif //HUFFMAN_PROJECT_COMPRESSION_H
