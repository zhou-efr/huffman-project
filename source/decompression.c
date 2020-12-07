#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "decompression.h"
#include "files/fstream/functions.h"
#include "files/dico/dictionnary.h"

void uncompress(char* target, Tree* arbre)
{
    FILE* binaries = NULL;
    binaries = fopen(target, "r");

    if(!binaries)
        return;

    char* outputPath = (char*)malloc(300*sizeof(char));
    int strSize = strlen(target);
    for (int j = 0; j < strSize; j++) {
        if (target[j] == '.'){
            outputPath[j] = target[j];
            outputPath[j+1] = 't';
            outputPath[j+2] = 'x';
            outputPath[j+3] = 't';
            outputPath[j+4] = '\0';
            break;
        }else{
            outputPath[j] = target[j];
        }
    }

    FILE* output = NULL;
    output = fopen(outputPath, "w");

    char ch = '\0';
    Tree* searcher = arbre;

    while ((ch = fgetc(binaries)) != EOF)
    {
        if (!hasSons(searcher))
        {
            fputc(searcher->data, output);
            searcher = arbre;
        }

        if(isZero(ch)){
            searcher = searcher->left;
        }else{
            searcher = searcher->right;
        }
    }

    if (!hasSons(searcher))
    {
        fputc(searcher->data, output);
        searcher = arbre;
    }

    fclose(binaries);
    fclose(output);
}

int isZero(char a)
{
    return a == '0';
}

/**
 * This fucntion decompresses a given file thanks to a given HT
 * @param target is the file we want to decompress
 * @param tree is the key tree
 */
void b_decompression(char *target, Tree *tree)
{
    FILE* binaries = NULL;
    binaries = fopen(target, "rb");

    if(!binaries)
        return;

    FILE* output = NULL;
    output = fopen("output.txt", "w");

    char ch = '\0';
    Tree* searcher = tree;

    // TODO : test and correct

    // overbytes size
    fread(&ch, sizeof(char), 1, binaries);
    int bsize = (int)ch;
    ch = '\0';

    //get file size
    int f_size = get_file_size(binaries);

    // iterator
    int i = 0;

    while (ch != EOF && i < (f_size - bsize))
    {
        fread(&ch, sizeof(char), 1, binaries);
        i++;

        if (!hasSons(searcher))
        {
            //printf("%c", searcher->data);
            fputc(searcher->data, output);
            searcher = tree;
        }

        if(ch){
            searcher = searcher->right;
        }else{
            searcher = searcher->left;
        }
    }

    if (!hasSons(searcher))
    {
        fputc(searcher->data, output);
        searcher = tree;
    }

    fclose(binaries);
    fclose(output);
}