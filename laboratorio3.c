#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIN 1000
#define Cnegro ▅



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
   FILE* fp=fopen("archivo.in","r");
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
int llenarbosque(int x,int posx,int posy,int **matriz,int **bosque){
	int i = 2;
	int j = posy - 2;
	while(j <= posy + 2){
		bosque[posx-1][j] = matriz[x][i];
		j++;
		i++;
	}	
}
int largo = 0,ancho = 0;
int **rellenar(int **matriz){
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
	i = 1;
	while(i<=22){
		llenarbosque(i,matriz[i][0],matriz[i][1],matriz,bosque);
		i++;
	}
	return bosque;
}
int salida1(int **bosque){
	FILE *archivo = fopen("salida1.out","w");

	for (int i = 0; i <= ancho; ++i)
	{
		for (int j = 0; j <= largo; ++j)
		{
			if(bosque[i][j] == 0){
				int X = 'X';
				fprintf(archivo, "0 ");;
			}else{
				fprintf(archivo, "%i ",bosque[i][j]);
			}	
		}
		fprintf(archivo,"\n");
	}
	fclose(archivo);
}
int cambio(int x,int y,int **bosqueF){
	if(y == ancho){
		return 0;
	}
	if(bosqueF[y+1][x] == 0 ){
		bosqueF[y+1][x] = bosqueF[y][x];
	}else{
		bosqueF[y+1][x] =  bosqueF[y+1][x];
	}
}
int salida2(int **bosque){
	int **bosqueF;
	//memoria para bosque con la funcion malloc
	bosqueF = (int **)malloc(sizeof(int *)*ancho);
	//memoria para cada espacio en bosque
	for (int i = 0; i <= largo; ++i)
		bosqueF[i] = (int *)malloc(sizeof(int)*largo);
	//rellenamos la matriz bosque con ceros inicialmente
	for (int l = 0; l <= ancho; ++l){
		for (int k = 0; k <= largo; ++k)
			bosqueF[l][k] = 0;
	}
	for (int i = 0; i <= ancho; ++i)
	{
		for (int j = 0; j <= largo; ++j)
		{
			bosqueF[i][j] = bosque[i][j];
			printf("%i ",bosqueF[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i <= ancho; ++i)
	{
		for (int j = 0; j <= largo; ++j)
		{
			cambio(j,i,bosqueF);
			printf("%i ",bosqueF[i][j]);
		}
		printf("\n");
	}
	FILE *archivo = fopen("salida2.out","w");

	for (int i = 0; i <= ancho; ++i)
	{
		for (int j = 0; j <= largo; ++j)
		{
			fprintf(archivo, "%i ",bosqueF[i][j]);	
		}
		fprintf(archivo,"\n");
	}
	fclose(archivo);
}
int main(int argc, char const *argv[])
{
	int **matriz = leermatriz();
	int **bosque = rellenar(matriz);
	salida1(bosque);
	printf("\n");
	salida2(bosque);
	return 0;
}