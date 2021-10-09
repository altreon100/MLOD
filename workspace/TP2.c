#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h> 

void echange_contenu(int*valeur1,int* valeur2){
    int valeur;
valeur=(*valeur1);
(*valeur1)=(*valeur2);
(*valeur2)=valeur;
}

bool estConvexe(bool tab[],int length){
    bool valeurPrec=tab[0];
    int res=1; 
    int i=1;
    while (i != length && res!=2){
        if (tab[i]!=valeurPrec && res!=0)
            res=0;
        else if (tab[i]!=valeurPrec && res==0 )
            res=2; 
        else if (tab[i]!=valeurPrec && res==2 )
            res=3; 
        valeurPrec=tab[i];
        i++;
    }
    if (res==2 && tab[length-1]==tab[0])
        res=1;

    if (res==1)
        return true;
    else
        return false;
 }

void mult_matrice(int a,int64_t**matRes,int64_t**mat1,int64_t**mat2){
    int somme=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            for(int k=0;k<a;k++)
                somme+=mat1[i][k]*mat2[k][j];
            matRes[i][j]=somme;
        somme=0;
        
    }
}
}
void affiche_matrice(int a,int64_t**matRes){
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)
            printf("%ld ",matRes[i][j]);
        printf("\n");
    }
}
int main(void) {
    /*int a=10;
    int b=20;
    echange_contenu(&a,&b);
    printf("%d %d",a,b);
    bool tab1[4]={true,true,false,false};
    bool tab2[5]={true,true,false,true,false};
    bool tab3[5]={true,true,false,false,true};
    bool a;
    a=estConvexe(tab3,5);
    printf("%d",a);*/
int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
int64_t matriceResultat[5][5];
int a=sizeof(matrice1) / sizeof(int64_t);
    a=sqrt(a);
    printf("%d",a);
mult_matrice(a,matriceResultat,matrice1,matrice2);
affiche_matrice(a,matriceResultat);
// la fonction n'est pas intéressante car elle n'est utilisable que pour les matrices de taille 5 5.

    return 0;
}