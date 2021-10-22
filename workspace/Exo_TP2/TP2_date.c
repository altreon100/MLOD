#include <stdio.h>
#include <stdlib.h>
enum mois {
janvier=1,
fevrier,
mars,
avril,
mai,
juin,
juillet,
aout,
septembre,
octobre,
novembre,
decembre
};
void affiche_mois(enum mois m){
        if (m==1)
            printf("Janvier");
        else if (m==2)
            printf("Février");
        else if (m==3)
            printf("Mars");
        else if (m==4)
            printf("Avril");
        else if (m==5)
            printf("Mai");
        else if (m==6)
            printf("Juin");
        else if (m==7)
            printf("Juillet");
        else if (m==8)
            printf("Aout");
        else if (m==9)
            printf("Septembre");
        else if (m==10)
            printf("Octobre");
        else if (m==11)
            printf("Novembre");
        else if (m==12)
            printf("Décenmbre");
    }

struct Date{
    int annee;
    enum mois mois;
    int jour;
};
typedef struct Date Date;

void initialiseDate(Date*date){

    printf("Entrer l'année:");
    scanf("%d",&((*date).annee));
    printf("\nEntrer le mois en nombre:");
    scanf("%d.",(int*)&date->mois);
    printf("\nEntrer le jour:");
    scanf("%d",&date->jour);
    
}
void afficheDate(Date*date){
    printf("Aujourd'hui nous sommes le: %d ",(*date).jour);
    affiche_mois((*date).mois);
    printf(" %d",date->annee);
}
Date creerDateParCopie(){
    Date d;
    initialiseDate(&d);
    return d;
}
Date* newDate(){
    Date* date;
    date=malloc(sizeof(*date));
    initialiseDate(date);
    return date;
}
int main(void){
     /*Date d;
    initialiseDate(&d);
    afficheDate(&d);
    d = creerDateParCopie();
    afficheDate(&d);*/
    Date *date;
    date = newDate();
    afficheDate(date);
    free(date);
    return 0;
}