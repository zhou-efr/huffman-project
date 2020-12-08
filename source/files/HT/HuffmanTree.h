//
// Created by zhou on 07/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_HUFFMANTREE_H
#define HUFFMAN_NAIVE_C11_HUFFMANTREE_H

#include "../structures.h"

/**
 *
 * @return
 */
Tree* init_Tree();

/**
 *
 * @param data
 * @param occurrence
 * @param left
 * @param right
 * @return
 */
Tree* create_tree(char data,
                  int occurrence,
                  Tree* left, Tree* right);

/**
 *
 * @param node
 */
void t_free(Tree* node);

/**
 *
 * @param c
 * @param source
 * @param size
 * @return
 */
char *get_bin(char c, Tree *source, int size);

/**
 *
 * @param arbre
 * @return
 */
int hasSons(Tree* arbre);

/**
 *
 * @param occurrences
 * @return
 */
Element* BT_to_UT(Tree* occurrences);

/**
 *
 * @param SLL
 */
void SLL_to_HT(Element** SLL);

/**
 *
 * @param ht
 * @param ch
 */
void add_occurrences(Tree **ht, char ch);

/**
 *
 * @param output_file
 * @param tree
 */
void register_tree(FILE* output_file, Tree* tree);

/**
 *
 * @param tree_file
 * @return
 */
Tree* read_tree(FILE* tree_file);

#endif //HUFFMAN_NAIVE_C11_HUFFMANTREE_H
