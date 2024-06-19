def compare_maximals(maximal_list):
    maximal_A_counter = 1

    for maximal_A in maximal_list:
        similar_maximals = []

        maximal_B_counter = 1

        for maximal_B in maximal_list:
            if len(maximal_A - maximal_B) == 1:
                similar_maximals.append((maximal_B_counter, maximal_B))
            maximal_B_counter += 1

        if len(similar_maximals) > 0:
            print(f'{maximal_A_counter}: {maximal_A}', end='\n')

            for maximal in similar_maximals:
                print(f'    {maximal[0]}: {maximal[1]},', end='\n')

            print('')

        maximal_A_counter += 1
            

            
maximals = [

]

compare_maximals(maximals)