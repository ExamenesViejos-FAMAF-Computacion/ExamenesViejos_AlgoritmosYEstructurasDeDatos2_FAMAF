#include <stdlib.h>
#include <assert.h>

#include "pokerdeck_helpers.h"
#include "pokerdeck.h"

pokerdeck pokerdeck_clean(pokerdeck deck) {
    while (!pokerdeck_is_empty(deck)) {
        deck = pokerdeck_pop(deck, NULL, NULL);
    }
    return deck;
}

pokerdeck pokerdeck_fulldeck(pokerdeck deck) {
    for (cardsuit_t suit=0; suit < CARD_SUITS; suit++) {
        for (cardnum_t num=CARD_NUM_FST; num <= CARD_NUM_LST; num++) {
            deck = pokerdeck_add(deck, num, suit);
        }
    }
    return deck;
}
pokerdeck pokerdeck_mixcards(pokerdeck deck) {
    pokerdeck auxdeck1=pokerdeck_empty();
    pokerdeck auxdeck2=pokerdeck_empty();
    unsigned int length=pokerdeck_length(deck);
    unsigned int half_length=length /2;
    // Split deck in tow halfes: auxdeck1 and auxdeck2
    while (!pokerdeck_is_empty(deck)) {
        cardnum_t num;
        cardsuit_t suit;
        deck = pokerdeck_pop(deck, &num, &suit);
        if (pokerdeck_length(deck) > half_length) {
            auxdeck1 = pokerdeck_add(auxdeck1, num, suit);
        } else {
            auxdeck2 = pokerdeck_add(auxdeck2, num, suit);
        }
    }
    assert(pokerdeck_length(deck) == 0 &&
          pokerdeck_length(auxdeck1) + pokerdeck_length(auxdeck2) == length);
    // Join both halfes into original deck with interleaving
    while (!pokerdeck_is_empty(auxdeck1) || !pokerdeck_is_empty(auxdeck2)) {
        cardnum_t num;
        cardsuit_t suit;
        if (!pokerdeck_is_empty(auxdeck1)) {
            auxdeck1 = pokerdeck_pop(auxdeck1, &num, &suit);
            deck = pokerdeck_add(deck, num, suit);
        }
        if (!pokerdeck_is_empty(auxdeck2)) {
            auxdeck2 = pokerdeck_pop(auxdeck2, &num, &suit);
            deck = pokerdeck_add(deck, num, suit);
        }

    }
    assert(pokerdeck_length(deck) == length &&
           pokerdeck_length(auxdeck1) + pokerdeck_length(auxdeck2) == 0);
    // Destroy auxiliar decks
    auxdeck1 = pokerdeck_destroy(auxdeck1);
    auxdeck2 = pokerdeck_destroy(auxdeck2);
    return deck;
}

pokerdeck pokerdeck_cuthalf(pokerdeck deck) {
    pokerdeck auxdeck=pokerdeck_empty();
    // Take the first half deck into auxdeck
    while (pokerdeck_length(deck) > pokerdeck_length(auxdeck)) {
        cardnum_t num;
        cardsuit_t suit;
        deck = pokerdeck_pop(deck, &num, &suit);
        auxdeck = pokerdeck_add(auxdeck, num, suit);
    }
    // Put auxdeck at the bottom of the main deck
    while(!pokerdeck_is_empty(auxdeck)) {
        cardnum_t num;
        cardsuit_t suit;
        auxdeck = pokerdeck_pop(auxdeck, &num, &suit);
        deck = pokerdeck_add(deck, num, suit);
    }
    // Destroy auxiliar deck
    auxdeck = pokerdeck_destroy(auxdeck);
    return deck;
}

