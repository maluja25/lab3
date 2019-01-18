/**
creado por : Diego Bustamante
RUN 20.067.251-8
seccion de laboratorio : L-2
FECHA DE CREACION : 17-enero-2019
**/
//incluimos las librerias stdio.h,stdlib.h y string.h 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIN 1000
// m y n nos dara las dimensiones que tendra la matriz con los datos almacenados en el archivo de entrada.in
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
   //retornamos la matriz con los datos del archivo de entrada.in en ella
   return matriz;
}
/*
llenarbosque
funcion que comenzara a rellenar el bosque dado la posicion x,y en la que se encuentra
entradas: x es el numero de fila de los datos que estan en el archivo entrada.in
posx y posy es la posicion x,y en la que el obtuvo los datos, en este caso son el primero y segundo elemento de cada fila del archivo de entrada.in
matriz es el puntero doble con todos los datos almacenados del archivo de entrada.in
bosque es una matriz donde iran almacenado todos los datos de los arboles que nos dan en el archivo de entrada.in
salida: nada
*/
void llenarbosque(int x,int posx,int posy,int **matriz,int **bosque){
	//i = 2 , es para comenzar a tomar desde el 3er elemento de cada fila del archivo de entrada.in
	int i = 2;
	//j = posy-2 es uniciado en menos dos posiciones de la posicion y de la que se encuentra pantro
	int j = posy - 2;
	//iteramos hasta j = posy+2 para asi rellenar los 5 datos de altura de los arboles para guardarlos en el bosque
	while(j <= posy + 2){
		//igualamos los 5 datos de las altura de los arboles con el lugar donde estos tiene que ir dependiendo de la posicion x,y
		bosque[posx-1][j] = matriz[x][i];
		j++;
		i++;
	}	
}
//declaramos largo y ancho en 0 como variables globales.
int largo = 0,ancho = 0;
/**
funcion **rellenar(int **matriz)
funcion que crea un puntero doble en el cual tendra almacenado todas las alturas de los arboles dados en el archivo de entrada.in
entradas: matriz con los datos del archivo de entrada.in
salidas: un doble puntero llamado bosque con los datos almacenados dado la posicion x,y y las alturas de los 5 arboles dados en esa posicion
**/
int **rellenar(int **matriz){
	//declaramos un entero i para comenzar a iterar desde la fila 1 puesto que el dato 0 es el numero de datos tomados por pantro
	int i;
	//usamos un for para recorrer el primero y segundo dato e ir comparando para asi obtener el largo y el ancho de la matrizbosque
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
	//para obtener el largo tenemos que sumarle 2 a la posicion y mayor 
	//para obtener el ancho hay que restarle 1 a la posicion x mayor
	largo = largo + 2;
	ancho = ancho - 1;
	//imprimimos por pantalla el largo y el ancho para verificar si esta correcto.
	printf("el largo es %i\n",largo);
	printf("el ancho es %i\n",ancho);
	//creamos una matriz dinamica llamada bosque
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
	//inicializamos i en 1 para comenzar a tomar desde la primera fila de los datos del archivo de entrada.in
	i = 1;
	//iteramos hasta la cantidad de datos que esta dado por el primer numero del archivo de entrada.in
	while(i <= matriz[0][0]){
		//llamamos a la funcion llenar bosque para que comienze a rellenar el bosque por cada dato de las filas en el archivo de entrada.in
		llenarbosque(i,matriz[i][0],matriz[i][1],matriz,bosque);
		i++;
	}
	//retornamos bosque con todos los datos de altura de los arboles colocados correctamente.
	return bosque;
}
/*
salida1(int **boque)
funcion que crea el primero archivo de salida1.out donde tiene tendra almacenado el bosque completo con las altura de los arboles incluyendo los que tiene una altura de 0
entradas: puntero doble con los datos del boque ya completo
salidas: salida1.out como archivo de salida con la matriz bosque en el archivo
*/
void salida1(int **bosque){
	//creamos una variable tipo en modo de escritura
	FILE *archivo = fopen("salida1.out","w");
	//recorremos la matriz bosque para ir imprimiendo con la funcion fprintf la matriz bosque en el archivo de salida1.out
	for (int i = 0; i <= ancho; ++i)
	{
		for (int j = 0; j <= largo; ++j)
		{
			//con fprintf imprimimos el dato para el archivo de salida1
			fprintf(archivo, "%i ",bosque[i][j]);	
		}
		fprintf(archivo,"\n");
	}
	//cerramos el archivo con fclose
	fclose(archivo);
}
/**
funcion cambio
comenzara a cambiar la matriz bosqueF que inicialmente tiene los mismo datos que la matriz boque , donde bosqueF tendra almacenado el bosque final sin agregar los datos con altura 0 ,puesto que estos seran cambiados por el arbol de altura mayor anterior
entradas: posicion x,y y un puntero doble llamado bosqueF 
salidas: ninguna
**/
int cambio(int x,int y,int **bosqueF){
	//si en la posicion y se encuentra en el limite superior del bosque retornamos 0 para que no realice el cambio
	if(y == ancho){
		return 0;
	}
	//si la posicion y siguiente hay un 0 , lo cambiamos por la misma altura que tenemos en nuetra posicion x,y actual
	if(bosqueF[y+1][x] == 0 ){
		bosqueF[y+1][x] = bosqueF[y][x];
	}
	//si no , la posicion se mantiene con el mismo numero.
	else{
		bosqueF[y+1][x] =  bosqueF[y+1][x];
	}
}
/**
salida2(int **bosque )
funcion que creara un puntero doble en el cual este tendra el bosque final con los datos igual a 0 cambiados.
entradas: bosque con todas las alturas de los arboles dados en el archivo de entrada.in
salida: bosqueF con los datos cambiados
**/
int **salida2(int **bosque){
	int i,j,k,l;
	//creamos una matriz dinamica llamada bosqueF
	int **bosqueF;
	//memoria para la cantidad de filas en bosqueF con la funcion malloc
	bosqueF = (int **)malloc(sizeof(int *)*ancho);
	//memoria para cada columna  en bosqueF
	for (i = 0; i <= largo; ++i)
		bosqueF[i] = (int *)malloc(sizeof(int)*largo);
	//rellenamos la matriz bosqueF con ceros inicialmente
	for (l = 0; l <= ancho; ++l){
		for (k = 0; k <= largo; ++k)
			bosqueF[l][k] = 0;
	}
	//copiamos los datos de la matriz bosque a bosqueF
	for (i = 0; i <= ancho; ++i)
	{
		for (j = 0; j <= largo; ++j)
			bosqueF[i][j] = bosque[i][j];
	}
	//por cada posicion x,y llamamos a la funcion cambio para hacer obtener la matriz bosqueF final con los datos cambiados
	for (i = 0; i <= ancho; ++i)
		for (j = 0; j <= largo; ++j)
			cambio(j,i,bosqueF);
	//creamos una variable tipo FILE y abrimos con fopen en modo de escritura para llamar el archivo salida2.out , si no existe la crea 
	FILE *archivo = fopen("salida2.out","w");
	//recorremos la matriz bosqueF ya con los datos cambiados para posteriormente con la funcion fprintf lo imprimimamos en el segundo archivo de salida2.out
	for (i = 0; i <= ancho; ++i)
	{
		for (j = 0; j <= largo; ++j)
		{
			fprintf(archivo, "%i ",bosqueF[i][j]);	
		}
		fprintf(archivo,"\n");
	}
	//cerramos el archivo una vez manipulado
	fclose(archivo);
	return bosqueF;
}
/**
imprimirBosque(int ** bosque)
funcion que imprime por pantalla el bosque
entradas: matriz dinamica bosque
salida: ninguna

**/
int imprimirBosque(int **bosque){
	//dos variables enteras para comenzar a recorrecore el bosque 
	int i,j;
	//recorremos el bosque para imprimir con la funcion printf 
	for (i = 0; i <= ancho; ++i)
	{
		printf("\t\t\t\t");
		for (j = 0; j <= largo; ++j)
		{
			printf("%i ",bosque[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int **matriz = leermatriz();
	int **bosque = rellenar(matriz);
	salida1(bosque);
	int **bosqueFinal=salida2(bosque);
	printf("\n\t\t\t\t");
	printf("BOSQUE con todas las alturas incluyendo con altura 0\n\n");
	imprimirBosque(bosque);
	printf("\n\t\t\t\t");
	printf("BOSQUE FINAL\n\n");
	imprimirBosque(bosqueFinal);
	printf("\n\n\n");
	return 0;
}