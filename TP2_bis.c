#include <stdio.h>
enum mois {
janvier,
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

struct Date{
    int annee;
    enum mois mois;
    int jour;
};
typedef struct Date Date;

void initialiseDate(Date*date){
    int a;
    int c;
    enum mois b;
    printf("Entrer l'année:");
    scanf("%d",&a);
    (*date).annee=a;
    
    printf("\nEntrer le mois en toute lettre:");
    scanf("%u.",&b);
    (*date).mois=b;
    printf("%u.",b);
    printf("\nEntrer le jour:");
    scanf("%d",&c);
    (*date).jour=c;
    
}
void afficheDate(Date*date){
    printf("Aujourd'hui nous sommes le: %d %u %d",(*date).jour,(*date).mois,(*date).annee);
}
Date creerDateParCopie(){
    Date d;
    initialiseDate(&d);
    return d;
}
int main(void){
     Date d;
    //initialiseDate(&d);
    d = creerDateParCopie();
    afficheDate(&d);
    return 0;
}