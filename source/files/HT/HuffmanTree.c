//
// Created by thepa on 03/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "HuffmanTree.h"
#include "../SLL/Element.h"

/**
 *
 * @return
 */
Tree* init_Tree()
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->data = '\0';
    tree->occurrence = 0;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

/**
 *
 * @param data
 * @param occurrence
 * @param left
 * @param right
 * @return
 */
Tree* create_tree(char data, int occurrence, Tree* left, Tree* right)
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->data = data;
    tree->occurrence = occurrence;
    tree->left = left;
    tree->right = right;

    return tree;
}

/**
 *
 * @param tree
 * @param space
 */
void display_tree(Tree *tree, int space)
{
    if(tree != NULL)
    {
        if (1)
        {
            for (int i = 0; i < space; ++i) {
                printf("|  ");
            }
            printf("|-(%c : %d)\n", tree->data, tree->occurrence);
        }

        if(tree->left)
            display_tree(tree->left, space+1);

        if(tree->right)
            display_tree(tree->right, space+1);
    }
}

/**
 *
 * @param SLL
 * @return
 */
Tree* sort_SLL_to_BT(Element* SLL)
{
    Tree** top = NULL, *buffer = create_tree(SLL->data, SLL->occurrence, NULL, NULL);
    top = &buffer;
    Element* temp = SLL->next;
    while (temp != NULL)
    {
        buffer = create_tree(0, 0, create_tree(temp->data, temp->occurrence, NULL, NULL), *top);
        top = &buffer;

        // update of the iterator
        temp = temp->next;
    }
    return *top;
}

void add_node(Tree **ht, char ch)
{
    if((*ht))
    {
        if((*ht)->data == ch)
        {
            (*ht)->occurrence++;
        }else if((*ht)->data > ch){
            add_node(&((*ht)->right), ch);
        }else{
            add_node(&((*ht)->left), ch);
        }
    }else{
        (*ht) = create_tree(ch, 1, NULL, NULL);
    }
}

/**
 *
 * @param node
 */
void t_free(Tree* node)
{
    if(node != 0)
    {
        t_free(node->left);
        t_free(node->right);
        free(node);
    }
}

/**
 *
 * @param c
 * @param source
 * @param size
 * @return
 */
char *get_bin(char c, Tree *source, int size)
{
    char* tmp = NULL;

    if(source)
    {
        if(source->data == c)
        {
            tmp = (char*)malloc(sizeof(char)*(size+1));
            tmp[size] = '\0';
        }
        else
        {
            tmp = get_bin(c, source->left, size+1);
            if(tmp)
                tmp[size] = '0';
            else
            {
                tmp = get_bin(c, source->right, size+1);
                if(tmp)
                    tmp[size] = '1';
            }
        }
    }

    return tmp;
}

int hasSons(Tree* arbre)
{
    return (arbre->left && arbre->right);
}

/**
 * save_trees : save a tree in a *.tdz.dictionary file
 * @param hf : tree to save
 */
void greenPeace(Tree* hf)
{
    if(hf)
    {
        
    }
}
