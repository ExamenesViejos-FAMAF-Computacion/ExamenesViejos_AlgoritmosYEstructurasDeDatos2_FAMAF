#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "pokerdeck.h"

struct s_pokerdck {
    /*
     * COMPLETAR
     */
    struct s_node *first;
};

struct s_node {
    cardnum_t num;
    cardsuit_t suit;
    struct s_node *nextcard;
};

typedef struct s_node * node_t;

// Auxiliar dump functions
static void dump_suit(cardsuit_t suit) {
    printf("%s", suit==spades   ? "♠️  ":
                 suit==hearts   ? "♥️  ":
                 suit==diamonds ? "♦️  ":
                 suit==clubs    ? "♣️  ": "???");
}

static void dump_num(cardnum_t num) {
    if (1 < num && num < 11) {
        printf("%-2d", num);
    } else {
        printf("%-2s", num==1 ? "A":
                       num==11 ? "J":
                       num==12 ? "Q":
                       num==13 ? "K": "???");

    }
}

// Representation invariant
static bool invrep(pokerdeck deck) {
    bool valid=false;
    /*
     * COMPLETAR
     *
     */
    return valid;
}

// Creates a single node in dynamic memory with a given card
static node_t create_node(cardnum_t num, cardsuit_t suit) {
    node_t newnode=NULL;
    /*
     * COMPLETAR
     *
     */
    assert(newnode!=NULL);
    return newnode;
}

// Destroy a single node
static node_t destroy_node(node_t node) {
    /*
     * COMPLETAR
     *
     */
    assert(node==NULL);
    return node;
}

// Public functions of the Abstract Data Type
pokerdeck pokerdeck_empty(void) {
    /*
     * COMPLETAR
     *
     */
}

bool pokerdeck_is_empty(pokerdeck deck) {
    /*
     * COMPLETAR
     *
     */
}

pokerdeck pokerdeck_add(pokerdeck deck, cardnum_t num, cardsuit_t suit) {
    /*
     * COMPLETAR
     *
     */
}

pokerdeck pokerdeck_push(pokerdeck deck,  cardnum_t num, cardsuit_t suit) {
    assert(invrep(deck));
    node_t newnode = create_node(num, suit);
    newnode->nextcard = deck->first;
    deck->first = newnode;
    /*
     * COMPLETAR: si fuera necesario actualizar datos de la estructura
     * principal.
     *
     */
    assert(invrep(deck) && !pokerdeck_is_empty(deck));
    return deck;
}

pokerdeck pokerdeck_pop(pokerdeck deck, cardnum_t *popped_num, cardnum_t *popped_suit) {
    /*
     * COMPLETAR
     *
     */
    if (popped_num!=NULL) *popped_num=/* COMPLETAR */;
    if (popped_suit!=NULL) *popped_suit=/* COMPLETAR */;
    return deck;
}

unsigned int pokerdeck_length(pokerdeck deck) {
    /*
     * COMPLETAR
     *
     */
}

pokerdeck pokerdeck_remove(pokerdeck deck, cardnum_t num, cardsuit_t suit) {
    /*
     * COMPLETAR
     *
     */
}

unsigned int pokerdeck_count(pokerdeck deck, cardsuit_t suit) {
    /*
     * COMPLETAR
     *
     */
}

struct card * pokerdeck_to_array(pokerdeck deck) {
    /*
     * COMPLETAR
     *
     */
}

void card_dump(cardnum_t num, cardsuit_t suit) {
    printf("|");
    dump_num(num);
    printf(" ");
    dump_suit(suit);
    printf("|");
}

void pokerdeck_dump(pokerdeck deck) {
    assert(invrep(deck));
    node_t node = deck->first;
    while (node != NULL) {
        card_dump(node->num, node->suit);
        printf(" ");
        node = node->nextcard;
    }
    printf("\n");
}

pokerdeck pokerdeck_destroy(pokerdeck deck) {
    /*
     * COMPLETAR
     *
     */
}

