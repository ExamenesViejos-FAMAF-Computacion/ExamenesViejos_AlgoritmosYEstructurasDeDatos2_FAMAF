#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "domino_line.h"
#include "domino.h"

struct _s_line {
    /*
     * COMPLETAR
     *
     */
};

domino_line line_new(domino first) {
    /*
     * COMPLETAR
     *
     */
}

domino_line line_add(domino_line line, domino t) {
    /*
     * COMPLETAR
     *
     */
}

unsigned int line_length(domino_line line) {
    /*
     * COMPLETAR
     *
     */
}

bool line_n_correct(domino_line line, unsigned int n) {
    /*
     * COMPLETAR
     *
     */
}

int line_total_points(domino_line line) {
    /*
     * COMPLETAR
     *
     */
}

domino * line_to_array(domino_line line) {
    /*
     * COMPLETAR
     *
     */
}

void line_dump(domino_line line) {
    domino *array=line_to_array(line);
    for (unsigned int i=0u; i < line_length(line); i++) {
        domino_dump(array[i]);
    }
    free(array);
}

domino_line line_destroy(domino_line line) {
    /*
     * COMPLETAR
     *
     */
}

