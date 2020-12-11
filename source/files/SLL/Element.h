//
// Created by thepa on 07/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_ELEMENT_H
#define HUFFMAN_NAIVE_C11_ELEMENT_H

#include "../structures.h"
#include "../HT/HuffmanTree.h"

/**
 * init_element : initialize an element
 * @return pointer to the initialized element
 */
Element* init_element();

/**
 * create_element : create a create_element node from given parameters
 * @param node
 * @param next
 * @return pointer to the created node
 */
Element* create_element(Tree* node , Element* next);

/**
 * free_SLL : free a SLL
 * @param node
 */
void free_SLL(Element* node);

#endif //HUFFMAN_NAIVE_C11_ELEMENT_H
