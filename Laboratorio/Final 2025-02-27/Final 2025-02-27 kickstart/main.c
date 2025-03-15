#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "ugraph.h"



void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n", program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[]) {
	char *filepath = NULL;

	/* parse the filepath given in command line arguments */
	filepath = parse_filepath(argc, argv);

	/* parse the file to build a ugraph instance*/
	ugraph g = ugraph_from_file(filepath);
	ugraph_dump(g);
	
	int v1 = 2, v2=10, v3 =8;
	printf("El grafo unario %s tiene un camino del vertice %d al vertice %d.\n", ugraph_path(g,v1,v2)? "SI":"NO", v1,v2);
	
	ugraph_delete_vertex(g,v3);
	printf("Si eliminamos el vertice %d, el grafo unario %s tiene un camino del vertice %d al vertice %d.\n", v3, ugraph_path(g,v1,v2)? "SI":"NO", v1,v2);

	g = ugraph_destroy(g);


	
	/**************** Testing Extra solo para alumnos Libres (DESCOMENTAR) ****************/
	/* g = ugraph_from_file(filepath);	
	printf("****************** Solo Libres ******************\n");
	printf("El grafo unario %s tiene ciclo.\n", ugraph_cycle(g)? "SI":"NO");
	
	ugraph_delete_vertex(g,v3);
	printf("Si eliminamos el vertice %d, el grafo unario %s tiene ciclo.\n", v3, ugraph_cycle(g)? "SI":"NO");

	g = ugraph_destroy(g);*/
  
  return EXIT_SUCCESS;
}
