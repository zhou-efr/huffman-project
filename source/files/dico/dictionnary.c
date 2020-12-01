//
// Created by thepa on 09/11/2020.
// Optimized, rewrite and published on repo by Lou_ on 01/12/2020 
//

#include <stdio.h>
#include "dictionnary.h"
#include "../stack/Stack.h"
#include "../HT/HuffmanTree.h"
#include "../SLL/Element.h"


Dico* merge(Dico* a, Dico* b)
{
    if(a == NULL)
    {
        if(b == NULL)
        {
            return NULL;
        }
        return b;
    }
    if(b == NULL)
    {
        return a;
    }

    Dico** scan = &a;
    while(*scan != NULL)
    {
        if(b != NULL && b->data < (*scan)->data)
        {
            Dico* temp = b;
            b = b->left;
            temp->left = *scan;
            *scan = temp;
        }
        scan = &(*scan)->left;
    }
    if(b != NULL)
    {
        *scan = b;
    }
    return a;
}

Dico* all_left_dico(Tree* huff, char* buffer, int lsize, int psize)
{
    if(huff == NULL){return NULL;}
    if(huff->data != 0)
    {
        Dico* ret = (Dico*)malloc(sizeof(Dico));
        ret->key = huff->data;
        ret->value = copy(buffer, lsize);
        ret->left = NULL;
        ret->right = NULL;

        return ret;
    }

    int fr = 0;
    if(lsize + 1 > psize)
    {
        psize += 100;
        buffer = (char*)malloc(psize*sizeof(char));
        fr = 1;
    }

    buffer[lsize] = '0';
    Dico* zero = all_left_dico(huff->left, buffer, lsize+1, psize);
    buffer[lsize] = '1';
    Dico* one = all_left_dico(huff->right, buffer, lsize+1, psize);

    if(fr){free(buffer);}

    return merge(zero, one);
}

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

void saveDictionary(Dico* dictionary)
{
    FILE* out = fopen("dictionary.txt", "w");
    sub_function_saveDictionary(dictionary, out);
    fclose(out);
}

void sub_function_saveDictionary(Dico* dictionary, FILE* dico_file)
{
    if(dictionary != NULL)
    {
        fprintf(dico_file, "%c%s", dictionary->key, dictionary->value);
        //printf("%c : %s\n", dictionary->key, dictionary->value);
        sub_function_saveDictionary(dictionary->left);
        sub_function_saveDictionary(dictionary->right);
    }
}