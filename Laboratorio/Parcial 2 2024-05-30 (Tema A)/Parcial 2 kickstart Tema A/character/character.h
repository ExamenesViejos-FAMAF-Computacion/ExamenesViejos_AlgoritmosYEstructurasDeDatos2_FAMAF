/*
  @file character.h
  @brief Defines character information
*/

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <stdbool.h> // Incluir esta biblioteca para usar bool
#include <stdio.h>

/* ============================================================================
IO
============================================================================ */

/** @brief Maximum length of character name */
#define CHARACTER_NAME_LENGTH 5

/** @brief Expected format of character attributes */
#define EXPECTED_ATTRIBUTE_FORMAT                                              \
  " [%c %c] %5s, life: %u, strength: %u, agility: %u "

/** @brief Maximum number of characters */
#define CHARACTER_COUNT 10

/* ============================================================================
THE CHARACTER
============================================================================ */

/** @brief Character alignments */
typedef enum { good, evil } alignment_t;

/** @brief Character types */
typedef enum { physical, agile, tank, magic } charttype_t;

/**
 * @brief Represents a character in the game.
 *
 * The Character struct contains information about a character, including their
 * type, alignment, name, life points, strength, agility, and alive status.
 */
typedef struct s_Character *Character;

/* ============================================================================
PRINT
============================================================================ */

/**
 * @brief Prints the details of a character.
 *
 * This function takes a Character struct as input and prints the various
 * attributes of the character, including the character type, alignment, name,
 * life points, strength, and agility.
 *
 * @param character The Character struct containing the character details.
 *
 * The function uses the character_type and character_alignment functions to
 * convert the character's type and alignment enums into human-readable strings
 * before printing them.
 *
 * The printed details include:
 * - Character type (ctype): The type of the character (e.g., physical, agile,
 * tank, magic).
 * - Alignment: The alignment of the character (e.g., good, evil).
 * - Name: The name of the character.
 * - Life: The current life points of the character.
 * - Strength: The strength attribute of the character.
 * - Agility: The agility attribute of the character.
 *
 * After printing the character details, a line of dashes is printed to visually
 * separate the output for each character.
 */
void character_print(Character character);

/* ============================================================================
PROCESSOR
============================================================================ */

/**
 * @brief Function pointer type for processing a character.
 *
 * This function pointer type represents a function that takes two parameters:
 * - `where`: A void pointer representing the location where the character is
 * processed. The specific type and purpose of this pointer depend on the
 * implementation.
 * - `character`: A Character struct containing the details of the character
 * being processed.
 *
 * Functions of this type are responsible for performing specific operations or
 * actions on a character based on the provided `where` and `character`
 * parameters.
 *
 * @param where A void pointer indicating the location or context where the
 * character is being processed. The interpretation of this pointer is
 * implementation-specific.
 * @param character The Character struct holding the details of the character to
 * be processed.
 *
 * @return This function pointer type does not specify a return value. The
 * actual return type depends on the specific function implementation.
 */
typedef void (*ProcessCharacter)(void *where, Character character);

/* ============================================================================
CREATORS AND DESTUCTORS
============================================================================ */

/**
 * Creates a new Character object with the specified attributes.
 *
 * @param ctype The type of the character (physical, agile, tank, magic).
 * @param alignment The alignment of the character (good, evil).
 * @param name The name of the character.
 * @param life The initial life points of the character.
 * @param strength The initial strength attribute of the character.
 * @param agility The initial agility attribute of the character.
 *
 * @return A pointer to the newly created Character object.
 *
 * @throws None.
 */
Character character_create(char ctype, char alignment, char *name,
                           unsigned int life, unsigned int strength,
                           unsigned int agility);

/**
 * Destroys a Character object and frees any associated resources.
 *
 * @param character The Character object to be destroyed.
 *
 * @return None.
 *
 * @throws None.
 */
Character character_destroy(Character character);

/**
 * @brief Creates a copy of a Character object.
 *
 * @param character The Character object to be copied.
 *
 * @return A pointer to the newly created copy of the Character object.
 *
 * @throws None.
 */
Character character_copy(Character character);

/* ============================================================================
FILE TO CHARACTERS
============================================================================ */

/**
 * @brief Reads character data from a file and prints it.
 *
 * This function opens a file named "characters.txt" and reads character data
 * from each line using the `character_from_file_line` function. It prints the
 * attributes of each valid character.
 *
 * @param file Pointer to the file to read from.
 *
 * @return Number of records readed
 */
unsigned int character_read(FILE *file, void *where, ProcessCharacter process);

/* ============================================================================
GET-SET
============================================================================ */

/**
 * @brief Returns the name of a character.
 *
 * @param character A pointer to the Character struct containing the character
 * details.
 *
 * @return A pointer to a string containing the character's name.
 *
 * @throws None.
 */
char *character_name(Character character);

/**
 * @brief Returns the type of a character.
 *
 * @param character A pointer to the Character struct containing the character
 * details.
 *
 * @return An enum value representing the character type (physical, agile,
 * tank, magic).
 *
 * @throws None.
 */
charttype_t character_ctype(Character character);

/**
 * @brief Returns the alignment of a character.
 *
 * @param character A pointer to the Character struct containing the character
 * details.
 *
 * @return An enum value representing the character alignment (good, evil).
 *
 * @throws None.
 */
alignment_t character_alignment(Character character);

/**
 * @brief Returns the life points of a character.
 *
 * @param character A pointer to the Character struct containing the character
 * details.
 *
 * @return The number of life points currently associated with the character.
 *
 * @throws None.
 */
unsigned int character_life(Character character);

/**
 * @brief Returns the strength attribute of a character.
 *
 * @param character A pointer to the Character struct containing the character
 * details.
 *
 * @return The strength attribute of the character.
 *
 * @throws None.
 */
unsigned int character_strenght(Character character);

/**
 * @brief Returns the agility attribute of a character.
 *
 * @param character A pointer to the Character struct containing the character
 * details.
 *
 * @return The agility attribute of the character.
 *
 * @throws None.
 */
unsigned int character_agility(Character character);

/**
 * @brief Checks if a character is alive.
 *
 * @param character A pointer to the Character struct containing the character
 * details.
 *
 * @return A boolean value indicating whether the character is alive or not.
 *
 * @throws None.
 */
bool character_is_alive(Character character);

#endif // _CHARACTER_H
