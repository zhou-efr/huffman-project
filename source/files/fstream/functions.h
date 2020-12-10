//
// Created by zhou on 18/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_FUNCTIONS_H
#define HUFFMAN_NAIVE_C11_FUNCTIONS_H

#include <stdio.h>

/**
 *
 * @param target
 * @return
 */
int get_file_size(FILE* target);

/**
 *
 * @param target
 * @param newExtension
 */
void change_extension(char *target,
                      char *newExtension,
                      char *original,
                      int size);

/**
 *
 * @param target
 */
void txtToBinairies(char* target);

/**
 *
 * @param original
 * @param target
 * @return
 */
int compare(char* original, char* target);

#endif //HUFFMAN_NAIVE_C11_FUNCTIONS_H