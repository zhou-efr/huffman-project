#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "function.h"
#include "../fstream/functions.h"
#include "../dico/dictionnary.h"

/**
 * This function compresses a given file
 * @param target is the file we want to compress
 */
void b_compression(char *target)
{
    // --- file read ---
    // file variables
    FILE* input = fopen(target, "r"); if (!input) return;
    int size = get_file_size(input);

    // text variables
    char* transcription = (char*)malloc(size*sizeof(char));
    char ch = '\0';

    // iterator
    int i = 0;

    // character list
    Element* list = NULL;

    //file read
    while ((ch = fgetc(input)) != EOF)
    {
        //printf("%c : %d \n", ch, ch);

        // update transcription
        transcription[i] = ch;
        i++;

        // update list
        add_occurrence(&list, ch);
    }

    // end the file transcription
    transcription[i] = '\0';

    // close file
    fclose(input);

    // list to dictionary
    Dico* dictionary = slltodico(list);

    // temporary
    //Tree* h_tree = sort_SLL_to_BT(list);
    // free SLL
    free_SLL(list);

    // --- compression ---

    /* Available Variables
     * Dico Dictionary
     * int size
     * char* transcription
     * char ch
     * int i
     * */

    // file variable
    FILE* output = fopen("output.tdz", "wb");

    // temporary variables
    char* temp_bin = NULL;
    int temp_bit = 0;

    // binary size
    int bsize = 0;

    i = 0;
    while (i <= size)
    {
        // write in file
        temp_bin = get_value(dictionary, transcription[i]);
        for (int j = 0; temp_bin[j] != '\0'; j++)
        {
            temp_bit = (temp_bin[j] == '1');
            fwrite(&temp_bit, 1, 1, output);
            bsize++;
        }

        // iterator update
        i++;
    }

    // TODO: add the over byte system (integer)
    bsize = (bsize%8)?(8-(bsize%8)):0;
    ch = (char)bsize;
    temp_bit = 0;
    for (int j = 0; j < bsize; j++)
    {
        fwrite(&temp_bit, 1, 1, output);
    }
    fseek(output, 0L, SEEK_SET);
    fwrite(&ch, sizeof(char), 1, output);

    // close file
    fclose(output);

    // temporary
    //saveDictionary(dictionary);

    // free variables
    free(transcription);
    d_free(dictionary);

    //b_decompression("output.tdz", h_tree);

    // free temporary
    //t_free(h_tree);
}
