import math

def remove_duplicates(maximals):
    unique_maximals = []
    for maximal in maximals:
        if maximal not in unique_maximals:
            unique_maximals.append(maximal)
    return unique_maximals

def rotate_and_translation_set(vertex_list, maximals):
    i = 0
    maximal_list = []
    for maximal in maximals:
        for j in range(len(vertex_list[0])):
            for k in range(len(vertex_list[0][0])):
                if (j == 0 and k == 0):
                    continue
                to_remove = []
                for element in maximal:
                    i = element - 1
                    to_remove.append(vertex_list[i][j][k])
                maximal_list.append(to_remove)

    unique_maximals = remove_duplicates(maximal_list)
    return unique_maximals
   

vertex_1 = [
    [ 1, 24, 16, 25 ],
    [ 20, 5, 29, 12 ],
    [ 9, 32, 8, 17 ],
    [ 22, 3, 27, 14 ],
    [ 15, 26, 2, 23 ],
    [ 30, 11, 19, 6 ],
    [ 7, 18, 10, 31 ],
    [ 28, 13, 21, 4 ]
]

vertex_2 = [
  [ 2, 23, 15, 26 ],
  [ 19, 6, 30, 11 ],
  [ 10, 31, 7, 18 ],
  [ 21, 4, 28, 13 ],
  [ 16, 25, 1, 24 ],
  [ 29, 12, 20, 5 ],
  [ 8, 17, 9, 32 ],
  [ 27, 14, 22, 3 ]
]

vertex_3 = [
  [ 3, 27, 14, 22 ],
  [ 26, 2, 23, 15 ],
  [ 11, 19, 6, 30 ],
  [ 18, 10, 31, 7],
  [ 13, 21, 4, 28 ],
  [ 24, 16, 25, 1 ],
  [ 5, 29, 12, 20 ],
  [ 32, 8, 17, 9 ]
]

vertex_4 = [
  [ 4, 28, 13, 21 ],
  [ 25, 1, 24, 16 ],
  [ 12, 20, 5, 29 ],
  [ 17, 9, 32, 8 ],
  [ 14, 22, 3, 27 ],
  [ 23, 15, 26, 2 ],
  [ 6, 30, 11, 19 ],
  [ 31, 7, 18, 10 ]
]

vertex_5 = [
  [ 5, 29, 12, 20 ],
  [ 32, 8, 17, 9 ],
  [ 3, 27, 14, 22 ],
  [ 26, 2, 23, 15 ],
  [ 11, 19, 6, 30 ],
  [ 18, 10, 31, 7],
  [ 13, 21, 4, 28 ],
  [ 24, 16, 25, 1 ]
]

vertex_6 = [
  [ 6, 30, 11, 19 ],
  [ 31, 7, 18, 10 ],
  [ 4, 28, 13, 21 ],
  [ 25, 1, 24, 16 ],
  [ 12, 20, 5, 29 ],
  [ 17, 9, 32, 8 ],
  [ 14, 22, 3, 27 ],
  [ 23, 15, 26, 2 ]
]

vertex_7 = [
  [ 7, 18, 10, 31 ],
  [ 28, 13, 21, 4 ],
  [ 1, 24, 16, 25 ],
  [ 20, 5, 29, 12 ],
  [ 9, 32, 8, 17 ],
  [ 22, 3, 27, 14 ],
  [ 15, 26, 2, 23 ],
  [ 30, 11, 19, 6 ]
]

vertex_8 = [
  [ 8, 17, 9, 32 ],
  [ 27, 14, 22, 3 ],
  [ 2, 23, 15, 26 ],
  [ 19, 6, 30, 11 ],
  [ 10, 31, 7, 18 ],
  [ 21, 4, 28, 13 ],
  [ 16, 25, 1, 24 ],
  [ 29, 12, 20, 5 ]
]

vertex_9 = [
  [ 9, 32, 8, 17 ],
  [ 22, 3, 27, 14 ],
  [ 15, 26, 2, 23 ],
  [ 30, 11, 19, 6 ],
  [ 7, 18, 10, 31 ],
  [ 28, 13, 21, 4 ],
  [ 1, 24, 16, 25 ],
  [ 20, 5, 29, 12 ]
]

