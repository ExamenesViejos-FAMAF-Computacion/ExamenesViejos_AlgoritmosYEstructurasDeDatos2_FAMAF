#ifndef _TESTING_H_
#define _TESTING_H_

#include "pokerdeck.h"


#define CARD_INPUT_PATTERN " [%2s %c]"

#define OPTIONS 14

typedef enum {opt_exit, opt_checkempty, opt_length, opt_show, opt_countsuit,
              opt_add, opt_push, opt_pop, opt_remove, opt_arr, 
              opt_fulldeck, opt_mix, opt_cut, opt_clean} option_t;

static const char* optios_labels[OPTIONS]={
    [opt_checkempty]="Verificar si el mazo está vacío",
    [opt_length]    ="Mostrar cantidad de cartas en el mazo",
    [opt_show]      ="Mostrar el mazo por pantalla",
    [opt_countsuit] ="Contar cantidad de cartas de determinado palo",
    [opt_push]      ="Agregar una carta al tope del mazo",
    [opt_add]       ="Agregar una carta al final del mazo",
    [opt_pop]       ="Sacar la carta del tope del mazo",
    [opt_remove]    ="Sacar una carta a elección del mazo",
    [opt_arr]       ="Obtener un arreglo con las cartas del mazo",
    [opt_fulldeck]  ="Cargar el mazo completo",
    [opt_mix]       ="Mezclar cartas intercalando dos mitades del mazo",
    [opt_cut]       ="Cortar el mazo ubicando la segunda mitad en el tope",
    [opt_clean]     ="Vaciar el mazo de cartas",
    [opt_exit]      ="Salir"
};

static const char *suit_labels[CARD_SUITS]={
    [spades]  ="picas",
    [hearts]  ="corazones",
    [diamonds]="diamantes",
    [clubs]   ="tréboles"
};

static const char suit_chars[CARD_SUITS]={
    [spades]  ='p',
    [hearts]  ='c',
    [diamonds]='d',
    [clubs]   ='t'
};

#define CARD_NUMSTR_LEN 2

static const char *number_strings[CARD_NUMS + 1]={
    "", "A",
    "2", "3","4","5","6","7","8","9","10",
    "J", "Q", "K"
};

static const char *number_labels[CARD_NUMS + 1]={
    "",
    "As",
    "2 (dos)",
    "3 (tres)",
    "4 (cuatro)",
    "5 (cinco)",
    "6 (seis)",
    "7 (siete)",
    "8 (ocho)",
    "9 (nueve)",
    "10 (diez)",
    "J (Jack)",
    "Q (Reyna)",
    "K (Rey)"
};

#endif /* _TESTING_H_ */

