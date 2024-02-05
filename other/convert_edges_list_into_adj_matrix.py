# Número total de vértices no grafo
num_vertices = 32

# Inicializando a matriz de adjacência com zeros
matriz_adjacencia = [[0] * num_vertices for _ in range(num_vertices)]

# Lista de arestas fornecidas
arestas = [
(1, 20),
(1, 24),
(1, 25),
(1, 28),
(17, 8),
(17, 9),
(17, 12),
(17, 14),
(20, 5),
(20, 9),
(20, 12),
(4, 21),
(4, 25),
(4, 28),
(4, 31),
(5, 24),
(5, 29),
(5, 32),
(21, 13),
(21, 16),
(21, 10),
(24, 13),
(24, 16),
(8, 29),
(8, 32),
(8, 27),
(9, 32),
(9, 22),
(25, 12),
(25, 16),
(28, 13),
(28, 7),
(12, 29),
(13, 18),
(29, 16),
(32, 3),
(2, 19),
(2, 23),
(2, 26),
(2, 27),
(18, 7),
(18, 10),
(18, 11),
(19, 6),
(19, 10),
(19, 11),
(3, 22),
(3, 26),
(3, 27),
(6, 23),
(6, 30),
(6, 31),
(22, 14),
(22, 15),
(23, 14),
(23, 15),
(7, 30),
(7, 31),
(10, 31),
(26, 11),
(26, 15),
(27, 14),
(11, 30),
(30, 15),
]

# Preenchendo a matriz de adjacência com 1 nas posições correspondentes às arestas
for aresta in arestas:
    u, v = aresta
    matriz_adjacencia[u - 1][v - 1] = 1
    matriz_adjacencia[v - 1][u - 1] = 1  # Se o grafo for não direcionado, remova esta linha

# Imprimindo a matriz de adjacência
for linha in matriz_adjacencia:
    print(linha)