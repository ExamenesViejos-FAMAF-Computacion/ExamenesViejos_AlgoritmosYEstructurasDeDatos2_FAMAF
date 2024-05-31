#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "character/character.h"
#include "pqueue.h"

/* ============================================================================
STRUCTS!
============================================================================ */

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

/* ============================================================================
INVREP
============================================================================ */

static bool invrep(pqueue q) {
  /*
   * COMPLETAR
   *
   */
  return true;
}

/* ============================================================================
NEW
============================================================================ */

pqueue pqueue_empty(void) {
  pqueue q = NULL;
  /*
   * COMPLETAR
   *
   */
  return q;
}

/* ============================================================================
ENQUEUE
============================================================================ */

static float calculate_priority(Character character) {
  /*
   * COMPLETAR
   *
   */
  return 0.0;
}

static struct s_node *create_node(Character character) {
  struct s_node *new_node = NULL;
  float priority = calculate_priority(character);
  new_node = malloc(sizeof(struct s_node));
  assert(new_node != NULL);
  /*
   * COMPLETAR
   *
   */
  return new_node;
}

pqueue pqueue_enqueue(pqueue q, Character character) {
  assert(invrep(q));
  struct s_node *new_node = create_node(character);
  /*
   * COMPLETAR
   *
   */
  return q;
}

/* ============================================================================
IS EMPTY?
============================================================================ */

bool pqueue_is_empty(pqueue q) {
  /*
   * COMPLETAR
   *
   */
  return true;
}

/* ============================================================================
PEEKS
============================================================================ */

Character pqueue_peek(pqueue q) {
  /*
   * COMPLETAR
   *
   */
  return NULL;
}

float pqueue_peek_priority(pqueue q) {
  /*
   * COMPLETAR
   *
   */
  return 0.0;
}

/* ============================================================================
SIZE
============================================================================ */

unsigned int pqueue_size(pqueue q) {
  assert(invrep(q));
  unsigned int size = 0;
  /*
   * COMPLETAR
   */

  return size;
}

/* ============================================================================
COPY
============================================================================ */

pqueue pqueue_copy(pqueue q) {
  assert(invrep(q));
  /*
   * COMPLETAR
   */
  return NULL;
}

/* ============================================================================
DESTROY!
============================================================================ */
static struct s_node *destroy_node(struct s_node *node) {
  assert(node != NULL);
  /*
   * COMPLETAR
   *
   */
  assert(node == NULL);
  return node;
}

pqueue pqueue_dequeue(pqueue q) {
  assert(invrep(q));
  /*
   * COMPLETAR
   */
  return q;
}

pqueue pqueue_destroy(pqueue q) {
  /*
   * COMPLETAR
   */
  assert(q == NULL);
  return q;
}
