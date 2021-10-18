#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef  int** Matrix;
typedef Matrix* MatrixArray;

void readMatrix(MatrixArray* Mat){
int ligne,colonne;
scanf("%i %i",&ligne,&colonne);
Mat=malloc(ligne*colonne*sizeof(int));
    for (int i=0;i<ligne;i++){
        for(int j=0;j<colonne;j++){
            scanf("%i ",&(*(Mat[i][j])));
        }
    }
}

void readMatrixArray(MatrixArray* Matrice,int nbMat){
        for(int i;i<nbMat;i++){
            readMatrix(&Matrice[i]);
        }
    
}

void printMatrix(MatrixArray tabMat){
}


int main(void)
{	int nbMat;
    scanf("%i\n",&nbMat); 
    MatrixArray Mat;
    Matrix tab;
    readMatrixArray(&Mat,nbMat);
    printMatrix(Mat);

	//readMatrixArray(&Mat,nbMat);
	return EXIT_SUCCESS;
}