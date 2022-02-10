#include <stdlib.h>
#include <stdbool.h>

#include <assert.h>
#include "card.h"

struct s_card {
    unsigned int num;
    color_t color;
    type_t type;
};

static bool
invrep(card_t c) {
    // Invariante de representación
    bool valid=false;
    valid = c != NULL;
    /*
     * [COMPLETAR]
     *
     * Mejorar la invariante chequeando más
     * propiedades de los campos de la estructura
     *
     */
    return valid;
}

card_t
card_new(unsigned int num, color_t color, type_t s) {
    card_t card=NULL;
    /*
     * [COMPLETAR]
     *
     */
    return card;
}


type_t
card_get_number(card_t card) {
    assert(invrep(card));
    return card->num;
}

color_t
card_get_color(card_t card) {
    assert(invrep(card));
    return card->color;
}

type_t
card_get_type(card_t card) {
    assert(invrep(card));
    return card->type;
}

bool
card_samecolor(card_t c1, card_t c2) {
    /*
     * [COMPLETAR]
     *
     */
}


bool
card_samenum(card_t c1, card_t c2) {
    /*
     * [COMPLETAR]
     *
     */
}

bool
card_compatible(card_t new_card, card_t pile_card) {
    bool compatible=false;
    assert(invrep(new_card) && invrep(pile_card));
    /*
     * [COMPLETAR]
     *
     */
    return compatible;
}

card_t
card_destroy(card_t card) {
    /*
     * [COMPLETAR]
     *
     */
}


