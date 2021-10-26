#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

//gcc -W -Wall LinkedList.c mySpitofy.c linkedListOfMusic.c  -o mySpitofy
int main(){
	Liste l;

	l = NULL;
     FILE* f;
    f = fopen("music.csv","r");
	//printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	l=readFile(f);
	afficheListe_i(l);
	//detruire_i(l);
    fclose(f);
    return EXIT_SUCCESS;
}