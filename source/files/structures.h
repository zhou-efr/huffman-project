//
// Created by thepa on 07/12/2020.
//

#ifndef HUFFMAN_PROJECT_STRUCTURES_H
#define HUFFMAN_PROJECT_STRUCTURES_H

/**
 * structure _huffmanTree : binary tree node
 * type: Tree
 */
typedef struct _huffmanTree
{
    int occurrence; /** number of occurrence of the node's char */
    char data; /** node's char */
    struct _huffmanTree* left; /** left : pointer to the left son */
    struct _huffmanTree* right; /** right : pointer to the right son */
}Tree;

/**
 * structure _element : SLL
 */
typedef struct _element {
    Tree* node; /** node : Tree node */
    struct _element *next; /** next : pointer to the next element */
} Element;

/**
 * structure StackNode : SLL
 */
typedef struct StackNode {
    Tree* data; /** data : Tree node */
    struct StackNode* next; /** next : pointer to the next StackNode */
}StackNode;

/**
 * structure Stack : stack ?
 */
typedef struct Stack{
    StackNode* top; /** pointer to the top element */
}Stack;

/**
 * structure _dictionary
 */
typedef struct _dictionary
{
    char key; /** key : just the key */
    char* value; /** value : string containing (normally) the binary transcription of the key */
    struct _dictionary *right; /** right : pointer to the right son */
    struct _dictionary *left; /** left : pointer to the left son */
}Dico;

#endif //HUFFMAN_PROJECT_STRUCTURES_H
