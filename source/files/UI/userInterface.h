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

void HNC_help();
void custom_color(char* str, char* color);
char *cin(int size);
char *getLine(FILE *fp, int size);
int menu(int size, ...);
int marin_pierre_babin();
void title();
void shell_tdz();

#endif //HUFFMAN_PROJECT_USERINTERFACE_H
