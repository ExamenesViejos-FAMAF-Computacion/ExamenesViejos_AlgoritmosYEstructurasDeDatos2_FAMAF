#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    /* COMPLETAR */
};

struct s_node {
    /* COMPLETAR */
};

static struct s_node * create_node(pstack_elem e) {
    struct s_node *new_node = NULL;
    assert(new_node!=NULL);
    /* COMPLETAR */
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    /* COMPLETAR */
    return node;
}


static bool invrep(pstack s) {
    return true;
}

pstack pstack_empty(priority_t max_priority) {
    pstack s=NULL;
    /* COMPLETAR */
    assert(invrep(s) && pstack_is_empty(s));
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    /* COMPLETAR */
    assert(invrep(s) && !pstack_is_empty(s));
    return s;
}

bool pstack_is_empty(pstack s) {
    assert(invrep(s));
    /* COMPLETAR */
    return 0u;
}

pstack_elem pstack_top(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETAR */
    return 0u;
}

priority_t pstack_top_priority(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETAR */
    return true;
}

size_t pstack_size(pstack s) {
    assert(invrep(s));
    /* COMPLETAR */
    return 0u;
}

pstack pstack_pop(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETAR */
    assert(invrep(s));
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    /* COMPLETAR */
    return s;
}
