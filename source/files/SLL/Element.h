//
// Created by thepa on 07/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_ELEMENT_H
#define HUFFMAN_NAIVE_C11_ELEMENT_H

#include "../structures.h"
#include "../HT/HuffmanTree.h"

/**
 *
 * @return
 */
Element* init_element();

/**
 *
 * @param node
 * @param next
 * @return
 */
Element* create_element(Tree* node , Element* next);

/**
 *
 * @param node
 */
void free_SLL(Element* node);

#endif //HUFFMAN_NAIVE_C11_ELEMENT_H
