def separar_elementos(maximum_referencia_A, maximum_referencia_B, maximals):
    maximum_A = set(maximum_referencia_A)
    maximum_B = set(maximum_referencia_B)

    print(f'Máximo A: {maximum_A}')
    print(f'Máximo B: {maximum_B}\n')

    for maximal in maximals:
        elementos_maximal_in_A = []
        elementos_maximal_in_B = []

        for elemento in maximal:
            if elemento in maximum_A and elemento in maximum_B:
                elementos_maximal_in_A.append(elemento)
            else:
                if elemento in maximum_A:
                    elementos_maximal_in_A.append(elemento)
                if elemento in maximum_B:
                    elementos_maximal_in_B.append(elemento)

        print(f"--------------------------------------------------------\n")
        print(f"Maximal: {maximal}")
        print(f"Elementos do máximo A: {elementos_maximal_in_A}")
        print(f"Elementos do máximo B: {elementos_maximal_in_B}\n")

maximum_A = {2, 3, 5, 8, 9, 12, 14, 15}
maximum_B = {1, 4, 6, 7, 10, 11, 13, 16}

maximals = [
    { 4, 7, 8, 9, 12, 13 }, 
    { 4, 5, 8, 12, 13, 16 }, 
    { 4, 5, 8, 9, 12, 13 }, 
    { 4, 7, 8, 9, 10, 13 }, 
    { 4, 5, 8, 10, 13, 16 }, 
    { 4, 5, 8, 9, 10, 13 }, 
    { 4, 7, 8, 11, 12, 15 }, 
    { 4, 7, 8, 9, 12, 15 }, 
    { 4, 5, 8, 9, 12, 15 }, 
    { 3, 7, 8, 10, 11, 14 }, 
    { 3, 6, 7, 11, 14, 15 }, 
    { 3, 6, 7, 10, 11, 14 }, 
    { 3, 7, 8, 9, 10, 14 }, 
    { 3, 6, 7, 9, 14, 15 }, 
    { 3, 6, 7, 9, 10, 14 }, 
    { 3, 7, 8, 11, 12, 16 }, 
    { 3, 7, 8, 10, 11, 16 }, 
    { 3, 6, 7, 10, 11, 16 }, 
    { 2, 3, 8, 10, 11, 14 }, 
    { 2, 3, 6, 11, 14, 15 }, 
    { 2, 3, 6, 10, 11, 14 }, 
    { 2, 3, 8, 11, 12, 16 }, 
    { 2, 3, 8, 10, 11, 16 }, 
    { 2, 3, 5, 8, 12, 16 }, 
    { 2, 3, 5, 8, 10, 16 }, 
    { 2, 3, 6, 10, 11, 16 }, 
    { 2, 3, 5, 6, 10, 16 }, 
    { 2, 5, 8, 12, 13, 16 }, 
    { 2, 5, 8, 10, 13, 16 }, 
    { 2, 8, 11, 12, 13, 16 }, 
    { 2, 8, 10, 11, 13, 16 }, 
    { 2, 5, 8, 9, 12, 13 }, 
    { 2, 5, 8, 9, 10, 13 }, 
    { 2, 5, 6, 10, 13, 16 }, 
    { 2, 6, 10, 11, 13, 16 }, 
    { 2, 5, 6, 9, 10, 13 }, 
    { 1, 4, 7, 9, 12, 13 }, 
    { 1, 4, 5, 12, 13, 16 }, 
    { 1, 4, 5, 9, 12, 13 }, 
    { 1, 4, 7, 11, 12, 15 }, 
    { 1, 4, 7, 9, 12, 15 }, 
    { 1, 4, 6, 7, 11, 15 }, 
    { 1, 4, 6, 7, 9, 15 }, 
    { 1, 4, 5, 9, 12, 15 }, 
    { 1, 4, 5, 6, 9, 15 }, 
    { 1, 6, 7, 11, 14, 15 }, 
    { 1, 6, 7, 9, 14, 15 }, 
    { 1, 7, 11, 12, 14, 15 }, 
    { 1, 7, 9, 12, 14, 15 }, 
    { 1, 6, 7, 10, 11, 14 }, 
    { 1, 6, 7, 9, 10, 14 }, 
    { 1, 5, 6, 9, 14, 15 }, 
    { 1, 5, 9, 12, 14, 15 }, 
    { 1, 5, 6, 9, 10, 14 }, 
    { 4, 7, 8, 11, 12, 13, 16 }, 
    { 4, 7, 8, 10, 11, 13, 16 }, 
    { 3, 7, 8, 11, 12, 14, 15 }, 
    { 3, 7, 8, 9, 12, 14, 15 }, 
    { 2, 3, 8, 11, 12, 14, 15 }, 
    { 2, 3, 5, 8, 9, 10, 14 }, 
    { 2, 3, 5, 6, 9, 14, 15 }, 
    { 2, 3, 5, 6, 9, 10, 14 }, 
    { 1, 4, 7, 11, 12, 13, 16 }, 
    { 1, 4, 6, 7, 9, 10, 13 }, 
    { 1, 4, 5, 6, 10, 13, 16 }, 
    { 1, 4, 5, 6, 9, 10, 13 }, 
    { 2, 3, 5, 8, 9, 12, 14, 15 }, 
    { 1, 4, 6, 7, 10, 11, 13, 16 }
]

# Chama a função para separar os maximals
separar_elementos(maximum_A, maximum_B, maximals)