#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "userInterface.h"


void shell_tdz()
{
    custom_color("          \\/\n          /\\\n         /  \\\n        /    \\\n       /      \\\n      /        \\\n     /          \\\n    /     /\\     \\\n   /     /  \\     \\\n  /     /    \\     \\\n", "yellow");
    printf("\n\n");
    printf("| tdz present |\n\n");

}

#ifdef _WIN32

void custom_color(char* str, char* color)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!strcmp(color, "red")){
        SetConsoleTextAttribute(hStdOut, (FOREGROUND_RED));
    }else if(!strcmp(color, "green")){
        SetConsoleTextAttribute(hStdOut, (FOREGROUND_GREEN));
    }else if(!strcmp(color, "blue")){
        SetConsoleTextAttribute(hStdOut, (FOREGROUND_BLUE));
    }else if(!strcmp(color, "black")){
        SetConsoleTextAttribute(hStdOut, 0);
    }else if(!strcmp(color, "white")){
        SetConsoleTextAttribute(hStdOut, 15);
    }else if(!strcmp(color, "magenta")){
        SetConsoleTextAttribute(hStdOut, (FOREGROUND_RED | FOREGROUND_BLUE));
    }else if(!strcmp(color, "cyan")){
        SetConsoleTextAttribute(hStdOut, (FOREGROUND_GREEN | FOREGROUND_BLUE));
    }else if(!strcmp(color, "yellow")){
        SetConsoleTextAttribute(hStdOut, (FOREGROUND_GREEN | FOREGROUND_RED));
    }else{
        SetConsoleTextAttribute(hStdOut, (((int) *color) - 48));
    }
    printf("%s", str);
    SetConsoleTextAttribute(hStdOut, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED));
}
#elif unix
/**
 * custom_color : function that display given text with the given color
 * @param str : text we want to display
 * @param color : wanted color (string or string with at [0] a number)
 */
void custom_color(char* str, char* color)
{
    if (!strcmp(color, "red")){
        printf("\033[0;31m");
    }else if(!strcmp(color, "green")){
        printf("\033[0;32m");
    }else if(!strcmp(color, "blue")){
        printf("\033[0;34m");
    }else if(!strcmp(color, "black")){
        printf("\033[1;33m");
    }else if(!strcmp(color, "white")){
        printf("\033[0m;");
    }else if(!strcmp(color, "magenta")){
        printf("\033[0;35m");
    }else if(!strcmp(color, "cyan")){
        printf("\033[0;36m");
    }else if(!strcmp(color, "yellow")){
        printf("\033[0;33m");
    }else{
        // later
        //TODO : strcat for custom color
    }
    printf("%s", str);
    printf("\033[0m;");
}
#endif

void getLine(FILE *fp, int size, char *output)
{
    fgets(output, size, stdin); output[size-1] = '\0';
    int i = 0;
    for (i = 0; output[i] != '\n'; i++);
    output[i] = '\0';
    fflush(fp);
}

void cin(int size, char *output)
{
    getLine(stdin, size, output);
}

int menu(int size, ...)
{
    // getting the input answer
    char answer[9];
    fgets(answer, 9, stdin); answer[8] = '\0'; int maxsize;
    for(maxsize = 0; answer[maxsize] != '\n' && answer[maxsize] != '\0'; maxsize++);answer[maxsize] = '\0';
    fflush(stdin);

    int result = -1;
    va_list args;
    MenuComponent* buffer = 0;

    va_start(args, size);
    for(int i = 0; i < size; i++)
    {
        buffer = va_arg(args, MenuComponent*);
        if(!strcmp(answer, buffer->name)){
            result = buffer->returnValue;
            va_end(args);
            return result;
        }
    }
    return result;
}
