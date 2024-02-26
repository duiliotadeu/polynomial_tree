# Número total de vértices no grafo
num_vertices = 12

# Inicializando a matriz de adjacência com zeros
matriz_adjacencia = [[0] * num_vertices for _ in range(num_vertices)]

# Lista de arestas fornecidas
arestas = [
(1, 2),
(1, 4),
(1, 6),
(1, 12),
(2, 5),
(2, 10),
(2, 11),
(3, 4),
(3, 6),
(3, 10),
(3, 11),
(4, 8),
(4, 9),
(5, 6),
(5, 8),
(5, 9),
(6, 7),
(7, 8),
(7, 10),
(7, 12),
(8, 11),
(9, 10),
(9, 12),
(11, 12),
]

# Preenchendo a matriz de adjacência com 1 nas posições correspondentes às arestas
for aresta in arestas:
    u, v = aresta
    matriz_adjacencia[u - 1][v - 1] = 1
    matriz_adjacencia[v - 1][u - 1] = 1  # Se o grafo for não direcionado, remova esta linha

# Imprimindo a matriz de adjacência
for linha in matriz_adjacencia:
    print(linha)