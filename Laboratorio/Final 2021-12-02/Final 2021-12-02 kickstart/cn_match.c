#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "cn_match.h"
#include "card.h"

struct _s_match {
  /*
  * COMPLETAR
  *
  */
};

cn_match match_new(void) {
  /*
  * COMPLETAR
  *
  */
}

cn_match match_add(cn_match match, card c) {
  /*
  * COMPLETAR
  *
  */
}

unsigned int match_size(cn_match match) {
  /*
  * COMPLETAR
  *
  */
}

unsigned int match_length(cn_match match) {
  /*
  * COMPLETAR
  *
  */
}

bool is_match_correct(cn_match match) {
  /*
  * COMPLETAR
  *
  */
}

unsigned int winner_total_points(cn_match match) {
  /*
  * COMPLETAR
  * tips:
  * * recordar que si is_match_correct es falso esto retorna 0
  *
  */
}

card * match_to_array(cn_match match) {
  /*
  * COMPLETAR
  *
  */
}

void match_dump(cn_match match) {
  card *array = match_to_array(match);
  for (unsigned int i=0u; i < match_size(match); i++) {
    card_dump(array[i]);
  }
  free(array);
}

cn_match match_destroy(cn_match match) {
  /*
  * COMPLETAR
  *
  */
}
