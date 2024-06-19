#include "include/prografo.h"

/*
 * GRAPH READING AND LOADING FUNCTIONS
 */

/*
 * run_prografo()
 *
 * The main function.
 */

int run_prografo(char* executionType, char* filePath) {
    graph_t* g = prografo_read_dimacs_file(filePath);
    if (g == NULL) {
        printf("Erro: Falha ao ler o grafo do arquivo.\n");
        return 1;
    }

    setlist_t* maximal_list;
    maximal_list = setlist_create(g->n);
    set_t maximum;
    maximum = set_new(g->n);

    set_t* maximum_list = malloc( (1+ (g->n)) * sizeof(set_t));
    for (int i = 0; i < ((g->n) +1); i++) {
		maximum_list[i] = set_new(g->n);
	}

    char* fileName = strrchr(filePath, '/');
    if (fileName == NULL) {
        fileName = filePath; 
    } else {
        fileName++;
    }

    char* ext = strrchr(fileName, '.'); 
    if (ext != NULL) {
        *ext = '\0'; 
    }

    char outputFileName[strlen(fileName) + 12];
    snprintf(outputFileName, sizeof(outputFileName), "%s-result.txt", fileName);

    FILE *arquivo;

    arquivo = fopen(outputFileName, "w");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1; 
    }

    if (strcmp(executionType, "-a") == 0) {
        prografo_maximum_paralel(g, maximum_list);
        fprintf(arquivo, "A razao de independencia do grafo e %d/%d e um conjunto independente maximo e: ", set_size(maximum_list[0]), set_size(g->valid_vertex));
        set_print_new(arquivo, maximum_list[0]);
    } else if (strcmp(executionType, "-b") == 0) {
        prografo_maximum(g, maximum);
        fprintf(arquivo, "A razao de independencia do grafo e %d/%d e um conjunto independente maximo e: ", set_size(maximum), set_size(g->valid_vertex));
        set_print_new(arquivo, maximum);
    } else if (strcmp(executionType, "-c") == 0) {
        prografo_maximals(g, maximal_list, maximum);
        fprintf(arquivo, "A razao de independencia do grafo e %d/%d e os conjuntos independentes maximos sao: \n\n", set_size(maximum), set_size(g->valid_vertex));
        setlist_insertion_sort(maximal_list);
        setlist_print_max(arquivo, maximal_list, set_size(maximum));
    } else if (strcmp(executionType, "-d") == 0) {
        prografo_maximals(g, maximal_list, maximum);
        fprintf(arquivo, "A razao de independencia do grafo e %d/%d e os conjuntos independentes maximais sao: \n\n", set_size(maximum), set_size(g->valid_vertex));
        setlist_insertion_sort(maximal_list);
        setlist_print(arquivo, maximal_list);
    } else {
        printf("Erro: Argumento invalido. Escolha -b, -c ou -d. Argumento passado: %s\n", executionType);
        fclose(arquivo);
        graph_free(g);
        return 1;
    }
  
    fclose(arquivo);
    graph_free(g);

    return 0;
}

/* 
 * prografo_read_dimacs()
 *
 * Reads a graph in DIMACS format from an open file and returns a pointer to the graph data structure.
 */
graph_t *prografo_read_dimacs(FILE *fp) {
	graph_t *g;
	
    g = graph_read_dimacs(fp);

	g->valid_vertex = set_new(g->n);
	for (int i = 0; i < g->n; i++) {
		SET_ADD_ELEMENT(g->valid_vertex, i);
	}

	return g;
}	

/* 
 * prografo_read_dimacs_file()
 *
 * Opens a file with the specified name, reads the graph in DIMACS format from that file,
 * and returns a pointer to the graph data structure.
 */
graph_t *prografo_read_dimacs_file(char *file) {
	FILE *fp;
	graph_t *g;

	ASSERT((sizeof(setelement)*8)==ELEMENTSIZE);
	ASSERT(file!=NULL);

	if ((fp=fopen(file,"rb"))==NULL) {
		perror(file);
		return NULL;
	}
	g=prografo_read_dimacs(fp);
	fclose(fp);

	return g;
}

/* 
 * prografo_reading_file_name()
 *
 * Reads the file name from the standard input and returns the string containing the file name.
 */
