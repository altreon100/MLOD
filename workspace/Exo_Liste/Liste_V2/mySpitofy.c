#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

//gcc -W -Wall LinkedList.c mySpitofy.c linkedListOfMusic.c  -o mySpitofy
// ./mySpitofy >out.csv
// diff music.csv out.csv
//out.csv= fichier non trié  out.txt=fichier trié par année
int main(){
	Liste l;
	l = NULL;
    FILE* f;
    f = fopen("music.csv","r");
	l=readFile(f);
	triYear(l);
	afficheListe_i(l);
	detruire_i(l);
    fclose(f);
    return EXIT_SUCCESS;
}