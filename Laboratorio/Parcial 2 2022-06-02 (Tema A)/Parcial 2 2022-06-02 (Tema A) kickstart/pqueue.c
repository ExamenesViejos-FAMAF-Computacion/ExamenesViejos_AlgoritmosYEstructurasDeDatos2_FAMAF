#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    /*
     * COMPLETAR
     *
     */
};

struct s_node {
    /*
     * COMPLETAR
     *
     */
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;
    // Completar
    assert(new_node!=NULL);
    /*
     * COMPLETAR
     */
    assert(e==e && priority == priority); // BORRAR ESTE ASSERT
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    /*
     * COMPLETAR
     *
     */
    assert(node == NULL);
    return node;
}


static bool invrep(pqueue q) {
    /*
     * COMPLETAR
     *
     */
    assert(q==q); // BORRAR ESTE ASSERT
    return true;
}

pqueue pqueue_empty(void) {
    pqueue q=NULL;
    /*
     * COMPLETAR
     *
     */
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    /*
     * COMPLETAR
     *
     */
    assert(e==e && priority==priority && new_node==new_node); // BORRAR ESTE ASSERT
    return q;
}

bool pqueue_is_empty(pqueue q) {
    /*
     * COMPLETAR
     *
     */
    assert(q==q); // BORRAR ESTE ASSERT
    return true;
}

pqueue_elem pqueue_peek(pqueue q) {
    /*
     * COMPLETAR
     *
     */
    assert(q==q); // BORRAR ESTE ASSERT
    return 0;
}

unsigned int pqueue_peek_priority(pqueue q) {
    /*
     * COMPLETAR
     *
     */
    assert(q==q); // BORRAR ESTE ASSERT
    return 0;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    unsigned int size=0;
    /*
     * COMPLETAR
     *
     */

    return size;
}

pqueue pqueue_dequeue(pqueue q) {
    /*
     * COMPLETAR
     *
     */
    assert(q==q); // BORRAR ESTE ASSERT
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    /*
     * COMPLETAR
     *
     */
    assert(q == NULL);
    return q;
}