vertex_10 = [
  [ 10, 31, 7, 18 ],
  [ 21, 4, 28, 13 ],
  [ 16, 25, 1, 24 ],
  [ 29, 12, 20, 5 ],
  [ 8, 17, 9, 32 ],
  [ 27, 14, 22, 3 ],
  [ 2, 23, 15, 26 ],
  [ 19, 6, 30, 11 ]
]

vertex_11 = [
  [ 11, 19, 6, 30 ],
  [ 18, 10, 31, 7],
  [ 13, 21, 4, 28 ],
  [ 24, 16, 25, 1 ],
  [ 5, 29, 12, 20 ],
  [ 32, 8, 17, 9 ],
  [ 3, 27, 14, 22 ],
  [ 26, 2, 23, 15 ]
]

vertex_12 = [
  [ 12, 20, 5, 29 ],
  [ 17, 9, 32, 8 ],
  [ 14, 22, 3, 27 ],
  [ 23, 15, 26, 2 ],
  [ 6, 30, 11, 19 ],
  [ 31, 7, 18, 10 ],
  [ 4, 28, 13, 21 ],
  [ 25, 1, 24, 16 ]
]

vertex_13 = [
  [ 13, 21, 4, 28 ],
  [ 24, 16, 25, 1 ],
  [ 5, 29, 12, 20 ],
  [ 32, 8, 17, 9 ],
  [ 3, 27, 14, 22 ],
  [ 26, 2, 23, 15 ],
  [ 11, 19, 6, 30 ],
  [ 18, 10, 31, 7]
]

vertex_14 = [
  [ 14, 22, 3, 27 ],
  [ 23, 15, 26, 2 ],
  [ 6, 30, 11, 19 ],
  [ 31, 7, 18, 10 ],
  [ 4, 28, 13, 21 ],
  [ 25, 1, 24, 16 ],
  [ 12, 20, 5, 29 ],
  [ 17, 9, 32, 8 ]
]

vertex_15 = [
  [ 15, 26, 2, 23 ],
  [ 30, 11, 19, 6 ],
  [ 7, 18, 10, 31 ],
  [ 28, 13, 21, 4 ],
  [ 1, 24, 16, 25 ],
  [ 20, 5, 29, 12 ],
  [ 9, 32, 8, 17 ],
  [ 22, 3, 27, 14 ]
]

vertex_16 = [
  [ 16, 25, 1, 24 ],
  [ 29, 12, 20, 5 ],
  [ 8, 17, 9, 32 ],
  [ 27, 14, 22, 3 ],
  [ 2, 23, 15, 26 ],
  [ 19, 6, 30, 11 ],
  [ 10, 31, 7, 18 ],
  [ 21, 4, 28, 13 ]
]

vertex_17 = [
  [ 17, 9, 32, 8 ],
  [ 14, 22, 3, 27 ],
  [ 23, 15, 26, 2 ],
  [ 6, 30, 11, 19 ],
  [ 31, 7, 18, 10 ],
  [ 4, 28, 13, 21 ],
  [ 25, 1, 24, 16 ],
  [ 12, 20, 5, 29 ]
]

vertex_18 = [
  [ 18, 10, 31, 7],
  [ 13, 21, 4, 28 ],
  [ 24, 16, 25, 1 ],
  [ 5, 29, 12, 20 ],
  [ 32, 8, 17, 9 ],
  [ 3, 27, 14, 22 ],
  [ 26, 2, 23, 15 ],
  [ 11, 19, 6, 30 ]
]

vertex_19 = [
  [ 19, 6, 30, 11 ],
  [ 10, 31, 7, 18 ],
  [ 21, 4, 28, 13 ],
  [ 16, 25, 1, 24 ],
  [ 29, 12, 20, 5 ],
  [ 8, 17, 9, 32 ],
  [ 27, 14, 22, 3 ],
  [ 2, 23, 15, 26 ]
]

vertex_20 = [
  [ 20, 5, 29, 12 ],
  [ 9, 32, 8, 17 ],
  [ 22, 3, 27, 14 ],
  [ 15, 26, 2, 23 ],
  [ 30, 11, 19, 6 ],
  [ 7, 18, 10, 31 ],
  [ 28, 13, 21, 4 ],
  [ 1, 24, 16, 25 ]
]

