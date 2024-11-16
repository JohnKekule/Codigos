import pandas as pd
import matplotlib.pyplot as plt

#Este codigo es el encargado de graficar los resultados 1 y 3
#Resive el archivo CSV y grafica el tiempo de ejecucion en funcion de la distancia de edicion
#Se aplico logaritmo al tiempo para ver mejor los datos.

df = pd.read_csv('Resultados/resultados_3.csv')


plt.figure(figsize=(10, 6))


plt.scatter(df['Distancia_Dinamico'], df['Tiempo_Dinamico'], color='blue', label='Tiempo Dinámico', alpha=0.6)


plt.scatter(df['Distancia_Bruteforce'], df['Tiempo_Bruteforce'], color='red', label='Tiempo Fuerza Bruta', alpha=0.6)


plt.title('Tiempo Promedio vs Distancia de Edición (Escala Logarítmica)', fontsize=14)
plt.xlabel('Distancia de Edición', fontsize=12)
plt.ylabel('Tiempo Promedio (microsegundos)', fontsize=12)


plt.yscale('log')


plt.legend()


plt.grid(True)
plt.show()



