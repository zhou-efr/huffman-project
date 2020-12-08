//
// Created by thepa on 03/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "Element.h"

Element* init_element()
{
    Element* temp = (Element*)malloc(sizeof(Element));
    temp->next = NULL;
    temp->node = init_Tree();
    return temp;
}

Element* create_element(Tree* node, Element* next)
{
    Element* temp = (Element*)malloc(sizeof(Element));
    temp->next = next;
    temp->node = node;
    return temp;
}

void free_SLL(Element* node)
{
    if(node != 0)
    {
        free_SLL(node->next);
        free(node);
    }
}
