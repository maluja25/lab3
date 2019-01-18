#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char const *argv[])
{
	srand (time(NULL));
	int largo = 15;
	int ancho = 5; 
	int numero; 
	int **matriz;
	//memoria para matriz con la funcion malloc
	matriz = (int **)malloc(sizeof(int *)*ancho);
	//memoria para cada espacio en matriz
	for (int i = 0; i <= largo; ++i)
		matriz[i] = (int *)malloc(sizeof(int)*largo);
	//rellenamos la matriz matriz con ceros inicialmente
	for (int l = 0; l <= ancho; ++l){
		for (int k = 0; k <= largo; ++k){
			numero = rand() % 10; 
			matriz[l][k] = numero;
			printf("%i  ",matriz[l][k]);
		}
		printf("\n");	
	}
	return 0;
}