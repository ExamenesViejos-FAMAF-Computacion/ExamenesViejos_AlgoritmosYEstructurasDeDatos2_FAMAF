/*
  @file ranking.h
  @brief Defines ranking information
*/

#ifndef _RANKING_H
#define _RANKING_H

#define EXPECTED_RANKING_FILE_FORMAT  /* COMPLETAR */

#define NO_PLAYERS 100
#define TYPES 2

#include <stdio.h>

typedef enum types { road, track } type_t; 

/** @brief Type used to represent ranking data.*/
typedef struct _ranking {
  unsigned int pos;
  int pos_prev;
  int diff;
  char name[20];
  char team[20];
  float points;
} Ranking;


typedef Ranking RankingTable[NO_PLAYERS][TYPES];

/**
 * @brief reads ranking data from file line
 * @details
 * Ranking file line must contain:
 * <unsigned int> <int> <int> <string> <string> <float>
 *
 * @param[in] file Opened file stream
 * @param[in] type The type of information
 * @return Ranking structure which contains read information from file
 */
Ranking ranking_from_file(FILE* file);

float total_track_points_per_team(RankingTable a, char *team_name);

#endif
