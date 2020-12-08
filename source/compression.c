#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "compression.h"
#include "files/fstream/functions.h"
#include "files/dico/dictionnary.h"
#include "decompression.h"
#include "files/HT/HuffmanTree.h"

/**
 * This function compresses a given file
 * @param target is the file we want to compress
 */
int b_compression(char *target)
{
    // --- file read ---
    // file variables
    FILE* input = fopen(target, "r"); if (!input) return 1;
    int size = get_file_size(input)+1;

    // text variables
    char* transcription = (char*)malloc(size*sizeof(char));
    char ch = '\0';

    // iterator
    int i = 0;

    // character list
    Tree* occurrences = NULL;

    //file read
    while ((ch = fgetc(input)) != EOF)
    {
        //printf("%c : %d \n", ch, ch);

        // update transcription
        transcription[i] = ch;
        i++;

        // update list
        add_occurrences(&occurrences, ch);
    }

    // end the file transcription
    transcription[i] = '\0';

    // close file
    fclose(input);

    // list to dictionary
    Element* HS = BT_to_UT(occurrences);
    SLL_to_HT(&HS);
    Tree* HT = HS->node;
    Dico* dictionary = htreetodico(HT, occurrences);

    // temporary
    //Tree* h_tree = sort_SLL_to_BT(list);
    // free SLL
    free_SLL(HS);

    // --- compression ---

    /* Available Variables
     * Dico Dictionary
     * int size
     * char* transcription
     * char ch
     * int i
     * */

    char* outputPath = (char*)malloc(300*sizeof(char));
    int strSize = strlen(target);
    for (int j = 0; j < strSize; j++) {
        if (target[j] == '.'){
            outputPath[j] = target[j];
            outputPath[j+1] = 't';
            outputPath[j+2] = 'd';
            outputPath[j+3] = 'z';
            outputPath[j+4] = '\0';
            break;
        }else{
            outputPath[j] = target[j];
        }
    }

    FILE* output = fopen(outputPath, "w");


//    // file variable
//    FILE* output = fopen("output.tdz", "wb");
//
//    // temporary variables
//    char* temp_bin = NULL;
//    int temp_bit = 0;
//
//    // binary size
//    int bsize = 0;
//
//    printf()
//
    i = 0;
    while (i <= size)
    {
//        // write in file
//            temp_bin = get_value(dictionary, transcription[i]);
//        //printf("%c", transcription[i]);
//        //printf("|%c\n", transcription[i]);
//        for (int j = 0; temp_bin[j] != '\0'; j++)
//        {
//            //printf("%c", temp_bin[j]);
//            temp_bit = (temp_bin[j] == '1');
//            fwrite(&temp_bit, 1, 1, output);
//            bsize++;
//        }

        fprintf(output, get_value(dictionary, transcription[i]));

        // iterator update
        i++;
    }
//
//    // TODO: add the over byte system (integer)
//    bsize = (bsize%8)?(8-(bsize%8)):0;
//    ch = (char)bsize;
//    temp_bit = 0;
//    for (int j = 0; j < bsize; j++)
//    {
//        fwrite(&temp_bit, 1, 1, output);
//    }
//    fseek(output, 0L, SEEK_SET);
//    fwrite(&ch, sizeof(char), 1, output);

    // close file
    fclose(output);

    // temporary
    saveDictionary(dictionary);

    // free variables
    free(transcription);
    d_free(dictionary);

    outputPath = (char*)malloc(300*sizeof(char));
    for (int j = 0; j < strSize; j++) {
        if (target[j] == '.'){
            outputPath[j] = target[j];
            outputPath[j+1] = 'z';
            outputPath[j+2] = 'd';
            outputPath[j+3] = 'd';
            outputPath[j+4] = '\0';
            break;
        }else{
            outputPath[j] = target[j];
        }
    }
    output = fopen(outputPath, "w");

    //save tree
    register_tree(output, HT);

    //reclose file
    fclose(output);

    // free temporary
    t_free(HT);

    return 0;
}
