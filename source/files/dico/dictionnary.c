//
// Created by thepa on 09/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "dictionnary.h"
#include "../stack/Stack.h"
#include "../HT/HuffmanTree.h"
#include "../SLL/Element.h"

Dico* htreetodico(Tree* huff, Tree* ascii)
{
    if(ascii)
    {   Dico* tree = (Dico*)malloc(sizeof(Dico));
        (tree)->key = ascii->data;
        (tree)->value = get_bin(ascii->data, huff, 0);
        (tree)->left = htreetodico(huff, ascii->left);
        (tree)->right = htreetodico(huff, ascii->right);
        return tree;
    }
    return NULL;
}

int depth(Dico* tree){
    if(tree == NULL){
        return 0;//Attention définition. -1 ou 0
    }
    else{
        int depth_left = depth(tree->left);
        int depth_right = depth(tree->right);
        if(depth_left > depth_right){
            return 1 + depth_left;
        }
        else{
            return 1 + depth_right;
        }
    }
}

int bf(Dico* tree){
    if(tree == NULL) {
        return 0;
    }
    else{
        return depth(tree->right) - depth(tree->left);
    }
}

void right_rotation(Dico** tree){
    if (*tree != NULL){
        Dico* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}

void left_rotation(Dico** tree){
    if (*tree != NULL){
        Dico* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}

void balance(Dico** tree){
    if (*tree != NULL){
        balance(&((*tree)->left));// Postfix
        balance(&((*tree)->right));

        int balance_factor = bf(*tree);
        if (balance_factor <= -2){// Cas Gauche - ??
            if(bf((*tree)->left) > 0){// Gauche - Droite
                left_rotation(&((*tree)->left));
            }
            right_rotation(tree);// Gauche - Gauche
        }
        else if (balance_factor >= 2){// Cas Droite - ??
            if(bf((*tree)->right) < 0){// Droite - Gauche
                right_rotation(&((*tree)->right));
            }
            left_rotation(tree);// Droite - Droite
        }
    }
}

void trees_balance_BST(Dico** tree){
    if(*tree != 0)
    {
        trees_balance_BST(&((*tree)->left));
        trees_balance_BST(&((*tree)->right));
        while(bf(*tree) >= 2 || bf(*tree) <= -2)
        {
            balance(tree);
        }
    }
}

void trees_add_value_BST(Dico **tree, char value, char *transcription) {
    if(*tree != NULL)
    {
        if(value > (*tree)->key)
        {
            trees_add_value_BST(&((*tree)->right), value, transcription);
        }
        else if(value < (*tree)->key)
        {
            trees_add_value_BST(&((*tree)->left), value, transcription);
        }
    }else
    {
        *tree = (Dico*)malloc(sizeof(Dico));
        (*tree)->key = value;
        (*tree)->value = transcription;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
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

Dico* slltodico(Element* node)
{
    /*Tree* buffer = sort_SLL_to_BT(node);
    Dico* tmp = htreetodico(buffer);
    t_free(buffer);
    return tmp;*/

    return NULL;
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
    if(dictionary)
    {
        FILE* out = fopen("dictionary.txt", "a");

        fprintf(out, "%c%s", dictionary->key, dictionary->value);
        //printf("%c : %s\n", dictionary->key, dictionary->value);

        fclose(out);

        saveDictionary(dictionary->left);
        saveDictionary(dictionary->right);
    }
}
