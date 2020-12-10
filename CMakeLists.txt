cmake_minimum_required(VERSION 3.17)
project(huffman_project C)

set(CMAKE_C_STANDARD 11)

add_executable(huffman_project
        source/main.c

        source/files/compression/compression.c

        source/files/stack/Stack.c
        source/files/stack/Stack.h

        source/files/dico/dictionnary.c
        source/files/dico/dictionnary.h

        source/files/HT/HuffmanTree.c
        source/files/HT/HuffmanTree.h

        source/files/SLL/Element.c
        source/files/SLL/Element.h

        source/files/fstream/functions.h
        source/files/fstream/functions.c

        source/files/UI/userInterface.h
        source/files/UI/userInterface.c
        )
