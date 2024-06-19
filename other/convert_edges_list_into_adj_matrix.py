# Número total de vértices no grafo
num_vertices = 24

# Inicializando a matriz de adjacência com zeros
matriz_adjacencia = [[0] * num_vertices for _ in range(num_vertices)]

# Lista de arestas fornecidas
arestas = [
(1, 4),
(1, 23),
(1, 25),
(1, 30),
(2, 3),
(2, 22),
(2, 24),
(2, 29),
(3, 7),
(3, 22),
(3, 27),
(4, 8),
(4, 23),
(4, 26),
(5, 24),
(5, 27),
(5, 28),
(5, 32),
(6, 9),
(6, 25),
(6, 26),
(6, 31),
(7, 28),
(7, 29),
(7, 36),
(8, 9),
(8, 30),
(8, 35),
(9, 30),
(9, 32),
(10, 13),
(10, 21),
(10, 32),
(10, 34),
(11, 12),
(11, 20),
(11, 31),
(11, 33),
(12, 16),
(12, 31),
(12, 36),
(13, 17),
(13, 32),
(13, 35),
(14, 19),
(14, 23),
(14, 33),
(14, 36),
(15, 18),
(15, 22),
(15, 34),
(15, 35),
(16, 19),
(16, 20),
(16, 27),
(17, 18),
(17, 21),
(17, 26),
(18, 21),
(18, 23),
(19, 20),
(19, 22),
(20, 24),
(21, 25),
(24, 27),
(25, 26),
(28, 29),
(28, 31),
(29, 33),
(30, 34),
(33, 36),
(34, 35)
]

# Preenchendo a matriz de adjacência com 1 nas posições correspondentes às arestas
for aresta in arestas:
    u, v = aresta
    matriz_adjacencia[u - 1][v - 1] = 1
    matriz_adjacencia[v - 1][u - 1] = 1  # Se o grafo for não direcionado, remova esta linha

# Imprimindo a matriz de adjacência
for linha in matriz_adjacencia:
    print(f'{linha},')