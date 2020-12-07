#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "decompression.h"
#include "files/fstream/functions.h"
#include "files/dico/dictionnary.h"


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