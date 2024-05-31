#ifndef _POKERDECK_HELPERS_H_
#define _POKERDECK_HELPERS_H_

#include "pokerdeck.h"

pokerdeck pokerdeck_clean(pokerdeck deck);
/*
 * DESC: Removes all cards from `deck` through pop() operations
 *
 */

pokerdeck pokerdeck_fulldeck(pokerdeck deck);
/*
 * DESC: Adds to `deck` all combinatios of card-numbers and card-suits
 * resulting in the standar 52 cards poker-deck
 *
 */

pokerdeck pokerdeck_mixcards(pokerdeck deck);
/*
 * DESC: Split the deck into two halves and join both of them by interleaving
 * every card. The resulting deck is returned.
 *
 */

pokerdeck pokerdeck_cuthalf(pokerdeck deck);
/*
 * DESC: Split the deck into two halves and put the second half at the top of
 * the deck.
 *
 */


#endif /* _POKERDECK_HELPERS_H_*/

