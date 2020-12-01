//
// Created by thepa on 09/11/2020.
// Rewrite and published on repo by Lou_ on 01/12/2020 
//

#ifndef HUFFMAN_NAIVE_C11_DICTIONNARY_H
#define HUFFMAN_NAIVE_C11_DICTIONNARY_H

#include <mmcobj.h>
#include "../HT/HuffmanTree.h"
#include "../SLL/Element.h"

typedef struct _dictionary
{
    char key;
    char* value;
    struct _dictionary *right;
    struct _dictionary *left;
}Dico;

char* get_value(Dico* dictionary, char key);
Dico* slltodico(Element* node);
void d_free(Dico* dictionary);

#endif //HUFFMAN_NAIVE_C11_DICTIONNARY_H