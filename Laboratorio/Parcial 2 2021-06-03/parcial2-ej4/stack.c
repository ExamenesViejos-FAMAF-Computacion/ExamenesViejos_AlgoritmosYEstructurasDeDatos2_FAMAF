#include <stdlib.h>
#include "assert.h"
#include "stack.h"

struct _s_stack {
    stack_elem elem;
    stack next;
};

stack stack_empty() {
    return NULL;
}

stack stack_push(stack s, stack_elem e) {
    stack new = calloc(1, sizeof(struct _s_stack));
    assert(new != NULL);
    new->elem = e;
    if (s == NULL) {
        s = new;
    } else {
        stack last=s;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
    return s;
}

stack stack_pop(stack s) {
    assert(s != NULL);
    /*
     * COMPLETAR
     *
     */
    return s;
}

unsigned int stack_size(stack s) {
    unsigned int count = 0;
    stack aux = s;
    while (aux != NULL) {
        aux = aux->next;
        ++count;
    }
    return count;
}

stack_elem stack_top(stack s) {
    assert(s != NULL);
    stack_elem e;
    /*
     * COMPLETAR
     *
     */
    return e;
}

bool stack_is_empty(stack s) {
    return (s == NULL);
}

stack stack_destroy(stack s) {
    stack aux = s;
    while (!stack_is_empty(aux)) {
        aux = stack_pop(aux);
    }
    return NULL;
}
