//
// Created by thepa on 09/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_DICTIONNARY_H
#define HUFFMAN_NAIVE_C11_DICTIONNARY_H

#include "../structures.h"

/**
 * htreetodico : convert a huffman tree into a dictionary
 * @param huff
 * @param ascii
 * @return pointer to de dictionary
 */
Dico* htreetodico(Tree* huff, Tree* ascii);

/**
 * get_value : return the binary path of a char in a huffman tree
 * @param dictionary
 * @param key
 * @return string containing the binary transcription
 */
char* get_value(Dico* dictionary, char key);

/**
 * d_free : free a dictionary
 * @param dictionary
 */
void d_free(Dico* dictionary);

#endif //HUFFMAN_NAIVE_C11_DICTIONNARY_H
