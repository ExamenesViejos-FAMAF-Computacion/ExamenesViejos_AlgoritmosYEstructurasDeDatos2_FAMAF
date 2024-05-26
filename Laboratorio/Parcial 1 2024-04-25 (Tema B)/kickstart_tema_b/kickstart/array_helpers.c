/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

void array_dump(RankingTable a) {
    for (unsigned int ranking = 0u; ranking < NO_PLAYERS; ranking++) {
        for (unsigned int type = road; type <= track; type++) {
            Ranking aux = a[ranking][type];
            fprintf(stdout, " %u %s %i %i %s %s %f\n",
                    ranking+1, (type==0?"road":"track"), aux.pos_prev, aux.diff, aux.name, aux.team, aux.points
            );
        }
    }
}

void array_from_file(RankingTable array, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    type_t type;

    int i = 0;
    while (/* COMPLETAR */) {

        int res = fscanf(file, /* COMPLETAR */);

        if (res != 1) {
            fprintf(stderr, "Invalid ranking type.\n");
            exit(EXIT_FAILURE);
        }

        /* COMPLETAR: Leer Ranking */
        Ranking ranking_row = /* completar... */

        /* COMPLETAR: guardar ranking en array */
        /* completar... */ = ranking_row;
        i++;
    }
    fclose(file);
}

