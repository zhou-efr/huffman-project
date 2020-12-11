//
// Created by zhou on 07/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_HUFFMANTREE_H
#define HUFFMAN_NAIVE_C11_HUFFMANTREE_H

#include "../structures.h"

/**
 * init_Tree : initialize a tree node
 * @return pointer to the created node
 * data = 0
 * occurrence = 0
 * left = NULL
 * right = NULL
 */
Tree* init_Tree();

/**
 * create_tree : create a Tree node from given parameters
 * @param data : char
 * @param occurrence : integer
 * @param left : left son of the tree
 * @param right : right son of the tree
 * @return pointer to the created node
 */
Tree* create_tree(char data,
                  int occurrence,
                  Tree* left, Tree* right);

/**
 * t_free : free a Tree
 * @param node
 */
void t_free(Tree* node);

/**
 * get_bin : found the string containing the binary transcription of a char in a huffman tree
 * @param c
 * @param source
 * @param size
 * @return containing the binary transcription
 */
char *get_bin(char c, Tree *source, int size);

/**
 * hasSons : tell if a tree node has at least one son
 * @param arbre
 * @return 0 if it doesn't has sons else 1
 */
int hasSons(Tree* arbre);

/**
 * BT_to_UT : convert a balance tree into an SLL of tree node sorted by occurrences
 * @param occurrences
 * @return pointer to the first node of the SLL
 */
Element* BT_to_UT(Tree* occurrences);

/**
 * SLL_to_HT : convert a SLL of tree node into an huffman tree
 * @param SLL
 * the given SLL will have one node containing the entire huffman tree
 */
void SLL_to_HT(Element** SLL);

/**
 * add_occurrences : add an occurrence to a balanced tree sorted by occurrences
 * @param ht
 * @param ch
 */
void add_occurrences(Tree **ht, char ch);

/**
 * ecosia (register_tree) : save a tree into a file
 * @param output_file
 * @param tree
 */
void ecosia(FILE* output_file, Tree* tree);

/**
 * read_tree : create a tree from a file
 * @param tree_file
 * @return pointer to the created tree
 */
Tree* read_tree(FILE* tree_file);

#endif //HUFFMAN_NAIVE_C11_HUFFMANTREE_H
