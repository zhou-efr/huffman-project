//
// Created by Marin-Pierre on 30/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_STACK_H
#define HUFFMAN_NAIVE_C11_STACK_H

#include "../structures.h"
#include "../HT/HuffmanTree.h"

/**
 *
 * @param stack
 * @param data
 */
void push_stack(Stack* stack, Tree *data);

/**
 *
 * @param stack
 * @return
 */
Tree * pull_stack(Stack* stack);

/**
 *
 * @param stack
 * @return
 */
int is_stack_empty(Stack* stack);

/**
 *
 * @return
 */
Stack* initialize_stack();

#endif //HUFFMAN_NAIVE_C11_STACK_H
