//
// Created by Marin-Pierre on 30/11/2020.
//

#include <malloc.h>
#include <stdio.h>
#include "Stack.h"

Stack* initialize_stack()
{
    Stack* buffer = (Stack*)malloc(sizeof(Stack));
    buffer->top = NULL;
    return buffer;
}

int is_stack_empty(Stack* stack)
{
    return !(stack->top);
}

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

void push_stack(Stack* stack, Tree *data)
{
    StackNode* buffer = (StackNode*)malloc(sizeof(StackNode));
    buffer->data = data;
    buffer->next = stack->top;
    stack->top = buffer;
}

void trees_log_prefix(Tree *tree){
    if(!tree){return;}
    Stack* history = initialize_stack();
    push_stack(history, tree);

    while(!is_stack_empty(history)){
        Tree* node = pull_stack(history);

        if(node->right){
            push_stack(history, node->right);
        }

        if(node->left){
            push_stack(history, node->left);
        }
    }

    free(history);
}


