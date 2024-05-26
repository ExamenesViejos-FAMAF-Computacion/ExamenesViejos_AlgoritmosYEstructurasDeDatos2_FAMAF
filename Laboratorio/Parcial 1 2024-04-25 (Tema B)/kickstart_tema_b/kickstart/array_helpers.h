/*
  @file array_helpers.h
  @brief defines array helpers methods. These methods operates over multidimensional array of prices
*/
#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdbool.h>
#include "ranking.h"

/**
 * @brief Write the content of the array 'a' into stdout.
 * @param[in] a array to dump in stdout
 */
void array_dump(RankingTable a);


/**
 * @brief reads an array of prices information from file
 * @details
 *
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *
 *   <type> <pa> <pp> <dp> <nc> <ne> <pt>
 *
 *   Those elements are copied into the multidimensional array 'a'.
 *   The dimensions of the array are given by the macros noted above.
 *
 * @param a array which will contain read file
 * @param filepath file with prices data
 */
void array_from_file(RankingTable a, const char *filepath);

#endif
