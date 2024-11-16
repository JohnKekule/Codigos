import random
import string

def generar_dataset(n):
    dataset = {}
    abecedario = string.ascii_lowercase  # Abecedario en minúsculas

    for i in range(0, n + 1):  # Generamos S_i con longitud i
        S_i = ''.join(random.choice(abecedario) for _ in range(i))
        S_j = ''.join(random.choice(abecedario) for _ in range(i + 1))  # Generamos S_j con longitud j+1
        dataset[f"Caso {i+2}"] = (S_i, S_j)
    
    return dataset

# Definir el tamaño máximo de cadenas deseado
n = 14  # Puedes cambiar el valor de n según el tamaño del dataset
dataset = generar_dataset(n)

# Guardar el dataset en un archivo txt
with open("dataset.txt", "w") as file:
    for key, (S_i, S_j) in dataset.items():
        file.write(f"{key}: S1 = '{S_i}', S2 = '{S_j}'\n")

print("El dataset ha sido guardado en dataset.txt")
