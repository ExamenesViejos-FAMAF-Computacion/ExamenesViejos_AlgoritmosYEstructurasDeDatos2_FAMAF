#include <stdio.h>
#include <assert.h>
#include "domino.h"

domino scan_domino(void) {
    int up, down, readed;
    printf("Ingrese los valores de un domino (up:down): ");
    readed = scanf("%d:%d", &up, &down);
    return readed == 2 ? domino_new(up, down) : NULL;
}

unsigned int chain_dominoes(domino pieces[], unsigned int size) {
    bool is_match=true;
    unsigned int match_count=1;  // Counts how many matches were made
    unsigned int i=0;
    assert(size > 0 && domino_is_double(pieces[0]));
    while (is_match && i + 1 < size) {
        domino p1=pieces[i], p2=pieces[i+1];
        /*
         * COMPLETAR
         *
         */
        i++;
    }
    assert(match_count <= size);
    match_count = size;  // FIXME: BORRAR ESTA LINEA AL IMPLEMENTAR LA FUNCION
    return match_count;
}

