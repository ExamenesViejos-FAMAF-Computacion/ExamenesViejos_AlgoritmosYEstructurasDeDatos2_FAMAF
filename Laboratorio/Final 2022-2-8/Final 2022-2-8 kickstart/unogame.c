#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "unogame.h"
#include "card.h"

#define NO_PLAYER -1

struct s_ugame {
    /*
     * [COMPLETAR]
     *
     */
};

unogame_t
uno_newgame(card_t card) {
    /*
     * [COMPLETAR]
     *
     */
}

card_t
uno_topcard(unogame_t uno) {
    /*
     * [COMPLETAR]
     *
     */
}

unogame_t
uno_addcard(unogame_t uno, card_t c) {
    /*
     * [COMPLETAR]
     *
     */
}

unsigned int
uno_count(unogame_t uno) {
    /*
     * [COMPLETAR]
     *
     */
}

bool
uno_validpile(unogame_t uno) {
    /*
     * [COMPLETAR]
     *
     */
}

color_t
uno_currentcolor(unogame_t uno) {
    /*
     * [COMPLETAR]
     *
     */
}

player_t
uno_nextplayer(unogame_t uno) {
    /*
     * [COMPLETAR]
     *
     */
}



card_t *
uno_pile_to_array(unogame_t uno) {
    /*
     * [COMPLETAR]
     *
     */
}

unogame_t
uno_destroy(unogame_t uno) {
    /*
     * [COMPLETAR]
     *
     */
}

