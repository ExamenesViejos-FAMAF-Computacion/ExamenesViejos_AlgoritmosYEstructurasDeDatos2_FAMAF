/*
  @file ranking.c
  @brief Implements store structure and methods
*/
#include <stdlib.h>
#include "ranking.h"
#include <string.h>

static const int NUMBER_OF_RANKING_VARS = 6;

Ranking ranking_from_file(FILE *file) {

    Ranking ranking;
    int a,b,c;
    char d[20], e[20];
    float f;

    int res = fscanf(/*COMPLETAR*/);

    /* COMPLETAR: se leyo correctamente? */

    strcpy(ranking.name,d);
    strcpy(ranking.team,e);

    /* COMPLETAR: campos de ranking */
    
    return ranking;
}

unsigned int total_track_points_per_team(RankingTable a, char *team_name) {
    int sum = 0;
    /* COMPLETAR */
    return sum;
}
