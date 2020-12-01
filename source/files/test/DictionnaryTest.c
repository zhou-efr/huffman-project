#include <stdio.h>
#include "../dico/dictionnary.h"

int main()
{
    Dico* test = (Dico*)malloc(sizeof(Dico));

    test->key = 'b';
    test->value = '000101';
    test->right = (Dico*)malloc(sizeof(Dico));
    test->left = (Dico*)malloc(sizeof(Dico));
    test->right->key = 'a';
    test->right->value = '110';
    test->right->right = NULL;
    test->right->left = NULL;
    test->left->key = 'c';
    test->left->value = '011';
    test->left->right = NULL;
    test->left->left = NULL;

    saveDictionary(test);

    free(test->right);
    free(test->left);
    free(test);
}