import math

def remove_duplicates(maximals):
    unique_maximals = []
    for maximal in maximals:
        add = True
        for unique_maximal in unique_maximals:
            if sorted(list(maximal)) == sorted(list(unique_maximal)):
                add = False
                break  

        if add:
            unique_maximals.append(maximal)

    return unique_maximals


def rotation_and_translation(vertex_list, maximals):
  i = 0
  transformated_sets = []

  for j in range(len(vertex_list[0])):
    for k in range(len(vertex_list[0][0])):
      for maximal in maximals:
        transformated_set = []
        for element in maximal:
          i = element-1
          transformated_set.append(vertex_list[i][j][k])

          transformated_sets.append(transformated_set)

        tmp_vertical = []
        tmp_horizontal = []
        tmp_diagonal = []

        for element in maximal:
          tmp_vertical_element = vertical_reflection[element-1]
          tmp_horizontal_element = horizontal_reflection[element-1]
          tmp_diagonal_element = diagonal_reflection[element-1]

          tmp_vertical.append(tmp_vertical_element)
          tmp_horizontal.append(tmp_horizontal_element)
          tmp_diagonal.append(tmp_diagonal_element)

        transformated_sets.append(tmp_vertical)
        transformated_sets.append(tmp_horizontal)  
        transformated_sets.append(tmp_diagonal)    
  
  return remove_duplicates(transformated_sets)

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

vertical_reflection = [
    30, 29, 32, 31, 26, 25, 28, 27, 22, 21, 24, 23, 18, 17, 20, 19, 14, 13, 16, 15, 10, 9, 12, 11, 6, 5, 8, 7, 2, 1, 4, 3 
]

horizontal_reflection = [
    24, 23, 22, 21, 20, 19, 18, 17, 32, 31, 30, 29, 28, 27, 26, 25, 8, 7, 6, 5, 4, 3, 2, 1, 16, 15, 14, 13, 12, 11, 10, 9
]

diagonal_reflection = [
    16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17
]

maximals = [ 
  [1, 4, 5, 12, 13, 16, 19, 22, 23, 26, 27, 30],
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

maximals = rotation_and_translation(vertex_list, maximals)
maximals = rotation_and_translation(vertex_list, maximals)
maximals_to_print = rotation_and_translation(vertex_list, maximals)

for maximal in maximals_to_print:
  print(f'{maximal},')