vertex_21 = [
  [ 21, 4, 28, 13 ],
  [ 16, 25, 1, 24 ],
  [ 29, 12, 20, 5 ],
  [ 8, 17, 9, 32 ],
  [ 27, 14, 22, 3 ],
  [ 2, 23, 15, 26 ],
  [ 19, 6, 30, 11 ],
  [ 10, 31, 7, 18 ]
]

vertex_22 = [
  [ 22, 3, 27, 14 ],
  [ 15, 26, 2, 23 ],
  [ 30, 11, 19, 6 ],
  [ 7, 18, 10, 31 ],
  [ 28, 13, 21, 4 ],
  [ 1, 24, 16, 25 ],
  [ 20, 5, 29, 12 ],
  [ 9, 32, 8, 17 ]
]

vertex_23 = [
  [ 23, 15, 26, 2 ],
  [ 6, 30, 11, 19 ],
  [ 31, 7, 18, 10 ],
  [ 4, 28, 13, 21 ],
  [ 25, 1, 24, 16 ],
  [ 12, 20, 5, 29 ],
  [ 17, 9, 32, 8 ],
  [ 14, 22, 3, 27 ]
]

vertex_24 = [
  [ 24, 16, 25, 1 ],
  [ 5, 29, 12, 20 ],
  [ 32, 8, 17, 9 ],
  [ 3, 27, 14, 22 ],
  [ 26, 2, 23, 15 ],
  [ 11, 19, 6, 30 ],
  [ 18, 10, 31, 7],
  [ 13, 21, 4, 28 ]
]

vertex_25 = [
  [ 25, 1, 24, 16 ],
  [ 12, 20, 5, 29 ],
  [ 17, 9, 32, 8 ],
  [ 14, 22, 3, 27 ],
  [ 23, 15, 26, 2 ],
  [ 6, 30, 11, 19 ],
  [ 31, 7, 18, 10 ],
  [ 4, 28, 13, 21 ]
]

vertex_26 = [
  [ 26, 2, 23, 15 ],
  [ 11, 19, 6, 30 ],
  [ 18, 10, 31, 7],
  [ 13, 21, 4, 28 ],
  [ 24, 16, 25, 1 ],
  [ 5, 29, 12, 20 ],
  [ 32, 8, 17, 9 ],
  [ 3, 27, 14, 22 ]
]

vertex_27 = [
  [ 27, 14, 22, 3 ],
  [ 2, 23, 15, 26 ],
  [ 19, 6, 30, 11 ],
  [ 10, 31, 7, 18 ],
  [ 21, 4, 28, 13 ],
  [ 16, 25, 1, 24 ],
  [ 29, 12, 20, 5 ],
  [ 8, 17, 9, 32 ]
]

vertex_28 = [
  [ 28, 13, 21, 4 ],
  [ 1, 24, 16, 25 ],
  [ 20, 5, 29, 12 ],
  [ 9, 32, 8, 17 ],
  [ 22, 3, 27, 14 ],
  [ 15, 26, 2, 23 ],
  [ 30, 11, 19, 6 ],
  [ 7, 18, 10, 31 ]
]

vertex_29 = [
  [ 29, 12, 20, 5 ],
  [ 8, 17, 9, 32 ],
  [ 27, 14, 22, 3 ],
  [ 2, 23, 15, 26 ],
  [ 19, 6, 30, 11 ],
  [ 10, 31, 7, 18 ],
  [ 21, 4, 28, 13 ],
  [ 16, 25, 1, 24 ]
]

vertex_30 = [
  [ 30, 11, 19, 6 ],
  [ 7, 18, 10, 31 ],
  [ 28, 13, 21, 4 ],
  [ 1, 24, 16, 25 ],
  [ 20, 5, 29, 12 ],
  [ 9, 32, 8, 17 ],
  [ 22, 3, 27, 14 ],
  [ 15, 26, 2, 23 ]
]

vertex_31 = [
  [ 31, 7, 18, 10 ],
  [ 4, 28, 13, 21 ],
  [ 25, 1, 24, 16 ],
  [ 12, 20, 5, 29 ],
  [ 17, 9, 32, 8 ],
  [ 14, 22, 3, 27 ],
  [ 23, 15, 26, 2 ],
  [ 6, 30, 11, 19 ]
]

