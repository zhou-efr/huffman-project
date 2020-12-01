//
// Created by thepa on 09/11/2020.
// Optimized, rewrite and published on repo by Lou_ on 01/12/2020 
//

#include <stdio.h>
#include "dictionnary.h"
#include "../stack/Stack.h"
#include "../HT/HuffmanTree.h"
#include "../SLL/Element.h"



int lenght(Dico* d)
{
    if(d != NULL)
    {
        return 1 + lenght(d->left);
    }
    return 0;
}
Dico* mid_of(Dico* d)
{
    int len = lenght(d);

    Dico* ret = d;
    for(int i = 0; i<len/2 - 1; i++)
    {
        ret = ret->left;
    }
    Dico* buffer = ret;
    ret = ret->left;
    buffer->left = NULL;

    return ret;
}
void balance_BST_all_left(Dico** tree)
{
    if(tree == NULL){return;}

    if(*tree != NULL && (*tree)->left != NULL)
    {
        Dico* buffer = *tree;
        *tree = mid_of(buffer);
        (*tree)->right = buffer;
        balance_BST_all_left(&(*tree)->left);
        balance_BST_all_left(&(*tree)->right);
    }
}

Dico* htreetodico(Tree* huff)
{
    char buffer[100];
    Dico* ret = all_left_dico(huff, buffer, 0, 100);
    balance_BST_all_left(&ret);
    return ret;
}

char* get_value(Dico* dictionary, char key)
{
    if(!dictionary)
        return "";
    else if(dictionary->key == key)
        return dictionary->value;
    else if(key < dictionary->key)
        return get_value(dictionary->left, key);
    else
        return get_value(dictionary->right, key);
}

Dico* slltodico(Element* node)
{
    Tree* buffer = sort_SLL_to_BT(node);
    Dico* tmp = htreetodico(buffer);
    t_free(buffer);
    return tmp;
}

void d_free(Dico* dictionary)
{
    if(dictionary)
    {
        d_free(dictionary->left);
        d_free(dictionary->right);
        free(dictionary->value);
        free(dictionary);
    }
}

