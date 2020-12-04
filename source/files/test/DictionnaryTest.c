#include <stdio.h>
#include "../dico/dictionnary.h"

int main()
{
    /*   must create a huffman tree named "huff" here which include somwhere the letter 'a'   */
    Dico* dictionary = htreetodico(huff);
    printf("%s", get_value(dictionary, 'a'));
    saveDictionary(dictionary);
    system("pause");

    /*   must create a node named "node" here   */
    dictionary = slltodico(node);
    saveDictionary(dictionary);
    
    d_free(dictionary);


    /* Result wanted :
     * print the corresponding code of the letter 'a'
     * write in dictionary.txt the dictionnary coresponding to the huffman tree
     * write in dictionary.txt after the pause the dictionnary coresponding to the node
    */
}