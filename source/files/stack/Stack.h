//
// Created by Marin-Pierre on 30/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_STACK_H
#define HUFFMAN_NAIVE_C11_STACK_H

#include "../HT/HuffmanTree.h"

typedef struct StackNode {
    Tree* data;
    struct StackNode* next;
}StackNode;

typedef struct Stack{
    StackNode* top;
}Stack;

void push_stack(Stack* stack, Tree *data);
Tree * pull_stack(Stack* stack);
int is_stack_empty(Stack* stack);
Stack* initialize_stack();

#endif //HUFFMAN_NAIVE_C11_STACK_H
