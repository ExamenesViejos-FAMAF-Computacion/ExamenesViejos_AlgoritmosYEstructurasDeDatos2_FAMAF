#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include "character/character.h"
#include <stdbool.h>

typedef struct s_pqueue *pqueue;

/*
 * DESC: Creates a new instance of pqueue
 *
 * PRE: {true}
 *  q = pqueue_empty();
 * POS: {q --> pqueue && pqueue_is_empty(q)}
 *
 */
pqueue pqueue_empty(void);

/*
 * DESC: Adds a character 'character' into the pqueue 'q'
 *
 * PRE: {q --> pqueue}
 *  q = pqueue_enqueue(q, character);
 * POS: {q --> pqueue && !pqueue_is_empty()}
 *
 */
pqueue pqueue_enqueue(pqueue q, Character character);

/*
 * DESC: Indicates whether the pqueue 'q' is empty or not
 *
 * PRE: {q --> pqueue}
 *  empty = pqueue_is_empty(q);
 * POS: {q --> pqueue}
 *
 */
bool pqueue_is_empty(pqueue q);

/*
 * DESC: Returns the number of elements inside the pqueue 'q'
 *
 * PRE: {q --> pqueue}
 *  size = pqueue_size(q);
 * POS: {q --> pqueue}
 *
 */
unsigned int pqueue_size(pqueue q);

/*
 * DESC: Returns the character with the highest priority from the pqueue 'q'
 *
 * PRE: {q --> pqueue && !pqueue_is_empty(q)}
 *  character = pqueue_peek(q);
 * POS: {q --> pqueue}
 *
 */
Character pqueue_peek(pqueue q);

/*
 * DESC: Returns the priority of the character with the highest priority from
 * the pqueue 'q'
 *
 * PRE: {q --> pqueue && !pqueue_is_empty(q)}
 *  priority = pqueue_peek_priority(q);
 * POS: {q --> pqueue}
 */
float pqueue_peek_priority(pqueue q);

/*
 * DESC: Returns a copy of the pqueue 'q'
 *
 * PRE: {q --> pqueue}
 *  copy = pqueue_copy(q);
 * POS: {q --> pqueue && copy --> pqueue}
 *
 */
pqueue pqueue_copy(pqueue q);

/*
 * DESC: Removes the character with the highest priority from the pqueue 'q'
 *
 * PRE: {q --> pqueue && !pqueue_is_empty(q)}
 *  q = pqueue_dequeue(q);
 * POS: {q --> pqueue}
 *
 */
pqueue pqueue_dequeue(pqueue q);

/*
 * DESC: Destroys the instance of pqueue, freeing all memory used by 'q'
 *
 * PRE: {q --> pqueue}
 *  q = pqueue_destroy(q);
 * POS: {q == NULL}
 *
 */
pqueue pqueue_destroy(pqueue q);

#endif