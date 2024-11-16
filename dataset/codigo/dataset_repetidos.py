import random
import string

def generar_dataset_caracteres_repetidos(n):
    dataset = []
    abecedario = string.ascii_lowercase  # Abecedario en minúsculas

    for i in range(2, n + 1):  # Comenzamos desde 2 para garantizar que haya al menos 2 caracteres
        # Generamos una lista de caracteres aleatorios con repeticiones para S_i
        S_i = ''.join(random.choice(random.choices(abecedario, k=3)) for _ in range(i))
        
        # Crear una variación de S_i para S_j introduciendo duplicaciones
        S_j_list = list(S_i)
        
        # Determinamos el número de duplicaciones en `S2` para el caso `i`
        num_duplicaciones = i - 1  # Comienza en 1 y aumenta con cada iteración
        
        # Duplicar caracteres en posiciones aleatorias de `S_j_list`
        for _ in range(num_duplicaciones):
            idx = random.randint(0, len(S_j_list) - 1)
            S_j_list.insert(idx, S_j_list[idx])  # Duplica el carácter en una posición aleatoria
        
        # Convertimos S_j de nuevo a una cadena
        S_j = ''.join(S_j_list)
        
        # Guardamos el par (S_i, S_j) como una tupla en la lista del dataset
        dataset.append((S_i, S_j))
    
    return dataset

# Definir el tamaño máximo de cadenas deseado
n = 17  # Puedes cambiar el valor de n según el tamaño del dataset
dataset = generar_dataset_caracteres_repetidos(n)

# Guardar el dataset en un archivo txt con formato especificado
with open("dataset_caracteres_repetidos.txt", "w") as file:
    for idx, (S_i, S_j) in enumerate(dataset, start=1):
        file.write(f"Caso {idx}: S1 = '{S_i}'    S2 = '{S_j}'\n")

print("El dataset con caracteres repetidos ha sido guardado en dataset_caracteres_repetidos.txt")
