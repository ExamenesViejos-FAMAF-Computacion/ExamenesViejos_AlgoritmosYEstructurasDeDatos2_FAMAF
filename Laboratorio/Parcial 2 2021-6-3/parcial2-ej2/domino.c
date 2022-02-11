#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "domino.h"

struct _s_domino {
    /*
     * COMPLETAR
     *
     */
};


/* auxiliary functions for dumping */

static char mark(bool b) {
    return b ? 'O' : ' ';
}

static void dump_num(int num) {
  printf("      | %c     %c |\n",
         mark(num > 1), mark(num > 3));
  printf("      | %c  %c  %c |\n",
         mark(num > 5), mark(num % 2 == 1), mark(num > 5));
  printf("      | %c     %c |\n",
         mark(num > 3), mark(num > 1));
}

static void dump_double_num(int num) {
  printf(" --------------------- \n");
  printf(" | %c  %c  %c ", mark(num > 3), mark(num > 5), mark(num > 1));
  printf( "| %c  %c  %c |\n", mark(num > 3), mark(num > 5), mark(num > 1));

  printf(" |    %c    ", mark(num % 2 == 1));
  printf( "|    %c    |\n", mark(num % 2 == 1));

  printf(" | %c  %c  %c ", mark(num > 1), mark(num > 5), mark(num > 3));
  printf( "| %c  %c  %c |\n", mark(num > 1), mark(num > 5), mark(num > 3));
  printf(" --------------------- \n");
}

void dump(int num_up, int num_down) {
    /* Pretty dump funcion for cool visualization :) */
    if (num_up != num_down)  {
        printf("      ----------- \n");
        dump_num(num_up);
        printf("      |---------| \n");
        dump_num(num_down);
        printf("      ----------- \n");
    } else {
        dump_double_num(num_up);
    }
}

/* Representation invariant */

static bool invrep(domino p) {
    bool valid_domino=false;
    /*
     * COMPLETAR
     *
     */
    return valid_domino;
}

/* Public functions */

domino domino_new(int num_up, int num_down) {
    domino p;
    /*
     * COMPLETAR
     *
     */
    return p;
}

bool domino_is_double(domino p) {
    bool is_double=false;
    /*
     * COMPLETAR
     *
     */
    return is_double;
}

bool domino_eq(domino p1, domino p2) {
    bool equals=false;
    /*
     * COMPLETAR
     *
     */
    return equals;
}

bool domino_matches(domino p_top, domino p_bottom) {
    bool is_match=false;
    /*
     * COMPLETAR
     *
     */
    return is_match;
}

domino domino_flip(domino p) {
    /*
     * COMPLETAR
     *
     */
    return p;
}

void domino_dump(domino p) {
    /*
     * COMPLETAR ( llamar a la función local dump() )
     *
     */
}

domino domino_destroy(domino p) {
    /*
     * COMPLETAR
     *
     */
    return p;
}

