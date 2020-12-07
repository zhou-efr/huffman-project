//
// Created by thepa on 03/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "Element.h"

/**
 * initialize an element
 * @return pointer to the created element
 */
Element* init_element()
{
    Element* temp = (Element*)malloc(sizeof(Element));
    temp->next = NULL;
    temp->node = init_Tree();
    return temp;
}
///*
//
//*/
///**
// * create an element
// * @param data
// * @param occurrence
// * @return pointer to the created elements
// *//*
//
Element* create_element(Tree* node, Element* next)
{
    Element* temp = (Element*)malloc(sizeof(Element));
    temp->next = next;
    temp->node = node;
    return temp;
}
//
//*/
///**
// * insert a node in a SLL
// * @param l
// * @param n
// * @param pos
// *//*
//
//void list_insert(Element** l, char c, int n, int pos)
//{
//    if(l != NULL)
//    {
//        if(*l == NULL || pos <= 1)
//        {
//            *l = create_element(c, n, *l);
//        }else{
//            list_insert(&((*l)->next), c, n, pos-1);
//        }
//    }
//}
//
//*/
///**
// *
// * @param l
// *//*
//
//void display_liste(Element* l)
//{
//    for(Element* buffer = l; buffer != NULL; buffer = buffer->next)
//    {
//        printf("(%c : %d), ", buffer->data, buffer->occurrence);
//    }
//}
//
//*/
///**
// *
// * @param node
// *//*
//
void free_SLL(Element* node)
{
    if(node != 0)
    {
        free_SLL(node->next);
        free(node);
    }
}
//
//*/
///**
// *
// * @param n1
// * @param n2
// *//*
//
//void swap(Element* n1, Element* n2)
//{
//    int n = n1->data;
//    n1->data = n2->data;
//    n2->data = n;
//
//    n = n1->occurrence;
//    n1->occurrence = n2->occurrence;
//    n2->occurrence = n;
//}
//
//void add_occurrence(Element **list, char occurrence)
//{
//    int found = 0;
//    for (Element *buffer = *list; buffer != NULL; buffer = buffer->next) {
//        if (buffer->data == occurrence && !found) {
//            buffer->occurrence++;
//            found++;
//            Element *buffer2 = buffer, *buffer_swap = buffer2;
//            Element *temp = NULL;
//            while (buffer2) {
//                if (buffer_swap->occurrence > buffer2->occurrence) {
//                    swap(buffer_swap, buffer2);
//                    buffer_swap = buffer_swap->next;
//                }
//                buffer2 = buffer2->next;
//            }
//        }
//    }
//    if (!found) {
//        list_insert(list, occurrence, 1, -1);
//    }
//}
//*/
