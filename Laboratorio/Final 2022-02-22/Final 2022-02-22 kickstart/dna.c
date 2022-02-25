#include "dna.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct _node {
    nucleobase_t elem;
    struct _node *next;
};

struct _dna_t
{
    struct _node* chain;
    unsigned int lenght;
};

static struct _node* single_node(nucleobase_t e)
{
    struct _node *node = calloc(1, sizeof(struct _node));
    assert(node != NULL);
    node->elem = e;
    node->next = NULL;
    return (node);
}

dna_t dna_T()
{
    dna_t res = NULL;
    /** COMPLETAR ACÁ */
    return res;
}

dna_t dna_C()
{
    dna_t res = NULL;
    /** COMPLETAR ACÁ */
    return res;
}

dna_t dna_A()
{
    dna_t res = NULL;
    /** COMPLETAR ACÁ */
    return res;
}

dna_t dna_G()
{
    dna_t res = NULL;
    /** COMPLETAR ACÁ */
    return res;
}


dna_t dna_join(dna_t first, dna_t second)
{
    dna_t res = NULL;
    /** COMPLETAR ACÁ */
    return res;
}

unsigned int dna_length(dna_t dna)
{
    unsigned int res = 0u;
    /** COMPLETAR ACÁ */
    return res;
}

void dna_print(dna_t dna)
{
    /** COMPLETAR ACÁ */
}

bool dna_is_prefix(dna_t first, dna_t second)
{
    bool is_prefix = false;
    /** COMPLETAR ACÁ */
    return is_prefix;
}

bool dna_is_equal(dna_t first, dna_t second)
{
    bool is_equal = false;
    /** COMPLETAR ACÁ */
    return is_equal;
}

dna_t *dna_cut(dna_t dna, unsigned int count)
{
    dna_t* res = NULL;
    /** COMPLETAR ACÁ */
    return res;
}

dna_t dna_destroy(dna_t dna)
{
    /** COMPLETAR ACÁ */
    return dna;
}
