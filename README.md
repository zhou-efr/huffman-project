# huffman-project
![C](https://img.shields.io/badge/version-v1.0.1-success?style=for-the-badge)
![C](https://img.shields.io/badge/language-C-blue?style=for-the-badge)

##Table of contents
- [installation](#installation)
- [usage](#usage)
- [Authors](#authors)

##Iinstallation
###To use the compressor
Download the `build/huffman_project.exe` file and execute it.
###To modify the compressor
####With Clion
Create a new project with `get from version control` and copy paste the https address 
(https://github.com/zhou-efr/huffman-project.git). Then go to `File/New CMake Project from Sources...` 
and select the folder containing the cloned repository.
##Usage
###Purpose
The point of the software is to find a way to compress a file in the most optimized way. By compressing we mean reducing the size of the file and by the most optimized way it means that the compression must adapt to the file. When it’s done, the software is able to decompress it if we want to read it.  
###Use the software: 
To use the software, you must launch the file “huffman_project.exe” :
###Compress a file: 
Once you pressed execute it, you must choose the option “Compress”. Then, you must write the path to get access to the file.
![menu](https://i.ibb.co/cTmWw4C/exa1.png)
![path](https://i.ibb.co/C8gPPF2/Exa2.png)
###Where is the compressed file stocked? 
The compressed file will be stocked into the same folder as the file you wanted it to be compressed. You’ll find next to it, a new file used as the key to decompress the file ending in “.zdd”.  
###Decompress a file: 
To decompress a file, you must execute the file again. Then, choose the “Decompress” option. Finally, you write the path to the file you want the decompression of. Make sure the “dico.txt” is in the same folder.  
![path](https://i.ibb.co/4pr2NRz/Exa3.png)
###Where is the decompressed file? 
The decompressed file will be stocked into the folder you put when answering “write the path of the output file name & path”. While writing the path you must choose a new name for your new file, be careful.
##Authors
- Marin-Pierre Babin
- Hugo Chamillard
- Guerric le Bihan
- Camille Sosso
- Killian Zhou.   