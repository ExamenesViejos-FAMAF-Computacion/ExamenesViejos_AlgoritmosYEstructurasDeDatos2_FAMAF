#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "testing.h"
#include "pokerdeck.h"
#include "pokerdeck_helpers.h"

// Axuliar function
void clear_stdin(void) {
    char garbage;
    while (scanf(" %c", &garbage) != 1);
}

void delay(float seconds) {
    struct timespec dtime;
    dtime.tv_sec=0;
    dtime.tv_nsec = (long) (((float) ((1000L * 1000L) * 1000L)) * seconds);
    fflush(stdout);
    nanosleep(&dtime, NULL);
}

// Show functions
void show_menu(void) {
    for (int opt=0; opt < OPTIONS; opt++) {
        if (opt!=opt_exit) {
            printf("%-2d ..... %s\n", opt, optios_labels[opt]);
        }
    }
    printf("%-2d ..... %s\n", opt_exit, optios_labels[opt_exit]);
}

void show_suit_ref(void) {
    for (int suit_index=0; suit_index < CARD_SUITS; suit_index++) {
        printf("%c ..... %s\n", 
                suit_chars[suit_index], suit_labels[suit_index]);
    }
    printf("\n");
}

void show_number_ref(void) {
    for (int num_index=CARD_NUM_FST; num_index <= CARD_NUM_LST; num_index++) {
        printf("%-2s ..... %s\n", 
                number_strings[num_index], number_labels[num_index]);
    }
    printf("\n");
}

void show_card_ref(void) {
    show_number_ref();
    show_suit_ref();
    printf("formato de carta: [<código-num> <código-palo>]\n");
}

// Convert functions
cardsuit_t suit_from_char(char chr_suit, bool *success) {
    assert(success!=NULL);
    cardsuit_t suit=0;
    while (suit < CARD_SUITS && chr_suit!=suit_chars[suit]) {
        suit++;
    }
    *success = suit < CARD_SUITS;
    return suit;
}

cardnum_t number_from_string(const char *str_num, bool *success) {
    assert(success!=NULL);
    cardnum_t num=CARD_NUM_FST;
    while (num <= CARD_NUM_LST && strcmp(str_num, number_strings[num]) != 0) {
        num++;
    }
    *success = num <= CARD_NUM_LST;
    return num;
}

// Functions to get input from user
cardsuit_t ask_suit(bool *success, bool quiet) {
    assert(success!=NULL);
    cardsuit_t suit;
    char chr_suit;

    if (!quiet) {
        show_suit_ref();
        printf("Elegi el palo:");
    }

    int res=scanf(" %c", &chr_suit);
    if (res==1) {
        suit = suit_from_char(chr_suit, success);
    } else {
        *success=false;
        clear_stdin();
    }
    return suit;
}

void ask_card(cardnum_t *num, cardsuit_t *suit, bool *success, bool quiet) {
    assert(num != NULL && suit!=NULL && success!=NULL);
    bool suit_success=false, number_success=false;
    char num_str[CARD_NUMSTR_LEN + 1];
    char suit_chr_in;
    if (!quiet) {
        show_card_ref();
        printf("\nIngrese una carta: ");
    }

    int res=scanf(CARD_INPUT_PATTERN, num_str, &suit_chr_in);
    if (res!=2) {
        fprintf(stderr, "Ingreso de carta incorrecto\n\n");
        clear_stdin();
        *success=false;
    } else {
        *suit=suit_from_char(suit_chr_in, &suit_success);
        *num=number_from_string(num_str, &number_success);
        *success = suit_success && number_success;
    }
}

// Menu functions
void on_checkempty(pokerdeck deck) {
    printf("El mazo %s vacío\n", pokerdeck_is_empty(deck) ? "está": "NO está");
}

void on_length(pokerdeck deck) {
    printf("El mazo tiene %u cartas\n", pokerdeck_length(deck));
}

void on_show(pokerdeck deck) {
    pokerdeck_dump(deck);
}

void on_countsuit(pokerdeck deck, bool quiet) {
    bool suit_success=false;
    cardsuit_t suit=ask_suit(&suit_success, quiet);
    if (suit_success) {
        unsigned int cardcount=pokerdeck_count(deck, suit);
        printf("Hay %u carta%s de %s\n",  
                cardcount,
                cardcount !=1 ? "s": "",
                suit_labels[suit]);
    } else {
        fprintf(stderr, "Ingreso de palo incorrecto.\n\n");
    }
}

