#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef  int** Matrix;
typedef Matrix* MatrixArray;

void readMatrix(MatrixArray* Mat,int ligne, int colonne){

Mat=malloc(ligne*colonne*sizeof(int));
    for (int i=0;i<ligne;i++){
        for(int j=0;j<colonne;j++){
            scanf("%i ",&(**(Mat[i][j])));
        }
    }
}

void readMatrixArray(MatrixArray* Matrice,int nbMat,int ligne,int colonne){
        for(int i;i<nbMat;i++){
            scanf("%i %i",&ligne,&colonne);
            readMatrix(&Matrice[i],ligne,colonne);
        }
    
}

void printMatrix(MatrixArray tabMat,int nbMat){
    int ligne,colonne;
    for(int i=0;i<nbMat;i++){
        
        readMatrixArray(tabMat,nbMat,ligne,colonne);

    }
}


int main(void)
{	int nbMat;
    scanf("%i\n",&nbMat); 
    printf("%i\n",nbMat);
    MatrixArray Mat;
    Matrix tab;
    //readMatrixArray(&Mat,nbMat);
    printMatrix(Mat,nbMat);

	//readMatrixArray(&Mat,nbMat);
	return EXIT_SUCCESS;
}