laboratorio3
funcionamiento:
el funcionamiento de este programa comienza con la funcion leermatriz() la cual es la que leé nuestro
archivo de entrada (archivo.in) y lo almacena en un arreglo dinamico bidimensional, para leerlo necesitamos abrir el archivo con la funcion fopen()
en modo de lectura. Con el archivo una vez abierto lo que hacemos es almacenar los datos de este archivo en un arreglo dinamico bidimensional 
para posteriormente comenzar a manipularlo.
una vez teniendo el arreglo con los datos del archivo de entrada, lo colocamos en la función rellenar() es funcion lo que hará es crear un arreglo llamado bosque en el cual irán puestos los datos del archivo de entrada.in dado la posicion x,y y las respectivas 5 alturas de los arboles de manera correcta. Luego una vez hecho lo que haremos es meter el arreglo bosque a dos funciones , salida1() y salida2() en los cuales se crearan los archivos de salida (salida1.out y salida2.out) lo que hacen estas dos salidas es abrir un archivo con fopen en modo escritura ,si no exite el archivo , lo crea
luego con fprintf usamos para almacenar el arreglo bosque en los archivos de salida.
la funcion salida2() lo que hace es crear el bosque final con los mismo datos del arreglo bosque ,puesto que esta funcion lo que hace es al mismo bosque final modificarlo para que este sea el bosque final con los datos cambiados , puesto que este arreglo no llevara arboles de altura 0 y esta funcion lo que hace finalmente es retornal el bosque final.

para finalizar el arreglo bosque y bosque Final lo colocamos en la funcion imprimirBosque() la cual nos imprimir por la salida estandar como es el bosque y el bosque final.
