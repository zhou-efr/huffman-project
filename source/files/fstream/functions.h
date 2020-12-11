//
// Created by zhou on 18/11/2020.
//

#ifndef HUFFMAN_NAIVE_C11_FUNCTIONS_H
#define HUFFMAN_NAIVE_C11_FUNCTIONS_H

#include <stdio.h>

/**
 * get_file_size : return the size of a function
 * @param target : target file
 * @return size of the file
 */
int get_file_size(FILE* target);

/**
 * change_extension : change the extension (3 char) of a string and put it in another string
 * @param target : string which will be changed
 * @param newExtension : new extension (3 characters)
 * @param original : original string
 * @param size : size of the original string
 */
void change_extension(char *target,
                      char *newExtension,
                      char *original,
                      int size);

/**
 * txtToBinairies : create a file with the binary transcription of the target file
 * @param target : string path to the target file
 */
void txtToBinairies(char* target);

/**
 * compare : compare 2 files
 * @param original : path of the first file
 * @param target : path of the second file
 * @return : 0 if same, 1 if different, 2 if file 1 doesn't exist, 3 if file 2 doesn't exist
 */
int compare(char* original, char* target);

#endif //HUFFMAN_NAIVE_C11_FUNCTIONS_H
