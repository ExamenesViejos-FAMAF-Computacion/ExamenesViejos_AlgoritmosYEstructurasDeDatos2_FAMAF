#ifndef _POKERDECK_H_
#define _POKERDECK_H_

#include <stdbool.h>

typedef enum {spades, hearts, diamonds, clubs} cardsuit_t;
typedef unsigned int cardnum_t;

#define CARD_SUITS 4

#define CARD_NUM_FST 1
#define CARD_NUM_LST 13

#define CARD_NUMS (CARD_NUM_LST - CARD_NUM_FST + 1)

struct card {
    cardnum_t num;
    cardsuit_t suit;
};

typedef struct s_pokerdck * pokerdeck;

pokerdeck pokerdeck_empty(void);
/*
 * DESC: Creates an instance of pokerdeck with no cards inside
 * 
 *   deck = pokerdeck_empty();
 * POS: {deck --> pokerdeck && pokerdeck_is_empty(deck)}
 */

bool pokerdeck_is_empty(pokerdeck deck);
/*
 * DESC: Indicates whether the deck is empty or not
 *
 * PRE: {deck --> pokerdeck}
 *   is_empty = pokerdeck_is_empty(deck);
 * POS: {deck --> pokerdeck}
 *
 */


pokerdeck pokerdeck_add(pokerdeck deck, cardnum_t num, cardsuit_t suit);
/*
 * DESC: Adds a card with number `num` and suit `suit` at the bottom of the
 * deck. A inmediate call to `pokerdeck_pop()` will not remove this card,
 * unless the deck was empty before and the added card is the only one inside
 * the deck.
 *
 * PRE: {deck --> pokerdeck}
 *   deck = pokerdeck_add(deck, num, suit);
 * POS: {deck --> pokerdeck && !pokerdeck_is_empty(deck)}
 *
 */


pokerdeck pokerdeck_push(pokerdeck deck,  cardnum_t num, cardsuit_t suit);
/*
 * DESC: Adds a card with number `num` and suit `suit` at the top of the deck.
 * A inmediate call to `pokerdeck_pop()` will result in removing this card.
 *
 * PRE: {deck --> pokerdeck}
 *   deck = pokerdeck_push(deck, num, suit);
 * POS: {deck --> pokerdeck && !pokerdeck_is_empty(deck)}
 *
 */

pokerdeck pokerdeck_pop(pokerdeck deck, cardnum_t *popped_num, cardsuit_t *popped_suit);
/*
 * DESC: Removes the card at the top of the deck, placing the number and suit
 * of the removed card in the memory pointed to by `popped_num` and `popped_suit`
 * respectively, unless a `NULL` pointer was passed.
 *
 * PRE: {deck --> pokerdeck && !pokerdeck_is_empty(deck)}
 *   deck = pokerdeck_pop(deck, popped_num, popped_suit);
 * POS: {deck --> pokerdeck}
 *
 * EXAMPLE 1: Pop a card and store the number and suit in `num` and `suit` variables
 * ```
 * cardnum_t num;
 * cardsuit_t suit;
 * deck = pokerdeck_pop(deck, &num, &suit);
 * ```
 * 
 * EXAMPLE 2: Pop a card without storing the removed card
 * ```
 * deck = pokerdeck_pop(deck, NULL, NULL);
 * ```
 *
 */


unsigned int pokerdeck_length(pokerdeck deck);
/*
 * DESC: Returns the number of cards in the deck.
 *
 * PRE: {deck --> pokerdeck}
 *   length = pokerdeck_length(deck);
 * POS: {deck --> pokerdeck && pokerdeck_is_empty(deck) == (length == 0)}
 *
 */

pokerdeck pokerdeck_remove(pokerdeck deck, cardnum_t num, cardsuit_t suit);
/*
 * DESC: Removes a card with number `num` and suit `suit` from the deck. If
 * there is more than one occurrence, it removes the first one encountered, but
 * there is no defined order in the search. If there is no card with such
 * number and suit, nothing is done.
 *
 * PRE: {deck --> pokerdeck}
 *   deck = pokerdeck_remove(deck, num, suit);
 * POS: {deck --> pokerdeck}
 *
 */

unsigned int pokerdeck_count(pokerdeck deck, cardsuit_t suit);
/*
 * DESC: Counts the cards in the deck that have the suit indicated by the
 * parameter `suit`.
 *
 * PRE: {deck --> pokerdeck}
 *   count = pokerdeck_count(deck, suit);
 * POS: {deck --> pokerdeck && count <= pokerdeck_length(deck)}
 *
 */

struct card * pokerdeck_to_array(pokerdeck deck);
/*
 * DESC: Returns an array of `struct card` elements in dynamic memory
 * containing all the cards, starting from the top to the bottom. The array
 * must eventually be freed by the caller.
 *
 * PRE: {deck --> pokerdeck}
 *   array = pokerdeck_to_array(deck, suit);
 * POS: {(pokerdeck_length(deck)==0) == (array==NULL)}
 *
 */


void card_dump(cardnum_t num, cardsuit_t suit);
/* 
 * DESC: Displays a card with number `num` and suit `suit` in the screen.
 *
 */

void pokerdeck_dump(pokerdeck deck);
/*
 * DESC: Displays all the cards in the deck from the top to the bottom.
 *
 * PRE: {deck --> pokerdeck}
 *   pokerdeck_dump(deck);
 * POS: {deck --> pokerdeck}
 *
 */


pokerdeck pokerdeck_destroy(pokerdeck deck);
/*
 * DESC: Destroys an instance of pokerdeck freeing all memory used by it
 *
 * PRE: {deck --> pokerdeck}
 *   deck = pokerdeck_destroy(deck);
 * POS: {deck == NULL}
 *
 */

#endif /* _POKERDECK_H_ */