char* prografo_reading_file_name() {
    char* fileName = malloc(sizeof(char) * 100);
    if (fileName == NULL) {
        printf("Erro: Falha na alocacao de memoria em prografo_reading_file_name.\n");
        return NULL;
    }

    printf("Digite o nome do arquivo (max. 100 caracteres): ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; 
    return fileName;
}

/* 
 * prografo_reading_file_path()
 *
 * Constructs the full path for a file based on the file name.
 * Assumes that files are located in the "./examples/" directory.
 * Returns the full path.
 */
char* prografo_reading_file_path(const char* file_name) {
    const char* file_path = "./examples/";
    char* full_path = malloc(strlen(file_path) + strlen(file_name) + 1);

    if (full_path == NULL) {
        printf("Erro: Falha na alocacao de memoria em prografo_reading_file_path.\n");
        return NULL;
    }

    strcpy(full_path, file_path);
    strcat(full_path, file_name);
    
    return full_path;
}

/*
 * MEMORY COPY AND RELEASE FUNCTIONS
 */

/*
 * prografo_new()
 *
 * Returns a newly allocated graph with n vertices all with weight 1,
 * no edges and a empty valid_vertex.
 */
graph_t *prografo_new(int n) {
    graph_t* g = graph_new(n); 
    g->valid_vertex=set_new(n);
    return g;
}

/* 
 * prografo_free()
 *
 * Frees the memory associated with the graph 'g'.
 */
void prografo_free(graph_t *g) {
    set_free(g->valid_vertex);
    graph_free(g);
    return;
}

/* 
 * prografo_copy()
 *
 * Creates a deep copy of the input graph 'graph', including edges and valid vertices.
 * Returns the copied graph.
 */
graph_t* prografo_copy(graph_t* graph) {
    graph_t* new_graph = prografo_new(graph->n); 
    
    for (int i = 0; i < graph->n; i++) {
        new_graph->edges[i] = set_copy(new_graph->edges[i], graph->edges[i]);
        if (new_graph->edges[i] == NULL) {
            printf("Erro: Falha na alocacao de memoria em prografo_copy (aresta %d).\n", i);
            prografo_free(new_graph);
            return NULL;
        }
    }

    new_graph->valid_vertex = set_copy(new_graph->valid_vertex, graph->valid_vertex);
    if (new_graph->valid_vertex == NULL) {
        printf("Erro: Falha na alocacao de memoria em prografo_copy (vertices validos).\n");
        prografo_free(new_graph);
        return NULL;
    }

    return new_graph;
}

/*
 * GRAPH MANIPULATION FUNCTIONS
 */

/* 
 * prografo_find_vertex_with_max_edges()
 *
 * Finds the vertex in the graph 'graph' with the highest number of incident edges.
 * Returns the index of that vertex.
 */
int prografo_find_vertex_with_max_edges(graph_t* graph) {
    int max_edges = 0;
    int max_vertex = -1;

    for (int i = 0; i < graph->n; i++) {
        int num_edges = graph_vertex_degree(graph, i);
        if (num_edges > max_edges) {
            max_edges = num_edges;
            max_vertex = i;
        }
    }

    return max_vertex;
}

/* 
 * prografo_delete_edges()
 *
 * Removes all edges incident to vertex 'v' in the graph 'g'.
 */
void prografo_delete_edges(graph_t *g, int v) {
    int i;
    
    for (i = 0; i < g->n; i++) {
        if (i != v) {
            GRAPH_DEL_EDGE(g, i, v);
        }
    }
}

/* 
 * prografo_delete_neighbors_edges()
 *
 * Removes all edges incident to neighbors of vertex 'v' in the graph 'g'
 * and removes those neighbors from the list of valid vertices.
 */
void prografo_delete_neighbors_edges(graph_t *g, int v) {
    set_t edges = g->edges[v];
    for (int i = 0; i < g->n; i++) {
        if (SET_CONTAINS(edges, i)) {
            prografo_delete_edges(g, i);
            SET_DEL_ELEMENT(g->valid_vertex, i);
        }
    }
}

/* 
 * prografo_is_empty()
 *
 * Checks if the graph 'graph' is empty, i.e., it has no edges.
 * Returns true if the graph is empty, false otherwise.
 */
boolean prografo_is_empty(graph_t* graph) {
    return (graph_edge_count(graph) == 0);
}

/*
 * MAXIMAL SETS FUNCTIONS
 */

/* 
 * prografo_maximum()
 *
 * Finds a maximal set in the graph 'g' using a recursive algorithm.
 * The resulting maximal set is stored in 'maximum'.
 */
void prografo_maximum(graph_t *g, set_t maximum) {
    if (g == NULL) {
        printf("Erro: Ponteiro de grafo NULL em prografo_maximum.\n");
        return;
    }

    if (set_size(maximum) >= set_size(g->valid_vertex)) {
        return;
    }
    

    int vertex = prografo_find_vertex_with_max_edges(g);
    
    if (!prografo_is_empty(g)) {
        graph_t *g1 = prografo_copy(g);
        prografo_delete_neighbors_edges(g1, vertex);
        prografo_maximum(g1, maximum);
        prografo_free(g1);

        for (int i = 0; i < g->n; i++) {
            graph_t *g2 = prografo_copy(g);
            if (SET_CONTAINS(g2->edges[vertex], i)) {
                prografo_delete_neighbors_edges(g2, i);
                prografo_maximum(g2, maximum);
            }
            prografo_free(g2);
        }
    } else {
        if (set_size(g->valid_vertex) > set_size(maximum)) {
            maximum = set_copy(maximum, g->valid_vertex); 
        }
    }
}

void prografo_maximum_paralel(graph_t *g, set_t* maximum) {
    if (g == NULL) {
        printf("Erro: Ponteiro de grafo NULL em prografo_maximum.\n");
        return;
    }

    int vertex = prografo_find_vertex_with_max_edges(g);
    int i;

    if (!prografo_is_empty(g)) {
        printf("Número de Ramos para o Loop: %d\n", 1+(g->n));
        int numthreads;
        numthreads=4;
        #pragma omp parallel for default(none) shared(g, vertex, maximum) schedule(dynamic)
        
            for (i = -1; i < g->n; i++) {
                int tid = omp_get_thread_num();
                int total_threads = omp_get_num_threads();

                if ( i==-1 ) {
                    printf("* Executado Item %d de %d\n", i+1, 1+(g->n) );
                    graph_t *g1 = prografo_copy(g);
                    set_t local_maximum = set_new(g->n);
                    prografo_delete_neighbors_edges(g1, vertex);
                    prografo_maximum(g1, local_maximum);
                    prografo_free(g1); 
                    maximum[i+1] = set_copy(maximum[i+1], local_maximum);
                } else {
                    printf("* Executado Item %d de %d da thread %d de %d\n", i+1, 1+(g->n) , tid, total_threads);
                    graph_t *g2 = prografo_copy(g);
                    set_t local_maximum = set_new(g->n);
                    if (SET_CONTAINS(g2->edges[vertex], i)) {
                        prografo_delete_neighbors_edges(g2, i);
                        prografo_maximum(g2, local_maximum);
                        maximum[i+1] = set_copy(maximum[i+1], local_maximum);
                    }
                    prografo_free(g2);
                }
            }
        printf("Concluido o LOOP\n");
    }

    for (int i = 0; i < g->n; i++) {
        if (set_size(maximum[i]) > set_size(maximum[0])) {
            maximum[0] = set_copy(maximum[0], maximum[i]);
        }
    }
}

/* 
 * prografo_maximals()
 *
 * Finds all maximal sets in the graph 'g' and stores them in a list of sets 'maximal_list'.
 * The largest maximal set found is stored in 'maximum'.
 */
void prografo_maximals(graph_t *g, setlist_t* maximal_list, set_t maximum) {
    if (g == NULL) {
        printf("Erro: Ponteiro de grafo NULL em prografo_maximals.\n");
        return;
    }

    int vertex = prografo_find_vertex_with_max_edges(g);
    
    if (!prografo_is_empty(g)) {
        graph_t *g1 = prografo_copy(g);
        prografo_delete_neighbors_edges(g1, vertex);
        prografo_maximals(g1, maximal_list, maximum);
        prografo_free(g1);

        for (int i = 0; i < g->n; i++) {
            graph_t *g2 = prografo_copy(g);
            if (SET_CONTAINS(g2->edges[vertex], i)) {
                prografo_delete_neighbors_edges(g2, i);
                prografo_maximals(g2, maximal_list, maximum);
            }
            prografo_free(g2);
        }
    } else {
        if (!setlist_exists_list(maximal_list, g)) {
            setlist_add_element(maximal_list, g);
            if (set_size(g->valid_vertex) > set_size(maximum)) {
                maximum = set_copy(maximum, g->valid_vertex); 
            }
        }
    }
}

/*
 * PRINTING AND DISPLAY FUNCTIONS
 */

/* 
 * prografo_print_maximal()
 *
 * Prints the number of vertices and the maximal set of the graph 'g' to the standard output.
 */
void prografo_print_maximal(graph_t *g) {
    int i;

    ASSERT((sizeof(setelement) * 8) == ELEMENTSIZE);

    if (g == NULL) {
        printf("Grafo nulo!\n");
        return;
    }
    if (g->n <= 0) {
        printf("Número de vértices do grafo inválido!\n");
        return;
    }

	printf("%d", g->n);
	printf("Conjunto maximal:\n");
	printf("{ ");
    for (i = 0; i < g->n; i++) {
        if (!SET_CONTAINS_FAST(g->valid_vertex, i)) 
			continue;

        printf("%d ", i);
    }
	printf("}\n\n");

    return;
}