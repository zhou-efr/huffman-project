//
// Created by zhou on 18/11/2020.
//

#include "functions.h"

int get_file_size(FILE* file_target)
{
    fseek(file_target, 0L, SEEK_END);
    int size = ftell(file_target);
    fseek(file_target, 0L, SEEK_SET);
    return size;
}
