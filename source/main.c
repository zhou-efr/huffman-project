//
// Created by thepa on 07/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "files/compression/compression.h"
#include "files/UI/userInterface.h"
#include "files/fstream/functions.h"
#ifdef unix
#include <unistd.h>
#endif

int main()
{
    shell_tdz();

    MenuComponent component_compression = {"compress", 1},
                  component_decompression = {"decompress", 2},
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
                     &component_compression,
                     &component_decompression,
                     &compressionNumber,
                     &decompressionNumber,
                     &quitNumber,
                     &debug);
    }

    char path[300], pathDico[300], outPath[300];

    switch (ready) {
        case 1:
            printf("\n");
            printf("write the path of the target file\n");
            cin(300, path);

            if (compression(path))
            {
                custom_color("\n404 error file not found", "mangenta");
            }else{
                custom_color("\nsuccess\n", "green");
            }
            break;
        case 2:
            printf("\n");
            printf("write the path of the compressed file\n");
            cin(300, path);
            printf("write the path of the dictionary file\n");
            cin(300, pathDico);
            printf("write the path of the output file name & path\n");
            cin(300, outPath);


            if(decompression(path, pathDico, outPath))
            {
                custom_color("\n404 error file not found\n", "mangenta");
            }else{
                custom_color("\nsuccess\n", "green");
            }
            break;
        case 4:
            printf("translation of the original file\n");
            txtToBinairies("a.txt");
            printf("component_compression\n");
            clock_t start = clock();
            if (compression("a.txt"))
            {
                custom_color("\n404 error file not found\n", "mangenta");
            }else{

                clock_t stop = clock();
                double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
                printf("\nExecution time : %.5f\n", elapsed);

                custom_color("\nsuccess\n", "green");

                printf("decompression\n");
                start = clock();
                if(decompression("a.tdz", "a.zdd", "output.txt"))
                {
                    custom_color("\n404 error file not found\n", "mangenta");
                }else{
                    stop = clock();
                    elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
                    printf("\nExecution time : %.5f\n", elapsed);

                    custom_color("\nsuccess\n", "green");

                    switch (compare("a.txt", "output.txt"))
                    {
                        case 1:
                            custom_color("\nError : output different from the input\n", "red");
                            break;
                        case 2:
                            custom_color("\n404 Error : input not found\n", "magenta");
                            break;
                        case 3:
                            custom_color("\n404 Error : output not found\n", "magenta");
                            break;
                        default:
                            custom_color("\ninput identical to output\n", "green");
                            FILE *file_original = fopen("output.bin", "r"),
                                 *target_file = fopen("a.tdz", "r");
                            double ratio = ((double)get_file_size(target_file))/((double)get_file_size(file_original));
                            if (ratio > 1) {
                                custom_color("\nWarning: compression inefficient\n", "yellow");
                            }
                            printf("\ncompression ratio : %lf%%\n", ratio*100);
                            fclose(file_original);
                            fclose(target_file);
                    }
                }
            }
            break;
        default:
            custom_color("\nerror, missed input\n", "red");
    }
    #ifdef WIN32
    system("pause");
    #elif unix
    pause();
    #endif
    return 0;
}