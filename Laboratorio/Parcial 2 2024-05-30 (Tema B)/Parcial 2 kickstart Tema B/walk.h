#ifndef WALK_H
#define WALK_H
#include <stdio.h>

typedef struct _walk_t * walk_t;

walk_t walk_empty(void);
/*
 * DESC: Crea una nueva caminata vacía
 * 
 *   walk = walk_empty();
 * POS: {walk --> walk_t && walk_length(walk) == 0}
 */

walk_t walk_north(walk_t walk);
/*
 * DESC: Agrega un paso al norte a una caminata walk
 *
 * PRE: {walk --> walk_t}
 *   walk = walk_north(walk);
 * POS: {walk --> walk_t && walk_length(walk) > 0}
 *
 */

walk_t walk_east(walk_t walk);
/*
 * DESC: Agrega un paso al este a una caminata walk
 *
 * PRE: {walk --> walk_t}
 *   walk = walk_east(walk);
 * POS: {walk --> walk_t && walk_length(walk) > 0}
 *
 */

walk_t walk_northeast(walk_t walk);
/*
 * DESC: Agrega un paso al noreste a una caminata walk
 *
 * PRE: {walk --> walk_t}
 *   walk = walk_northeast(walk);
 * POS: {walk --> walk_t && walk_length(walk) > 0}
 *
 */

unsigned int walk_length(walk_t walk);
/*
 * DESC: Calcula la longitud de una caminata
 *
 * PRE: {walk --> walk_t}
 *   length = walk_length(walk);
 * POS: {walk --> walk_t}
 *
 */

unsigned int walk_height(walk_t walk);
/*
 * DESC: Calcula la altura de una caminata
 *
 * PRE: {walk --> walk_t}
 *   length = walk_height(walk);
 * POS: {walk --> walk_t}
 *
 */

unsigned int walk_width(walk_t walk);
/*
 * DESC: Calcula el ancho de una caminata
 *
 * PRE: {walk --> walk_t}
 *   length = walk_width(walk);
 * POS: {walk --> walk_t}
 *
 */

walk_t walk_extend(walk_t walk, unsigned int east, unsigned int north);
/*
 * DESC: Extiende la caminata un cierto número de pasos al este y un 
 * cierto número de pasos al norte.
 *
 * PRE: {walk --> walk_t}
 *   walk = walk_extend(walk, e, n);
 * POS: {walk --> walk_t && (walk_length(walk) > 0 || (e == 0 && n == 0))}
 *
 */

void walk_dump(walk_t walk);
/*
 * DESC: Imprime en pantalla la caminata 
 *
 * PRE: {walk --> walk_t}
 *   walk_dump(walk);
 * POS: {walk --> walk_t}
 *
 */

walk_t walk_destroy(walk_t walk);
/*
 * DESC: Destruye la instancia liberando toda la memoria usada
 *
 * PRE: {walk --> walk_t}
 *   walk = walk_destroy(walk);
 * POS: {walk == NULL}
 *
 */

#endif
