#include <stdlib.h>
#include <assert.h>

#include "stack.h"

#define CHUNK_CAPACITY 5

struct s_node {
    // COMPLETAR
    struct s_node *top;
};

struct _s_stack {
    // COMPLETAR
};

static bool
valid_chunks(stack s) {
    bool valid=true;
    struct s_node *check=s->top;
    if (check!=NULL) {
        // Completar
    }
    return valid;
}

static bool
invrep(stack s) {
    // COMPLETAR
    return (s!=NULL && valid_chunks(s));
}

static struct s_node *
create_node(void) {
    /*
     * COMPLETAR
     *
     */
}


static struct s_node *
destroy_node(struct s_node *node) {
    /*
     * COMPLETAR
     *
     */
}

stack stack_empty(void) {
}


stack stack_push(stack s, stack_elem e) {
    /*
     * COMPLETAR
     *
     */
}


stack stack_pop(stack s) {
    /*
     * COMPLETAR
     *
     */
}


unsigned int stack_size(stack s) {
    /*
     * COMPLETAR
     *
     */
}

void stack_top(stack s, stack_elem *top) {
    /*
     * COMPLETAR
     * 
     */
}

bool stack_is_empty(stack s) {
    /*
     * COMPLETAR
     *
     */
}

stack_elem *stack_to_array(stack s) {
    /*
     * COMPLETAR
     *
     */
}


stack stack_destroy(stack s) {
    /*
     * COMPLETAR
     *
     */
}

