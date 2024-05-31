/*
 * @file main.c
 * @brief Main program for the Initiative project.
 */

/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "character/character.h"
#include "pqueue.h"

/* The constants */
static const int RIGHT_NUMBER_OF_ARGUMENTS = 2;

static const char *ERR_FILE_NOT_EXIST = "File does not exist.\n";

/*
 * @brief Prints the usage help of this program.
 * @param program_name The name of the program.
 */
static void print_help(char *program_name) {
  printf("Usage: %s <input file path>\n\n"
         "Read characters with an associated data and return the"
         "Initiative.\n"
         "\n",
         program_name);
}

/*
 * @brief Parses the filepath given by command line argument.
 * @param argc The number of command line arguments.
 * @param argv The array of command line arguments.
 * @return The filepath parsed from the command line arguments.
 */
static char *parse_filepath(int argc, char *argv[]) {
  char *result = NULL;

  if (argc < RIGHT_NUMBER_OF_ARGUMENTS) {
    print_help(argv[0]);
    exit(EXIT_FAILURE);
  }

  result = argv[1];

  return (result);
}

/*
 * @brief Processes a character and adds it to the priority queue.
 * @param q The priority queue.
 * @param character The character to be processed.
 */
static void process_character(void *q, Character character) {
  pqueue_enqueue(q, character);
}

/*
 * @brief Reads characters from a file and returns a priority queue of
 * characters.
 * @param filepath The path to the file containing characters.
 * @return The priority queue of characters.
 */
static pqueue initiative_from_file(const char *filepath) {
  FILE *file = NULL;
  file = fopen(filepath, "r");

  if (file == NULL) {
    fprintf(stderr, "%s", ERR_FILE_NOT_EXIST);
    exit(EXIT_FAILURE);
  }

  pqueue q = pqueue_empty();
  character_read(file, q, process_character);

  fclose(file);

  return q;
}

/*
 * @brief Dumps the contents of the priority queue to the console.
 * @param q The priority queue to be dumped.
 */
static void pqueue_dump(pqueue q) {
  pqueue copy_q = NULL;
  copy_q = pqueue_copy(q);

  unsigned int length = pqueue_size(copy_q);
  printf("=== CHARACTERS INITIATIVE (%u) ===\n", length);

  while (!pqueue_is_empty(copy_q)) {
    Character elem = pqueue_peek(copy_q);
    float priority = pqueue_peek_priority(copy_q);

    printf("[%.4f] -> ", priority);
    character_print(elem);

    copy_q = pqueue_dequeue(copy_q);
  }
  fprintf(stdout, "\n");
  pqueue_destroy(copy_q);
}

/*
 * @brief The main function of the program.
 * @param argc The number of command line arguments.
 * @param argv The array of command line arguments.
 * @return The exit status of the program.
 */
int main(int argc, char *argv[]) {
  char *filepath = NULL;

  /* Parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* Get the priority queue of characters from the file */
  pqueue q = initiative_from_file(filepath);

  /* Dump the priority queue of characters to the console */
  pqueue_dump(q);

  /* Destroy the instance of the priority queue */
  q = pqueue_destroy(q);

  return (EXIT_SUCCESS);
}