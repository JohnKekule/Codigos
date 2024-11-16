import matplotlib.pyplot as plt


#Este codigo es el encargado de graficar el resultado 2
#Resive el archivo CSV y grafica el tiempo de ejecucion en funcion de la distancia de edicion
#Se aplico logaritmo al tiempo para ver mejor los datos.

import pandas as pd
import matplotlib.pyplot as plt


archivo_csv = "Resultados/resultados_2.csv"  
df = pd.read_csv(archivo_csv)


largo_cadenas = df["S1"].apply(len)  
distancia_dinamico = df["Distancia_Dinamico"]
tiempo_dinamico = df["Tiempo_Dinamico"]
distancia_bruteforce = df["Distancia_Bruteforce"]
tiempo_bruteforce = df["Tiempo_Bruteforce"]


plt.figure(figsize=(14, 10))


plt.subplot(2, 1, 1)
plt.scatter(largo_cadenas, tiempo_dinamico, label="Tiempo Dinámico", color='blue')
plt.scatter(largo_cadenas, tiempo_bruteforce, label="Tiempo Brute Force", color='red')
plt.yscale("log")  
plt.xlabel("Largo de las cadenas")
plt.ylabel("Tiempo de ejecución (ms)")
plt.title("Tiempos de ejecución (Dinámico vs. Brute Force) en función del largo de las cadenas")
plt.legend()
plt.grid(True)


plt.tight_layout()
plt.show()


