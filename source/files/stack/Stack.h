//
// Created by Marin-Pierre on 30/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_STACK_H
#define HUFFMAN_NAIVE_C11_STACK_H

#include "../structures.h"
#include "../HT/HuffmanTree.h"

/**
 * push_stack : push a Tree to a stack
 * @param stack
 * @param data
 */
void push_stack(Stack* stack, Tree *data);

/**
 * pull_stack : pull a tree from a stack
 * @param stack
 * @return the pulled tree
 */
Tree * pull_stack(Stack* stack);

/**
 * is_stack_empty : tell if a stack is empty or not
 * @param stack
 * @return 1 if the stack is empty, 0 else
 */
int is_stack_empty(Stack* stack);

/**
 * initialize_stack : initialize a tree node
 * @return pointer to the created node
 * node = NULL
 * next = NULL
 */
Stack* initialize_stack();

#endif //HUFFMAN_NAIVE_C11_STACK_H
