#ifndef _UGRAPH_H_
#define _UGRAPH_H_

#include <stdbool.h>            /* Definition of bool      */

typedef int vertex;

typedef struct s_ugraph *ugraph;

/* CONSTRUCTORS */

ugraph ugraph_empty(void);
/*
  Creates a new empty ugraph
 
  g = ugraph_empty()
 
  POS: {g --> ugraph && ugraph_is_empty(g)}
 
*/

ugraph ugraph_add_vertex(ugraph g, vertex v);
/*
 Adds vertex <v>  to the ugraph <g>. If <v> was already in <g>
 the function makes no changes.

 PRE: {g --> ugraph}
 
 g = ugraph_add_vertex(g, v);

 POS: {g --> ugraph && !ugraph_is_emtpy(g)}
*/


ugraph ugraph_add_edge(ugraph g, vertex v1, vertex v2);
/*
 Adds a edge from vertex v1 to vertex v2 
If v1 has a outcomoing edge, then it replaced by new one. 

 PRE: {g --> ugraph && ugraph_member(g,v1) && ugraph_member(g,v2) }
 
 g = ugraph_add_edge(g, v1,v2);

 POS: {g --> ugraph && v2 = ugraph_succ(v1)}
*/


/* OPERATIONS   */

bool ugraph_is_empty(ugraph g);
/*
 Indicates if the ugraph <g> is empty.

 PRE: {g --> ugraph}

 b = ugraph_is_empty(g);

*/



unsigned int ugraph_size(ugraph g);
/*
 Returns how many vertexes are in <g>

 PRE: {g --> ugraph}

 n = ugraph_size(g);

 POS: {(n == 0) == ugraph_is_empty(g)}
*/


bool ugraph_member(ugraph g, vertex v);
/*
 Indicates if the vertex <v> is in the ugraph <g>.

 PRE: {g --> ugraph}

 b = ugraph_member(g,v);

*/
vertex ugraph_succ(ugraph g, vertex v);
/*
 Returns the unique succesor of vertex <v> in ugraph <g>

 PRE: {g --> ugraph && ugraph_get_node(g,v)->succ !=NULL}

 w = ugraph_succ(g,v);

 POS: {g --> ugraph &&  ugraph_get_node(g,v)->succ->elem = w }
*/


ugraph ugraph_delete_incoming_edge(ugraph g, vertex v);
/*
 Deletes all edges to vertex <v>.

 PRE: {g --> ugraph}

 g = ugraph_delete_outcoming_edge(g,v);

 POS: {g --> ugraph && for all w: w->v: ugraph_get_node(g,w)->succ == NULL}
*/



ugraph ugraph_delete_outcoming_edge(ugraph g, vertex v);
/*
 Deletes the unique edges from v to another vertex.

 PRE: {g --> ugraph}

 g = ugraph_delete_outcoming_edge(g,v);

 POS: {g --> ugraph && ugraph_get_node(g,v)->succ == NULL}
*/




ugraph ugraph_delete_vertex(ugraph g, vertex v);
/*
 Eliminates vertex <v> of the ugraph <g>. 
The functions also deletes the edge that arrives to <v> if this exists.If <v> was not present in <g> the function makes no changes. 

 {g --> ugraph}

 g = ugraph_delete(g, v);

 {g --> ugraph && !ugraph_member(g, v) && for all w: w!=v: ugraph_succ(g,w) != v }

*/



bool ugraph_path(ugraph g, vertex v1, vertex v2);
/*
 Indicates if <g> has a path from vertex <v1> to vertex <v2>, 
 i.e if exists wi such that v1 = w1 -> .... -> wk = v2 in <g>

 PRE: {g --> ugraph && ugraph_member(g,v)}

 b = ugraph_path(g, v1,v2);

 POS: {g --> ugraph && b = exist wi: i=1,...,k: ugraph_succ(g,vi) = vi+1 && v1 = w1 && v1 = wk>}
*/



ugraph ugraph_from_file(const char *filepath);
/*
    Each element is read from the file located at 'filepath'.
    The file must exist in disk and must have its contents in the following
    format:

	<n>
    <vertex_1> <vertex_2> <vertex_3> ... <vertex_n>
    <vertex_1> --> <vertex_2>
	<vertex_2> --> <vertex_3>
	<vertex_3> --> <vertex_3>
	...
	
    Those vertexes are stored in a new instance of unary graph.

    If something goes wrong in loading process, the funciton aborts.

    Returns the instance of ugraph where the vertexes were loaded. 

	PRE: {the file <filepath> is well formed}
	
	g = ugraph_from_file(filepath)
	
	POS: {g --> ugraph} 
*/


void ugraph_dump(ugraph g);
/*
 Prints the ugraph <g> in the stdout with the following format: 
 Vertexes: v1 ... vk
 Edeges:
 	v1 -> v2
 	v4 -> v5
 	v2 -> v7
 	...
 
 PRE: {g --> ugraph}
 
 ugraph_dump(g);

 POS: {g --> ugraph}
*/


ugraph ugraph_destroy(ugraph g);
/*
 Destroy the ugraph <g> freeing all memory used by the data structure

 PRE: {g --> ugraph}

 g = ugraph_destroy(g);

 POS: {g == NULL}

*/



/********** SOLO PARA ALUMNOS LIBRES!!! **********/
/* bool ugraph_cycle(ugraph g);
 Indicates if <g> has a cycle, i.e if exists v such that v -> v1 -> .... -> vk -> v in <g>

 PRE: {g --> ugraph && ugraph_member(g,v)}

 b = ugraph_cycle(g, v);

 POS: {g --> ugraph && b = exist vi: i=1,...,k: ugraph_succ(g,vi) = vi+1 && v1 = v && vk = v>}
*/




#endif