pokerdeck on_add(pokerdeck deck, bool quiet) {
    cardnum_t num;
    cardsuit_t suit;
    bool success=false;
    ask_card(&num, &suit, &success, quiet);
    if (!success) {
        fprintf(stderr, "Error en carta ingresada\n\n");
    } else {
        deck = pokerdeck_add(deck, num, suit);
    }
    return deck;
}

pokerdeck on_push(pokerdeck deck, bool quiet) {
    cardnum_t num;
    cardsuit_t suit;
    bool success=false;
    ask_card(&num, &suit, &success, quiet);
    if (!success) {
        fprintf(stderr, "Error en carta ingresada\n\n");
    } else {
        deck = pokerdeck_push(deck, num, suit);
    }
    return deck;
}

pokerdeck on_pop(pokerdeck deck) {
    cardnum_t num;
    cardsuit_t suit;

    deck = pokerdeck_pop(deck, &num, &suit);
    printf("La carta sacada del tope del mazo es: ");
    card_dump(num, suit);
    printf("\n");
    return deck;
}

pokerdeck on_remove(pokerdeck deck, bool quiet) {
    cardnum_t num;
    cardsuit_t suit;
    bool success=false;
    ask_card(&num, &suit, &success, quiet);
    if (!success) {
        fprintf(stderr, "Error en carta ingresada\n\n");
    } else {
        deck = pokerdeck_remove(deck, num, suit);
    }
    return deck;
}

void on_arr(pokerdeck deck) {
    struct card *arr=pokerdeck_to_array(deck);
    unsigned int length = pokerdeck_length(deck);
    printf("Arreglo:\n\n"
           "[");
    for (unsigned int i=0; i < length; i++) {
        printf(" %u: ", i);
        card_dump(arr[i].num, arr[i].suit);
        if (i + 1 != length) printf(", ");
    }
    printf("]\n");
    free(arr);
}

pokerdeck on_fulldeck(pokerdeck deck) {
    deck = pokerdeck_clean(deck);
    deck = pokerdeck_fulldeck(deck);
    return deck;
}

pokerdeck on_mix(pokerdeck deck) {
    deck = pokerdeck_mixcards(deck);
    return deck;
}

pokerdeck on_cut(pokerdeck deck) {
    deck = pokerdeck_cuthalf(deck);
    return deck;
}

pokerdeck on_clean(pokerdeck deck, bool quiet) {
    if (!quiet) {
        printf("\nDescartando mazo...\n\n");
    }
    while (!pokerdeck_is_empty(deck)) {
        cardnum_t num;
        cardsuit_t suit;
        deck = pokerdeck_pop(deck, &num, &suit);
        if (!quiet) {
            printf("\r");
            card_dump(num, suit);
            delay(0.05);
        }
    }
   return deck; 
}

int main(void) {
    pokerdeck deck=pokerdeck_empty();
    bool ask_exit=false, quiet=false;
    while (!ask_exit) {
        int option;
        show_menu();
        if (!quiet) {
            printf("\nElija una opción del menú: ");
        }
        int res = scanf("%d", &option);
        if (res==EOF || feof(stdin)) {
            fprintf(stderr, "Entrada finalizada\n\n");
            ask_exit=true;
            continue;
        } else if (res != 1 || option < 0 || option >= OPTIONS) {
            fprintf(stderr, "Opción incorrecta\n\n");
            clear_stdin();
            continue;
        }
        switch (option) {
            case opt_exit      : ask_exit=true; break;
            case opt_checkempty: on_checkempty(deck); break;
            case opt_length    : on_length(deck); break;
            case opt_show      : on_show(deck); break;
            case opt_countsuit : on_countsuit(deck, quiet); break;
            case opt_add       : deck = on_add(deck, quiet); break;
            case opt_push      : deck = on_push(deck, quiet); break;
            case opt_pop:
                if (pokerdeck_is_empty(deck)) {
                    fprintf(stderr, "ERROR: Mazo vacío!\n");
                } else {
                    deck = on_pop(deck);
                }
                break;
            case opt_remove:
                if (pokerdeck_is_empty(deck)) {
                    fprintf(stderr, "ERROR: Mazo vacío!\n");
                } else {
                    deck = on_remove(deck, quiet);
                }
                break;
            case opt_arr     : on_arr(deck); break;
            case opt_fulldeck: deck = on_fulldeck(deck); break;
            case opt_mix     : deck = on_mix(deck); break;
            case opt_cut     : deck = on_cut(deck); break;
            case opt_clean: deck = on_clean(deck, quiet); break;
        }
        printf("\n\n");
    }
    deck=pokerdeck_destroy(deck);
    return EXIT_SUCCESS; 
}

