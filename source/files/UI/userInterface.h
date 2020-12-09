//
// Created by thepa on 07/12/2020.
//

#ifndef HUFFMAN_PROJECT_USERINTERFACE_H
#define HUFFMAN_PROJECT_USERINTERFACE_H

/**
 * _MenuComponent structure
 */
typedef struct _MenuComponent
{
    char* name; /**< binded name */
    int returnValue; /**< value return if component triggered */
}MenuComponent;

/**
 * custom_color : function that display given text with the given color
 * @param str : text we want to display
 * @param color : wanted color (string or string with at [0] a number)
 */
void custom_color(char* str, char* color);

/**
 *
 * @param size
 * @return
 */
void cin(int size, char *output);

/**
 *
 * @param fp
 * @param size
 * @return
 */
void getLine(FILE *fp, int size, char *output);

/**
 * menu : bind a menu with the given component
 * @param size : number of component
 * @param ... : component
 * @return the return value of the selected component (if no component selected return -1)
 */
int menu(int size, ...);

/**
 *
 */
void shell_tdz();

#endif //HUFFMAN_PROJECT_USERINTERFACE_H
