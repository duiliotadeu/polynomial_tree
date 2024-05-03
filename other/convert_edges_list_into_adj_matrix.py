# Número total de vértices no grafo
num_vertices = 24

# Inicializando a matriz de adjacência com zeros
matriz_adjacencia = [[0] * num_vertices for _ in range(num_vertices)]

# Lista de arestas fornecidas
arestas = [
(1, 7),
(1, 9),
(1, 11),
(1, 12),
(2, 8),
(2, 10),
(2, 12),
(2, 14),
(3, 5),
(3, 9),
(3, 11),
(3, 15),
(4, 6),
(4, 9),
(4, 10),
(4, 12),
(5, 6),
(5, 7),
(5, 11),
(6, 8),
(6, 12),
(7, 8),
(7, 9),
(8, 10),
(10, 22),
(11, 23),
(13, 19),
(13, 21),
(13, 23),
(13, 24),
(14, 20),
(14, 22),
(14, 24),
(15, 17),
(15, 21),
(15, 23),
(16, 18),
(16, 21),
(16, 22),
(16, 24),
(17, 18),
(17, 19),
(17, 23),
(18, 20),
(18, 24),
(19, 20),
(19, 21),
(20, 22),
]

# Preenchendo a matriz de adjacência com 1 nas posições correspondentes às arestas
for aresta in arestas:
    u, v = aresta
    matriz_adjacencia[u - 1][v - 1] = 1
    matriz_adjacencia[v - 1][u - 1] = 1  # Se o grafo for não direcionado, remova esta linha

# Imprimindo a matriz de adjacência
for linha in matriz_adjacencia:
    print(f'{linha},')