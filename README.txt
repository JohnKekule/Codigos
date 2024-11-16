Consideraciones:

Como se menciono en el informe, ambos codigos estan basados en una relacion de recurrencia extraida de https://es.wikipedia.org/wiki/Distancia_de_Damerau-Levenshtein, luego se realizo el 
codigo de programacion dinamica, basandose en esa relacion de recurrencia. En cuanto al codigo de fuerza bruta, tambien fue realizado tomando como ejemplo esa relacion de recurrencia (no de 
manera literal, ya que esa relacion de recurrencia es para programacion dinamica), por lo que es probable que el lector reconozca los codigos de este sitio o algun otro en internet.


Como ejecutar:

La manera de ejecutar este codig, es bastante simple debido a su makefile, unicamente se encesita una terminal WSL y escribir "make", luego "make run", y el codigo se ejecutara. Para borrar los archivos creados durante la compilacion y ejecucion, 
unicamente debe escribir "make clean" en la terminal WSL.


Datasets:

Notara que existen 3 generadores de datos, cada uno trabaja de manera independiente del otro, y egenran cadenas distintas para cada tipo de prueba, transposiciones, caracteres repetidos
o cadenas aleatorias. Esto esta mejor detallado en el informe.


Graficos:

Para generar los graficos de los resultados 1 y 3 se requiere usar "graficos_1_3.py", ya que el dataset de transposiciones tiene una pecurialidad, explicada en el informa, por lo que para graficar
el resultado del dataset de transposiciones, DEBE usar "graficos_2.py".


CSV:

Los archivos CSV de la carpeta "Resultados" no se generan automaticamente, el archivo "automata.cpp"genera un archivo CSV con el dataset que se le entrego, por lo que el cambio de nombre del archivo debe ser manual para evitar
sobrescribir el archivo.

