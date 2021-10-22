#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

void afficheElement(Element e){
    printf("%s",(char*)e);
}

void detruireElement(Element e){

}

bool equalsElement(Element e1,Element e2){
    return strcmp((char *)e1,(char *)e2)==0;
}
int main(void){
	Liste l;
	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
 
	l = ajoutTete("2023",l);
	l = ajoutTete(" FISE",l);
	l = ajoutTete("E",l);
	l = ajoutTete("C",l);
	l = ajoutTete("N",l);
	l = ajoutTete("E",l);
	l = ajoutTete("X",l);
	l = ajoutTete("A",l);
	l = ajoutTete("M",l);
	afficheListe_i(l);
    detruire_r(l);
	return EXIT_SUCCESS;
}