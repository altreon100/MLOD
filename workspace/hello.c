#include <stdio.h>

float prix_billet (float prix_plein_tarif, int age){
    float prix_bille=0;  
    if(age<2)
        prix_bille=0.1*prix_plein_tarif;
    else if (age>2 && age<=12)
        prix_bille=0.5*prix_plein_tarif;
    else
        prix_bille=prix_plein_tarif;
    return prix_bille;
}

void affichage_des(int N){
    printf("Pour N=%d, les combinaisons sont:",N);
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                if(i+j+k==N)
                    printf("%d%d%d ",i,j,k);
            }
        }
    }
}

void affiche_parfait(int N){
    int somme=0;
    printf("Les nombres compris entre 0 et %d sont",N);
    for(int i=1;i<=N;i++){
        somme=0;
        for(int j=1;j<=(i/2);j++){
            if(i%j==0)
                somme+=j;
                }
        if(somme==i)
            printf(" %d",i);
    }
}

typedef unsigned long long TypeEntier;

TypeEntier  factiorielle(int N){
    unsigned long long somme=1;
    for(int i=1;i<=N;i++)
        somme*=i;
    
    return somme;
}
int main(void) {
    //float a=0;
    //a=prix_billet(10,5);
    //affiche_parfait(496);
    //printf("Le prix du billet est %f\n",a);
    for(int b=0;b<=15;b++)
    printf("Factiorielle%d= %llu\n",b,factiorielle(b));
    return 0;
}
