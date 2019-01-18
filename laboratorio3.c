#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIN 1000



// m y n nos dara las dimensiones 
int m = 0 , n = 0;
/*
funcion leermatriz
lo que hace esta funcion es leer el archivo de entrada .txt para comenzar a manípularlo dentro del programa
entrada: no tiene.
salida: un puntero doble , con todo lo del archivo almacenado
*/

int **leermatriz(){
   //fp es un dato tipo FILE y usando fopen para abrir el archivo de entrada .txt en modo lectura 
   FILE* fp=fopen("archivo.txt","r");
   // linea[MAX_LIN] es un arreglo estatico de tamaño 1000 (MAX_LINE = 1000) donde en el se almacenar cada una de las lineas en el archivo de entrada .txt
   // *p es un puntero que utilizando la funcion strtok va a separar los datos según la separacion que deseamos dar.
   char linea[MAX_LIN], *p;
   // val es la variable que almacenara cada dato de la linea en dato entero para posteriormente guardarla en la matriz
   int val;
   // aqui reservamos memoria para la matriz con la funcion calloc
   int **matriz= (int **) calloc(1000, sizeof(int *)) ;
   //inicializamos m con valor -1
   m=-1;
   while (fgets(linea, MAX_LIN, fp)!=NULL) {
     m=m+1;
     //aqui reservamos memoria para cada uno de los espacios de la matriz
     //printf("La linea es : %s\n", linea);
     matriz[m] = (int *) calloc(MAX_LIN, sizeof(int));
     p = strtok(linea,",");
     n=-1;
     while(p != NULL) {
       n=n+1;
       //con sscanf le damos le asignamos a val el valor que contiene p para posteriormente asigarle val a matriz en la posicion m,n
       sscanf(p,"%d",&val);
       //printf("%d\n",val);
       matriz[m][n] = val;
       p=strtok(NULL," ");
     }

   }
   //retornamos la matriz con los datos del archivo de entrada .txt en ella
   return matriz;
}
int llenarbosque(int posx,int posy,int **matriz,int **bosque){
	int i = 6;
	int j = -2;
	printf("\n\n\n");
	printf("el posx = %i\n",posx);
	printf("el posy = %i\n",posy);
	while(j < 3){
		printf("el posxb = %i\n",posx-1);
		printf("el posyb= %i\n",posy+j);
		bosque[posy-1][posx-j] = matriz[1][i];
		printf("bosque[%i][%i] (%i) == matriz[%i][%i](%i)\n",posy-2,posx-j,bosque[posy-2][posx-j],0,i,matriz[1][i]);
		j++;
		i--;
	}	
}
int rellenar(int **matriz){
	int largo = 0,ancho = 0;
	int i = 0;
	for(i = 1 ; i <= m ; i++){
		if(matriz[i][1] > largo){
			largo = matriz[i][1];
		}else{
			largo = largo;
		}
		if(matriz[i][0] > ancho){
			ancho = matriz[i][0];
		}
		else{
			ancho = ancho;
		}
	}
	largo = largo + 2;
	ancho = ancho - 1;
	printf("el largo es %i\n",largo);
	printf("el ancho es %i\n",ancho);
	int **bosque;
	//memoria para bosque con la funcion malloc
	bosque = (int **)malloc(sizeof(int *)*ancho);
	//memoria para cada espacio en bosque
	for (int i = 0; i <= largo; ++i)
		bosque[i] = (int *)malloc(sizeof(int)*largo);
	//rellenamos la matriz bosque con ceros inicialmente
	for (int l = 0; l <= ancho; ++l){
		for (int k = 0; k <= largo; ++k)
			bosque[l][k] = 0;
	}
	llenarbosque(matriz[1][0],matriz[1][1],matriz,bosque);
	//llenarbosque(matriz[2][0],matriz[2][1],matriz,bosque);
	//llenarbosque(matriz[3][0],matriz[3][1],matriz,bosque);
	//llenarbosque(matriz[4][0],matriz[4][1],matriz,bosque);
	/*
	llenarbosque(matriz[5][0],matriz[5][1],matriz,bosque);
	llenarbosque(matriz[6][0],matriz[6][1],matriz,bosque);
	llenarbosque(matriz[7][0],matriz[7][1],matriz,bosque);
	*/
	for (int i = 0; i <= ancho; ++i)
	{
		for (int j = 0; j <= largo; ++j)
		{
			printf("%i    ",bosque[i][j]);
		}
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int **matriz = leermatriz();
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			printf("%i    ",matriz[i][j]);
		}
		printf("\n");
	}


	rellenar(matriz);
	return 0;
}