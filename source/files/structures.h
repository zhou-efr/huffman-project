//
// Created by thepa on 07/12/2020.
//

#ifndef HUFFMAN_PROJECT_STRUCTURES_H
#define HUFFMAN_PROJECT_STRUCTURES_H

/*
 * structure _huffmanTree : binary tree node
 * type: Tree
 */
typedef struct _huffmanTree
{
    int occurrence;
    char data;
    struct _huffmanTree* left;
    struct _huffmanTree* right;
}Tree;

/**
 * structure _element : SLL
 */
typedef struct _element {
    Tree* node;
    struct _element *next;
} Element;

typedef struct StackNode {
    Tree* data;
    struct StackNode* next;
}StackNode;

typedef struct Stack{
    StackNode* top;
}Stack;

typedef struct _dictionary
{
    char key;
    char* value;
    struct _dictionary *right;
    struct _dictionary *left;
}Dico;

#endif //HUFFMAN_PROJECT_STRUCTURES_H
