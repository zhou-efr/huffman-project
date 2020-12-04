//
// Created by zhou on 07/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_HUFFMANTREE_H
#define HUFFMAN_NAIVE_C11_HUFFMANTREE_H

#include "../SLL/Element.h"

typedef struct _huffmanTree
{
    int occurrence;
    char data;
    struct _huffmanTree* left;
    struct _huffmanTree* right;
}Tree;

Tree* init_Tree();
Tree* create_tree(char data,
                  int occurrence,
                  Tree* left, Tree* right);
void display_tree(Tree *tree, int space);
void t_free(Tree* node);
Tree* sort_SLL_to_BT(Element* SLL);
char *get_bin(char c, Tree *source, int size);
int hasSons(Tree* arbre);
void add_node(Tree **ht, char ch);

#endif //HUFFMAN_NAIVE_C11_HUFFMANTREE_H
