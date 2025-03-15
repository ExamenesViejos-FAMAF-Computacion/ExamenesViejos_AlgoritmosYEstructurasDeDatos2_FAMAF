#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>            /* Definition of bool      */
#include <assert.h>


#include "ugraph.h"

struct s_node {
    vertex elem;
    struct s_node *next;
    struct s_node *succ;

};

typedef struct s_node *node_t;

struct s_ugraph {
    unsigned int size;
    node_t first;
};


static bool invrep1(ugraph g){
	//about main structre consistency
	return g!=NULL;
}

static bool invrep2(ugraph g){
	//about graph size consistency
	node_t node = g->first;
	unsigned int n = 0;
    while (node!=NULL) {
        node = node->next;
        n++;
    }
    return n == g->size;
}

static bool invrep3(ugraph g){
	//about uniqueness of vertexes
	/* COMPLETAR!!! */
}

static bool invrep(ugraph g){
	return invrep1(g) && invrep2(g) && invrep3(g);
}


static node_t create_node(vertex v){
	/* COMPLETAR!!! */
}


static node_t destroy_node(struct s_node *node){
	/* COMPLETAR!!! */
}

static node_t ugraph_get_node(ugraph g,vertex v){
	/*Returns the node of the vertex v*/
	assert(invrep(g) && ugraph_member(g,v));
	node_t node = g->first;
	while (node!=NULL && node->elem != v) {
		node = node->next;
	}
	assert(invrep(g));
	return node;
}


/****************** CONSTRUCTORS ******************/
ugraph ugraph_empty(void) {
	/* COMPLETAR!!! */
}

ugraph ugraph_add_vertex(ugraph g, vertex v) {
	/* COMPLETAR!!! */
}


ugraph ugraph_add_edge(ugraph g, vertex v1, vertex v2){
	/* COMPLETAR!!! */
}


/******************* OPERATIONS   *******************/
unsigned int ugraph_size(ugraph g){
	assert(invrep(g));
    return g->size;
}

bool ugraph_is_empty(ugraph g){
	assert(invrep(g));
    return g->size==0;
}

bool ugraph_member(ugraph g, vertex v) {
	/* COMPLETAR!!! */
}


vertex ugraph_succ(ugraph g, vertex v){
	assert(invrep(g) && ugraph_get_node(g,v)->succ !=NULL);
	node_t node_v = ugraph_get_node(g,v);
	assert(invrep(g));
	return node_v->succ->elem;
}

ugraph ugraph_delete_incoming_edge(ugraph g, vertex v){
	assert(invrep(g));
	if (ugraph_member(g,v)){
		node_t node_v = ugraph_get_node(g,v);
		node_t node = g->first;
		while (node!=NULL){
			if (node->succ == node_v){
				node->succ = NULL;
			}
			node = node->next;
		}
	}
	assert(invrep(g));
	return g;		
}

ugraph ugraph_delete_outcoming_edge(ugraph g, vertex v){
	assert(invrep(g) && ugraph_member(g,v));
	node_t node_v = ugraph_get_node(g,v);
	node_v->succ = NULL;
	assert(invrep(g) && ugraph_get_node(g,v)->succ == NULL);
	return g;		
}


ugraph ugraph_delete_vertex(ugraph g, vertex v){
	/* COMPLETAR!!! */
}



bool ugraph_path(ugraph g, vertex v1, vertex v2){
	/* COMPLETAR!!! */
}



ugraph ugraph_destroy(ugraph g){
	/* COMPLETAR!!! */
}



void ugraph_dump(ugraph g){
	assert(invrep(g));
    // prints the set of vertexes of the unary graph g
    node_t node = g->first;
    printf("Vertexes: ");
    while (node!=NULL ) {
	   printf("%d ", node->elem);
        node = node->next;
    }
    printf("\n");
    // prints the list of edges of the unary graph g
    printf("Edges: \n");
    node = g->first;
    while (node!=NULL ) {
    	if (node->succ != NULL) {
        	printf("\t%d --> %d\n", node->elem, node->succ->elem);
        }
        node = node->next;
    }
   	assert(invrep(g));
}


ugraph ugraph_from_file(const char *filepath){
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

	//read ugraph size
	int size;
    int res = fscanf(file,"%d", &size);
    if (res != 1) {
    	fprintf(stderr, "Invalid unary graph.\n");
        exit(EXIT_FAILURE);
    }
        
	//load ugraph vertexes
    ugraph g=ugraph_empty();
    int i = 1;
    while (i<=size){
        int elem;
        int res = fscanf(file,"%d", &elem);
        if (res != 1) {
            fprintf(stderr, "1-Invalid unary graph.\n");
            exit(EXIT_FAILURE);
        }
        g = ugraph_add_vertex(g, elem);
        i++;
	}
	//load ugraph edges
    while (!feof(file)){
        	/* COMPLETAR!!! */
    }
   
    fclose(file);
   	assert(invrep(g));
    return g;
}


/*SOLO PARA ALUMNOS LIBRES!!!*/
	/*bool ugraph_cycle(ugraph g){
       	COMPLETAR!!! 
	}*/




