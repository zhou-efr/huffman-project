//
// Created by zhou on 18/11/2020.
//

#include "functions.h"

int get_file_size(FILE* file_target)
{
    fseek(file_target, 0L, SEEK_END);
    int size = ftell(file_target);
    fseek(file_target, 0L, SEEK_SET);
    return size;
}

void change_extension(char *target, char *newExtension, char *original, int size)
{
    for (int j = 0; j < size; j++) {
        if (original[j] == '.'){
            target[j] = original[j];
            for (int i = 0; i < 3; ++i) {
                target[j+i+1] = newExtension[i];
            }
            target[j+4] = '\0';
            break;
        }else{
            target[j] = original[j];
        }
    }
}

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

int compare(char* original, char* target)
{
    FILE *file_original = fopen(original, "r"),
         *target_file = fopen(target, "r");

    if (!file_original)
    {
        if (target_file) fclose(target_file);
        return 2;
    }

    if (!target_file)
    {
        fclose(file_original);
        return 3;
    }

    int ch1 = 0, ch2 = 0;

    while (ch1 != EOF && ch2 != EOF)
    {
        if (ch1 != ch2)
        {
            fclose(file_original);
            fclose(target_file);
            return 1;
        }
        ch2 = fgetc(file_original);
        ch1 = fgetc(target_file);
    }

    if (ch1 == ch2) return 0;

    fclose(file_original);
    fclose(target_file);
    return 1;
}
