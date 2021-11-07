#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) 
{
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) 
{
	ArbreBinaire a;
	a=malloc(sizeof(Noeud));
	a->val=e;
	initialiser(&a->filsGauche);
	initialiser(&a->filsDroit);
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) 
{
	ArbreBinaire new=a;
	if(estVide(a))
		return creer(e);
	while(!estVide(new) && new->val!=e)
	{
		if(new->val>e)
		{
			if(estVide(new->filsGauche))
			{
				new->filsGauche=creer(e);
				return a;
			}
			new=new->filsGauche;
		}
		else 
		{
			if(estVide(new->filsDroit))
			{
				new->filsDroit=creer(e);
				return a;
			}
			new=new->filsDroit;
		}
	}
	return a;
}
// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e)
{
	if (estVide(a))
		return creer(e);
	else
	{
		if(e<a->val)
			a->filsGauche=insere_r(a->filsGauche,e);
		else if(e>a->val)
			a->filsDroit=insere_r(a->filsDroit,e);
		return a;
	}
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a)
{
	if (estVide(a))
		return 0;
	return (1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit));
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e)
{
	if(estVide(a))
		return -1;
	if(a->val==e)
		return 0;
	if(profondeur(a->filsDroit,e)<profondeur(a->filsGauche,e))
		return profondeur(a->filsGauche,e)+1;
	if (profondeur(a->filsDroit,e)>profondeur(a->filsGauche,e))
		return profondeur(a->filsDroit,e)+1;
	return -1;
}
// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
	if(estVide(a))
		return 0;
	int hauteur_Gauche=hauteur(a->filsGauche);
	int hauteur_Droite=hauteur(a->filsDroit);
		if(hauteur_Droite>hauteur_Gauche)
			return hauteur_Droite+1;
		else
			return hauteur_Gauche+1;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{
	if(estVide(a))
		return NULL;
	if(!estVide(a->filsGauche))
	{
		if(a->filsGauche->val==elem)
			return a;
	}
	if(!estVide(a->filsDroit))
	{
		if(a->filsDroit->val==elem)
			return a;
	}
	if(a->val==elem)
		return NULL;
	if(elem<a->val)
		return pere(a->filsGauche,elem);
	if(elem>a->val)
		return pere(a->filsDroit,elem);
	return a;
}


void afficheRGD_r(ArbreBinaire a)
{
	if(!estVide(a))
	{
		printf("%d",a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}


void afficheGRD_r(ArbreBinaire a)
{
	if(!estVide(a))
	{
		afficheGRD_r(a->filsGauche);
		printf("%d",a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a))
	{
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		printf("%d",a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
	if(estVide(a))
		return NULL;
	if(estVide(a->filsGauche))
		return a;
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
	if(estVide(a))
		return NULL;
	if(estVide(a->filsDroit))
		return a;
	return max(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem)
{
	if(estVide(a))
		return NULL;
	if(elem==a->val)
		return a;
	if(elem<a->val)
		return recherche_r(a->filsGauche,elem);
	else
		return recherche_r(a->filsDroit,elem);
}


// supprime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{
	if(estVide(a))
		return a;
	if(x<a->val)
		a->filsGauche=supprimer_r(a->filsGauche,x);
	else if(x>a->val)
		a->filsDroit=supprimer_r(a->filsDroit,x);
	else {
		if(estVide(a->filsDroit)&&estVide(a->filsGauche)){
			detruireElement(a->val);
			return NULL;
		}
		else if(a->filsGauche==NULL){
			ArbreBinaire new=a->filsDroit;
			detruireElement(a->val);
			return new;
		}
		else if(a->filsDroit==NULL){
			ArbreBinaire new=a->filsGauche;
			detruireElement(a->val);
			return new;
		}
		ArbreBinaire new=max(a->filsGauche);
		a->val=new->val;
		a->filsGauche=supprimer_r(a->filsGauche,new->val);
	}
return a;
}
void detruireElement(Element e) {
}
void detruire_r(ArbreBinaire a)
{
	if(estVide(a))
		return ;
	detruire_r(a->filsGauche);
	detruire_r(a->filsDroit);
	free(a);
}

