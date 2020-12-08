//
// Created by thepa on 07/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compression.h"
#include "decompression.h"
#include "files/UI/userInterface.h"

void txtToBinairies(char* target)
{
    FILE* file_target = NULL, *file_output = NULL;
    file_target = fopen(target, "r");
    if(!file_target)
        return;

    file_output = fopen("./output.bin", "w");

    char ch = 0;
    while((ch = fgetc(file_target)) != EOF)
    {
        for (int i = 7; i >= 0; i--) {
            fprintf(file_output, ((ch >> i) & 1)?"1":"0");
        }
    }

    fclose(file_target);
    fclose(file_output);
}

int main()
{
    shell_tdz();

    MenuComponent compression = {"compress", 1},
                  decompression = {"decompress", 2},
                  quit = {"quit", 3},
                  debug = {"debug", 4},
                  compressionNumber = {"2", 1},
                  decompressionNumber = {"3", 2},
                  quitNumber = {"1", 3};

    int ready = 0;

    while (!ready) {
        printf("\nCompressor\n\t1- ");
        custom_color("\"quit\"", "red");
        printf(" to quit,\n\t2- ");
        custom_color("\"compress\"", "cyan");
        printf(" to compress a file,\n\t3- ");
        custom_color("\"decompress\"", "cyan");
        printf(" to decompress a file\n");

        ready = menu(7,
                     &quit,
                     &compression,
                     &decompression,
                     &compressionNumber,
                     &decompressionNumber,
                     &quitNumber,
                     &debug);
    }
    char* path, *pathDico,*outPath;

    switch (ready) {
        case 1:
            printf("\n");
            printf("write the path of the target file\n");
            path = cin(300);

            if (b_compression(path))
            {
                custom_color("\n404 error file not found", "mangenta");
                system("pause");
            }else{
                custom_color("\nsuccess\n", "green");
                system("pause");
            }
            free(path);
            break;
        case 2:
            printf("\n");
            printf("write the path of the compressed file\n");
            path = cin(300);
            printf("write the path of the dictionary file\n");
            pathDico = cin(300);
            printf("write the path of the output file name & path\n");
            outPath = cin(300);


            if(uncompressChar(path, pathDico, outPath))
            {
                custom_color("\n404 error file not found", "mangenta");
                system("pause");
            }else{
                custom_color("\nsuccess\n", "green");
                system("pause");
            }

            free(path);
            free(pathDico);
            break;
        case 4:
            printf("translation of the original file\n");
            txtToBinairies("a.txt");
            printf("compression\n");
            clock_t start = clock();
            if (b_compression("a.txt"))
            {
                custom_color("\n404 error file not found", "mangenta");
                system("pause");
            }else{

                clock_t stop = clock();
                double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
                printf("\nExecution time : %.5f\n", elapsed);

                custom_color("\nsuccess\n", "green");
                system("pause");

                printf("decompression\n");
                start = clock();
                if(uncompressChar("a.tdz", "a.zdd", "output.txt"))
                {
                    custom_color("\n404 error file not found", "mangenta");
                    system("pause");
                }else{
                    stop = clock();
                    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
                    printf("\nExecution time : %.5f\n", elapsed);

                    custom_color("\nsuccess\n", "green");
                    system("pause");
                }
            }
            break;
    }
    return 0;
}