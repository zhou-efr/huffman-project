//
// Created by thepa on 09/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "dictionnary.h"
#include "../HT/HuffmanTree.h"

Dico* htreetodico(Tree* huff, Tree* ascii)
{
    if(ascii)
    {   Dico* tree = (Dico*)malloc(sizeof(Dico));
        (tree)->key = ascii->data;
        (tree)->value = get_bin(ascii->data, huff, 0);
        (tree)->left = htreetodico(huff, ascii->left);
        (tree)->right = htreetodico(huff, ascii->right);
        free(ascii);
        return tree;
    }
    return NULL;
}

char* get_value(Dico* dictionary, char key)
{
    if(!dictionary)
        return "";
    else if(dictionary->key == key)
        return dictionary->value;
    else if(key > dictionary->key)
        return get_value(dictionary->left, key);
    else
        return get_value(dictionary->right, key);
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
