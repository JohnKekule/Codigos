import random
import string

def generar_dataset_transposiciones(n):
    dataset = []
    abecedario = string.ascii_lowercase  # Abecedario en minúsculas

    for i in range(2, n + 1):  # Comenzamos desde 2 para garantizar que haya al menos 2 caracteres para transposición
        # Generamos una cadena base S_i de longitud i
        S_i = ''.join(random.choice(abecedario) for _ in range(i))
        
        # Convertimos S_i a una lista para modificarla
        S_j_list = list(S_i)

        # Realizamos una transposición en un par aleatorio de caracteres consecutivos
        idx = random.randint(0, i - 2)  # Índice para intercambiar los caracteres en idx y idx + 1
        S_j_list[idx], S_j_list[idx + 1] = S_j_list[idx + 1], S_j_list[idx]

        # Convertimos de nuevo S_j a una cadena
        S_j = ''.join(S_j_list)
        
        # Guardamos el par (S_i, S_j) como una tupla en la lista del dataset
        dataset.append((S_i, S_j))
    
    return dataset

# Definir el tamaño máximo de cadenas deseado
n = 17  # Puedes cambiar el valor de n según el tamaño del dataset
dataset = generar_dataset_transposiciones(n)

# Guardar el dataset en un archivo txt con formato especificado
with open("dataset_transposiciones.txt", "w") as file:
    for idx, (S_i, S_j) in enumerate(dataset, start=1):
        file.write(f"Caso {idx}: S1 = '{S_i}'    S2 = '{S_j}'\n")

print("El dataset con transposiciones ha sido guardado en dataset_transposiciones.txt")
