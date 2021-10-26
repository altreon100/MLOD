#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include<string.h>

// Definition des fonctions spécifiques à l'élément pour les chaines
void afficheElement(Element e)
{
    Music *music = (Music*)e;
    printf("%s,",music->name);
    printf("%s,",music->artist);
    printf("%s,",music->album);
    printf("%s,",music->genre);
    if(music->discNumber==0)
        printf(",");
    else
        printf("%i,",music->discNumber);
    printf("%i,",music->trackNumber);
    printf("%i",music->year);
    printf("\n");
}

void detruireElement(Element e)
{
   Music *m=(Music*)e;
    free(m);
}

bool equalsElement(Element e1, Element e2)
{
    Music *m1 = (Music*) e1;
    Music *m2 = (Music*) e2;
    bool res=(strcmp(m1->name,m2->name)==0);
	if(res!=0)
		res=(strcmp(m1->artist,m2->artist)==0);
	if(res!=0)
		res=(strcmp(m1->album,m2->album)==0);
	if(res!=0)
		res=(strcmp(m1->genre,m2->genre)==0);
	if(res!=0)
		res=(m1->discNumber==m2->discNumber);
	if(res!=0)
		res=(m1->trackNumber==m2->trackNumber);
	if(res!=0)
		res=(m1->year==m2->year);
	return res;

}

Music* ReadLine( char* ligne)
{
    Music* m =malloc(sizeof(Music));
    char* line=strdup(ligne);
    m->name=strsep(&line,",");
	m->artist=strsep(&line,",");
    m->album=strsep(&line,",");
    m->genre=strsep(&line,",");
    m->discNumber = atoi( strsep(&line,","));
    m->trackNumber = atoi( strsep(&line,","));
    m->year = atoi( strsep(&line,","));
	return m;
}

Liste readFile(FILE *fichier)
{
	Liste l = NULL;
	char *ligne=malloc(sizeof(char)*255);
    fgets(ligne,255,fichier);
	char *firstLine=strdup(ligne);
	printf("%s",firstLine);
	while(fgets(ligne,255,fichier)!=NULL)
        l=ajoutFin_i(ReadLine(ligne),l);
    
    return l;
}

Liste triYear(Liste l)
{
    if(l==NULL)
        return NULL;
    Liste new  = l;
    Liste suiv = NULL;
    while(!estVide(new))
    {
        suiv = new->suiv;
        while(!estVide(suiv))
        {
            if( ((Music*)(suiv->val))->year < ((Music*)(new->val))->year)
            {
                void *transition;
                transition = suiv->val;
                suiv->val = new->val;
                new->val = transition;
            }
            suiv = suiv->suiv;
        }
        new = new->suiv;
    }
    return l;
}