/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

struct Winner{
	int annee;
	char* nom;
	char* description;
};
typedef struct Winner winner;


void printWinners(winner *tab,int nombreGagnants){
for(int i=0;i<nombreGagnants;i++){
	printf("Winner Year : %i\n",tab[i].annee);
		printf("%s\n",tab[i].nom);
		printf("%s\n",tab[i].description);
}
}
void infosAnnee(winner **tab){
	int anne;
	printf("Donner l'annee voulu:");
	scanf("%i\n",&anne);
		for(int i=0;i<50;i++){
			if(anne==(tab[0]+i)->annee){
				printf("Winner Year : %i\n",tab[anne]->annee);
		printf("%s\n",tab[anne]->nom);
		printf("%s\n",tab[anne]->description);
			}
	}
}
void readWinner(winner **tab,int nombreGagnants){
	(*tab)=calloc(nombreGagnants,sizeof(winner));
	for(int i=0;i<=nombreGagnants;i++){
		(tab[0]+i)->annee=scanLineAsInt();
		(tab[0]+i)->nom=scanLine();
		(tab[0]+i)->description=scanLine();
	}
}

int main(void)
{	int nbGagnants = scanLineAsInt();
	winner *tab;
	readWinner(&tab,nbGagnants);
	printWinners(tab,nbGagnants);
	infosAnnee(&tab);
	//free(tab);
	return EXIT_SUCCESS;
}
