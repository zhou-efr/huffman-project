//
// Created by thepa on 07/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_ELEMENT_H
#define HUFFMAN_NAIVE_C11_ELEMENT_H

#include "../structures.h"
#include "../HT/HuffmanTree.h"

Element* init_element();
Element* create_element(Tree* node , Element* next);
void list_insert(Element** l, char c, int n, int pos);
void display_liste(Element* l);
void free_SLL(Element* node);
void swap(Element* n1, Element* n2);
void add_occurrence(Element **list, char occurrence);

#endif //HUFFMAN_NAIVE_C11_ELEMENT_H
