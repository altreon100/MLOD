#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


// Defnition des fonctions et structures spécifiques à l'élément
struct Music{
    char* name;
    char* artist;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int year;
};

typedef struct Music Music;
Liste readFile(FILE *fichier);
Music* ReadLine(FILE* fichier, char* ligne);