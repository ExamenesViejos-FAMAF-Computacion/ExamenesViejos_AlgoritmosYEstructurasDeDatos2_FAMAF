/*
  @file character.c
  @brief Implements character structure and methods
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"

static const int AMOUNT_OF_ATTRIBUTES = 6;

struct s_Character {
  char name[50];
  char ctype;
  char alignment;
  unsigned int life;
  unsigned int strength;
  unsigned int agility;
  bool alive;
};

/* ============================================================================
GET-SET
============================================================================ */

char *character_name(Character character) { return character->name; }

charttype_t character_ctype(Character character) {
  char ctype_c = character->ctype;
  charttype_t ctype = -1;
  switch (ctype_c) {
  case 'p':
    ctype = physical;
    break;
  case 'a':
    ctype = agile;
    break;
  case 't':
    ctype = tank;
    break;
  case 'm':
    ctype = magic;
    break;
  }
  return ctype;
}

alignment_t character_alignment(Character character) {
  char alignment_c = character->alignment;
  return (alignment_c == 'g') ? good : evil;
}

unsigned int character_life(Character character) { return character->life; }

unsigned int character_strenght(Character character) {
  return character->strength;
}

unsigned int character_agility(Character character) {
  return character->agility;
}

bool character_is_alive(Character character) { return character->alive; }

/* ============================================================================
PRINT
============================================================================ */

// static char *character_alignment(alignment_t alignment) {
//   return (alignment == good) ? "Good" : "Evil";
// }

static char *character_type_str(charttype_t ctype) {
  char *result = NULL;
  switch (ctype) {
  case physical:
    result = "Physical";
    break;
  case agile:
    result = "Agile";
    break;
  case tank:
    result = "Tank";
    break;
  case magic:
    result = "Magic";
    break;
  }
  return result;
}

static char *is_alive_str(bool alive) { return (alive) ? "Yes" : "No"; }

void character_print(Character character) {
  charttype_t ctype = character_ctype(character);
  printf("Character name: %s,", character->name);
  printf(" Alive? %s,", is_alive_str(character->alive));
  printf(" ctype: %s,", character_type_str(ctype));
  // printf(" alignment: %s\n", character_alignment(character.alignment));
  // printf(" life: %u\n", character.life);
  // printf(" strength: %u\n", character.strength);
  printf(" agility: %u\n", character->agility);
}

/**/ /* ============================================================================
 CREATORS AND DESTUCTORS
 ============================================================================ */

Character character_create(char ctype, char alignment, char *name,
                           unsigned int life, unsigned int strength,
                           unsigned int agility) {

  bool valid_data = true;
  if (alignment != 'g' && alignment != 'e') {
    fprintf(stderr, "Alignment must be 'g' or 'e'.\n");
    valid_data = false;
  } else if (ctype != 'p' && ctype != 'a' && ctype != 't' && ctype != 'm') {
    fprintf(stderr, "Character type must be 'p', 'a', 't' or 'm'.\n");
    valid_data = false;
  } else if (life > 100u) {
    fprintf(stderr, "Life must be between [0, 100].\n");
    valid_data = false;
  } else if (strength < 1u || strength > 10u) {
    fprintf(stderr, "Strength must be between [1, 10].\n");
    valid_data = false;
  } else if (agility < 1u || agility > 10u) {
    fprintf(stderr, "Agility must be between [1, 10].\n");
    valid_data = false;
  }

  Character character = NULL;

  if (valid_data) {

    character = malloc(sizeof(struct s_Character));
    character->alignment = alignment;
    character->ctype = ctype;
    strcpy(character->name, name);
    character->life = life;
    character->strength = strength;
    character->agility = agility;
    character->alive = life > 0;
  }
  return character;
}

Character character_destroy(Character character) {
  free(character);
  character = NULL;
  return character;
}

Character character_copy(Character character) {
  return character_create(character->ctype, character->alignment,
                          character->name, character->life, character->strength,
                          character->agility);
}

/* ============================================================================
FILE TO CHARACTERS
============================================================================ */

Character character_from_file_line(FILE *file) {

  // placeholders
  char ctype, alignment, name[CHARACTER_NAME_LENGTH + 1];
  unsigned int life, strength, agility;

  // Reading
  int res = fscanf(file, EXPECTED_ATTRIBUTE_FORMAT, &ctype, &alignment, name,
                   &life, &strength, &agility);

  Character character = NULL;
  if (res == AMOUNT_OF_ATTRIBUTES) {
    character =
        character_create(ctype, alignment, name, life, strength, agility);
  } else {
    fprintf(stderr, "Invalid Character data.\n");
  }

  return character;
}

unsigned int character_read(FILE *file, void *where, ProcessCharacter process) {

  // here we store how many records are readed
  unsigned int readed = 0;
  while (!feof(file)) {
    Character character = character_from_file_line(file);

    if (character == NULL) {
      break;
    }

    // send the data to the provided processor
    process(where, character);

    // one more record
    readed++;
  }

  // return the number of records readed
  return readed;
}
