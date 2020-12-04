//
// Created by Marin-Pierre on 30/11/2020.
//

#include <malloc.h>
#include <stdio.h>
#include "Stack.h"

/**
 * This function is used to initialize a stack
 * @return a stack box
 */
Stack* initialize_stack()
{
    Stack* buffer = (Stack*)malloc(sizeof(Stack));
    buffer->top = NULL;
    return buffer;
}

/**
 * This function allows us to know if a stack is empty or not
 * @param stack
 * @return 1 if stack is empty and 0 if not
 */
int is_stack_empty(Stack* stack)
{
    return !(stack->top);
}

/**
 * This function take the top data of a stack and delete it
 * @param stack we want to take the data of
 * @return the data at the top of the stack
 */
Tree * pull_stack(Stack* stack)
{
    Tree* data = NULL;
    if (!is_stack_empty(stack))
    {
        data = stack->top->data;
        StackNode* buffer = stack->top;
        stack->top = buffer->next;
        free(buffer);
    }
    return data;
}

/**
 * This function add an element in a stack
 * @param stack : the stack where we want to add the element
 * @param data : the data of the tree we want to put in our stack
 */
void push_stack(Stack* stack, Tree *data)
{
    StackNode* buffer = (StackNode*)malloc(sizeof(StackNode));
    buffer->data = data;
    buffer->next = stack->top;
    stack->top = buffer;
}




