#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "stringbuffer.h"

struct s_stringbuffer {
    struct s_node *first;
    struct s_node *last;
    /*
     * COMPLETAR
     */
};

struct s_node {
    char c;
    struct s_node *nextchar;
};

typedef struct s_node * node_t;

// Representation invariant
static bool invrep(stringbuffer sb) {
    bool valid=false;
    /*
     * COMPLETAR
     *
     */
    return valid;
}


// Creates a single node in dynamic memory with a given char
static node_t create_node(char c) {
    node_t newnode=NULL;    
    /*
     * COMPLETAR
     *
     */
    assert(newnode!=NULL);
    return newnode;
}


// Destroy a single node
static node_t destroy_node(node_t node) {
    /*
     * COMPLETAR
     *
     */
    assert(node==NULL);
    return node;
}


// Public functions of the Abstract Data Type
stringbuffer stringbuffer_empty(void) {
    /*
     * COMPLETAR
     *
     */
}


stringbuffer stringbuffer_create(const char *word) {
    assert(word!=NULL);
    node_t newnode = NULL;
    node_t first = NULL;
    node_t last = NULL;

    /*
     * COMPLETAR
     *
     */
    assert(invrep(sb) && !stringbuffer_is_empty(sb));
    return sb;
}


bool stringbuffer_is_empty(stringbuffer sb){
    /*
     * COMPLETAR
     *
     */
}


stringbuffer stringbuffer_append(stringbuffer sb, const char c) {
    /*
     * COMPLETAR
     *
     */ 
}


char stringbuffer_char_at(stringbuffer sb, unsigned int index) {
    assert(invrep(sb) && !stringbuffer_is_empty(sb) && index<stringbuffer_length(sb));
    unsigned pos = 0;
    node_t node = sb->first;
    while(pos < index) {
        node = node->nextchar;
        pos++;
    }
    return node->c;
}


stringbuffer stringbuffer_remove(stringbuffer sb, unsigned int index) {
    assert(invrep(sb));
    node_t node=sb->first, prev=NULL;
    unsigned pos = 0;
    /*
     * COMPLETAR
     *
     */    
    assert(invrep(sb));
    return sb;
}


stringbuffer stringbuffer_replace(stringbuffer sb, const char c, unsigned int index) {
    /*
     * COMPLETAR
     *
     */
}


unsigned int stringbuffer_length(stringbuffer sb) {
    /*
     * COMPLETAR
     *
     */
}


char* stringbuffer_to_string(stringbuffer sb) {
    /*
     * COMPLETAR
     *
     */
}


void stringbuffer_dump(stringbuffer sb) {
    assert(invrep(sb));
    node_t node = sb->first;
    while (node != NULL) {
        printf("%c", node->c);
        node = node->nextchar;
    }
    printf("\n");
}


stringbuffer stringbuffer_destroy(stringbuffer sb) {
    /*
     * COMPLETAR
     *
     */
}
