//
// Created by thepa on 09/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_DICTIONNARY_H
#define HUFFMAN_NAIVE_C11_DICTIONNARY_H

#include "../structures.h"

/**
 *
 * @param huff
 * @param ascii
 * @return
 */
Dico* htreetodico(Tree* huff, Tree* ascii);

/**
 *
 * @param tree
 */
void trees_balance_BST(Dico** tree);

/**
 *
 * @param tree
 * @param value
 * @param transcription
 */
void trees_add_value_BST(Dico **tree, char value, char *transcription);

/**
 *
 * @param dictionary
 * @param key
 * @return
 */
char* get_value(Dico* dictionary, char key);

/**
 *
 * @param dictionary
 */
void d_free(Dico* dictionary);

/**
 *
 * @param tree
 */
void balance(Dico** tree);

#endif //HUFFMAN_NAIVE_C11_DICTIONNARY_H
