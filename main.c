#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dsymec.h"

main(int argc, char *argv[]){
    if(strcmp(argv[1], "--help") == 0){
        printf("Usage: dctor [OPTION]... [FILES]...\nEncrypt or decrypt files and text write it in or print it out.\n -[Action(E/D)][Source(t/f)][Output(t/f)]\n\n -Ett: Encrypt a text and print it out.\n -Dtt: Decrypt a text and print it out.\n -Eff: Encrypt a file and write the changes in.\n -Dff: Decrypt a file and write in the changes.\n -Eft: Encrypt a file and print it out.\n -Dft: Decrypt a file and print it out.\n -Etf: Encrypt a text message and write it in.\n -Dtf: Decrypt a text and write it in.\n");
        exit(0);
    }
    tempascii = (int*) malloc(sizeof(int) * (2000));

    if(strcmp(argv[1], "-Ett") == 0){
        getkey();
        charlen = inputlen();
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        shiftrow1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        xor2(ptrascii, (charlen) - (charlen % 4));

        for(int element = 0; element < charlen; element++){
            printf("%c", *(ptrascii + element));
        }
        printf("\n");

        for(int element = 0; element < charlen; element++){
            printf("%d ", *(ptrascii + element));
        }

        printf("\n");
    }else if(strcmp(argv[1], "-Dtt") == 0){
        getkey();
        charlen = inputlen();
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        xor2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        shiftrow1(ptrascii, (charlen) - (charlen % 4));

        for(int element = 0; element < charlen; element++){
            printf("%c", *(ptrascii + element));
        }
        printf("\n");

        for(int element = 0; element < charlen; element++){
            printf("%d ", *(ptrascii + element));
        }

        printf("\n");
    }else if(strcmp(argv[1], "-Eff") == 0){
        getkey();
        charlen = inputfilelen(argv[2]);
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        shiftrow1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        xor2(ptrascii, (charlen) - (charlen % 4));

        filewrite(argv[2], ptrascii, charlen);
    }else if(strcmp(argv[1], "-Dff") == 0){
        getkey();
        charlen = inputfilelen(argv[2]);
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        xor2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        shiftrow1(ptrascii, (charlen) - (charlen % 4));

        filewrite(argv[2], ptrascii, charlen);
    }else if(strcmp(argv[1], "-Eft") == 0){
        getkey();
        charlen = inputfilelen(argv[2]);
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        shiftrow1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        xor2(ptrascii, (charlen) - (charlen % 4));

        for(int element = 0; element < charlen; element++){
            printf("%c", *(ptrascii + element));
        }
        printf("\n");

        for(int element = 0; element < charlen; element++){
            printf("%d ", *(ptrascii + element));
        }

        printf("\n");
    }else if(strcmp(argv[1], "-Dft") == 0){
        getkey();
        charlen = inputfilelen(argv[2]);
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        xor2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        shiftrow1(ptrascii, (charlen) - (charlen % 4));

        for(int element = 0; element < charlen; element++){
            printf("%c", *(ptrascii + element));
        }
        printf("\n");

        for(int element = 0; element < charlen; element++){
            printf("%d ", *(ptrascii + element));
        }

        printf("\n");
    }else if(strcmp(argv[1], "-Etf") == 0){
        getkey();
        charlen = inputlen();
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        shiftrow1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        xor2(ptrascii, (charlen) - (charlen % 4));

        filewrite(argv[2], ptrascii, charlen);
    }else if(strcmp(argv[1], "-Dtf") == 0){
        getkey();
        charlen = inputlen();
        ptrascii = (int*) malloc(sizeof(int) * charlen);
        fill(ptrascii);
        free(tempascii);

        xor2(ptrascii, (charlen) - (charlen % 4));
        xor1(ptrascii, (charlen) - (charlen % 4));
        shiftrow2(ptrascii, (charlen) - (charlen % 4));
        shiftrow1(ptrascii, (charlen) - (charlen % 4));

        filewrite(argv[2], ptrascii, charlen);
    } else{
        printf("Unknown Option\nTry 'dctor --help' for more info.\n");
    }
}