vertex_32 = [
  [ 32, 8, 17, 9 ],
  [ 3, 27, 14, 22 ],
  [ 26, 2, 23, 15 ],
  [ 11, 19, 6, 30 ],
  [ 18, 10, 31, 7],
  [ 13, 21, 4, 28 ],
  [ 24, 16, 25, 1 ],
  [ 5, 29, 12, 20 ]
]

maximals = [ 
  [7, 10, 13, 17, 20, 22, 23, 25, 26, 27, 29, 32],
    [18, 31, 21, 9, 5, 3, 15, 1, 2, 14, 12, 8],
    [10, 7, 4, 32, 29, 27, 26, 24, 23, 22, 20, 17],
    [31, 18, 28, 8, 12, 14, 2, 16, 15, 3, 5, 9],
    [28, 21, 24, 14, 9, 15, 6, 12, 11, 2, 8, 3],
    [13, 4, 16, 22, 32, 26, 30, 20, 19, 23, 17, 27],
    [21, 28, 25, 3, 8, 2, 11, 5, 6, 15, 9, 14],
    [4, 13, 1, 27, 17, 23, 19, 29, 30, 26, 32, 22],
    [1, 16, 5, 23, 22, 30, 31, 17, 18, 19, 27, 26],
    [24, 25, 29, 15, 3, 11, 7, 9, 10, 6, 14, 2],
    [16, 1, 12, 26, 27, 19, 18, 32, 31, 30, 22, 23],
    [25, 24, 20, 2, 14, 6, 10, 8, 7, 11, 3, 15],
    [20, 29, 32, 6, 15, 7, 4, 14, 13, 10, 2, 11],
    [5, 12, 8, 30, 26, 18, 28, 22, 21, 31, 23, 19],
    [29, 20, 17, 11, 2, 10, 13, 3, 4, 7, 15, 6],
    [12, 5, 9, 19, 23, 31, 21, 27, 28, 18, 26, 30],
    [9, 8, 3, 31, 30, 28, 25, 23, 24, 21, 19, 18],
    [32, 17, 27, 7, 11, 13, 1, 15, 16, 4, 6, 10],
    [8, 9, 14, 18, 19, 21, 24, 26, 25, 28, 30, 31],
    [17, 32, 22, 10, 6, 4, 16, 2, 1, 13, 11, 7],
    [22, 27, 26, 4, 7, 1, 12, 6, 5, 16, 10, 13],
    [3, 14, 2, 28, 18, 24, 20, 30, 29, 25, 31, 21],
    [27, 22, 23, 13, 10, 16, 5, 11, 12, 1, 7, 4],
    [14, 3, 15, 21, 31, 25, 29, 19, 20, 24, 18, 28],
    [15, 2, 11, 25, 28, 20, 17, 31, 32, 29, 21, 24],
    [26, 23, 19, 1, 13, 5, 9, 7, 8, 12, 4, 16],
    [2, 15, 6, 24, 21, 29, 32, 18, 17, 20, 28, 25],
    [23, 26, 30, 16, 4, 12, 8, 10, 9, 5, 13, 1],
    [30, 19, 18, 12, 1, 9, 14, 4, 3, 8, 16, 5],
    [11, 6, 10, 20, 24, 32, 22, 28, 27, 17, 25, 29],
    [19, 30, 31, 5, 16, 8, 3, 13, 14, 9, 1, 12],
    [6, 11, 7, 29, 25, 17, 27, 21, 22, 32, 24, 20],
]

vertex_list = [
  vertex_1,
  vertex_2,
  vertex_3,
  vertex_4,
  vertex_5,
  vertex_6,
  vertex_7,
  vertex_8,
  vertex_9,
  vertex_10,
  vertex_11,
  vertex_12,
  vertex_13,
  vertex_14,
  vertex_15,
  vertex_16,
  vertex_17,
  vertex_18,
  vertex_19,
  vertex_20,
  vertex_21,
  vertex_22,
  vertex_23,
  vertex_24,
  vertex_25,
  vertex_26,
  vertex_27,
  vertex_28,
  vertex_29,
  vertex_30,
  vertex_31,
  vertex_32
]

def print_list(list_name,list):
    print(f'{list_name}')
    for element in list:
        print(f'    {element},')


t = rotate_and_translation_set(vertex_list, maximals)

print_list('E', t)
