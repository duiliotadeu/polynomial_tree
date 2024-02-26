def unstable_metastable(maximals, edges):
    maximals_copy = [set(maximal) for maximal in maximals]

    for i, maximal in enumerate(maximals_copy):
        maximal_copy = set(maximal.copy())
        unstable = 0
        stable = 1

        for element in maximal:
            if unstable == 1:
                continue

            edge_counter = 0

            for edge in edges[element - 1]:
                if unstable == 1:
                    continue

                if edge:
                    if edge_counter + 1 not in maximal:

                        valid = 1

                        new_maximal = maximal_copy - {element}

                        for element_new in new_maximal:
                            if edges[element_new-1][edge_counter]:
                                print(f'{element} -> {edge_counter + 1} - X', end=', ')
                                valid = 0

                        if valid == 1:
                            new_maximal.add(edge_counter + 1)

                            if new_maximal in maximals_copy:
                                print(f'{element} -> {edge_counter + 1} - V - X', end=', ')
                                stable = 0
                                valid = 0
                                
                            if valid == 1 :
                                print(f'{element} -> {edge_counter + 1} - V - V', end=', ')
                                unstable = 1
                                print(f'\n{maximal}: Instável\n')

                edge_counter += 1

        if not unstable:
            if stable:
                print(f'\n{maximal}: Estável\n')  
            else:
                print(f'\n{maximal}: Metaestável\n')            

edges = [
[0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1],
[1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0],
[0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0],
[1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0],
[0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0],
[1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1],
[0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0],
[0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1],
[0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0],
[0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1],
[1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0],
]

maximals = [
{ 1, 3, 5, 7, },
{ 1, 3, 7, 9, },
{ 1, 3, 8, 9, },
{ 1, 5, 7, 11, },
{ 1, 5, 10, 11, },
{ 1, 7, 9, 11, },
{ 2, 3, 7, 9, },
{ 2, 3, 8, 9, },
{ 2, 3, 8, 12, },
{ 2, 4, 6, 12, },
{ 2, 6, 8, 9, },
{ 2, 6, 8, 12, },
{ 4, 5, 7, 11, },
{ 4, 5, 10, 11, },
{ 4, 5, 10, 12, },
{ 4, 6, 10, 11, },
{ 4, 6, 10, 12, },
{ 6, 8, 10, 12, },
]

unstable_metastable(maximals, edges)