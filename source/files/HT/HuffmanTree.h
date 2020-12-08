//
// Created by zhou on 07/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_HUFFMANTREE_H
#define HUFFMAN_NAIVE_C11_HUFFMANTREE_H

#include "../structures.h"
#include "../SLL/Element.h"

Tree* init_Tree();
Tree* create_tree(char data,
                  int occurrence,
                  Tree* left, Tree* right);
void display_tree(Tree *tree, int space);
void t_free(Tree* node);
Tree* sort_SLL_to_BT(Element* SLL);
char *get_bin(char c, Tree *source, int size);
int hasSons(Tree* arbre);
Element* BT_to_UT(Tree* occurrences);
void SLL_to_HT(Element** SLL);
void add_occurrences(Tree **ht, char ch);
void register_tree(FILE* output_file, Tree* tree);
Tree* read_tree(FILE* tree_file);

#endif //HUFFMAN_NAIVE_C11_HUFFMANTREE_H
