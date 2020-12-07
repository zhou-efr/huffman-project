//
// Created by thepa on 09/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_DICTIONNARY_H
#define HUFFMAN_NAIVE_C11_DICTIONNARY_H

#include "../structures.h"
#include "../HT/HuffmanTree.h"
#include "../SLL/Element.h"

Dico* htreetodico(Tree* huff, Tree* ascii);
Dico* sort(Dico* dictionary);
void trees_balance_BST(Dico** tree);
void trees_add_value_BST(Dico **tree, char value, char *transcription);
char* get_value(Dico* dictionary, char key);
Dico* slltodico(Element* node);
void d_free(Dico* dictionary);
void saveDictionary(Dico* dictionary);
void balance(Dico** tree);

#endif //HUFFMAN_NAIVE_C11_DICTIONNARY_H
