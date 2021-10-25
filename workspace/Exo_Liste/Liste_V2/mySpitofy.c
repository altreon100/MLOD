#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

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