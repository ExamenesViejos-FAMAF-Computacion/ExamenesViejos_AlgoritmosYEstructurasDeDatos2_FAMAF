#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "matchTimeline.h"

/* ============================================================================
STRUCTS
============================================================================ */

struct s_node
{
    team team;
    event e;
    time t;
    playerNumber pn;
    struct s_node *next;
};

struct s_matchTimeline
{
    struct s_node *head;
    // COMPLETAR
};

/* ============================================================================
INVERP & VALIDATION
============================================================================ */

static bool invrep(matchTimeline mt)
{
    // COMPLETAR
    return mt != NULL || mt == NULL; // Just for compiling, delete it
}

bool matchTimeline_is_time_and_score_valid(matchTimeline mt)
{

    // COMPLETAR

    return true;
}

/* ============================================================================
CONSTRUCTOR
============================================================================ */

matchTimeline matchTimeline_empty(void)
{
    matchTimeline mt = NULL;

    // COMPLETAR

    assert(invrep(mt));
    return mt;
}

/* ============================================================================
INSERTION
============================================================================ */

static struct s_node *create_node(team team, event e, time t, playerNumber pn)
{

    struct s_node *new_node = NULL;

    // COMPLETAR

    return new_node;
}

/* ============================================================================
GOAL
============================================================================ */

matchTimeline matchTimeline_score_goal(matchTimeline mt, team team, time t, playerNumber pn)
{
    assert(invrep(mt));
    
    // COMPLETAR

    return mt;
}

/* ============================================================================
THE CARDS
============================================================================ */

matchTimeline matchTimeline_receive_yellowCard(matchTimeline mt, team team, time t, playerNumber pn)
{
    assert(invrep(mt));

    // COMPLETAR

    return mt;
}

matchTimeline matchTimeline_receive_redCard(matchTimeline mt, team team, time t, playerNumber pn)
{
    assert(invrep(mt));

    // COMPLETAR

    return mt;
}

/* ============================================================================
SCORE
============================================================================ */

unsigned int matchTimeline_get_score(matchTimeline mt, team team)
{
    assert(invrep(mt));

    // COMPLETAR

    return 0;
}

/* ============================================================================
SIZE
============================================================================ */

unsigned int matchTimeline_size(matchTimeline mt)
{
    assert(invrep(mt));
    // COMPLETAR

    return 0;
}

/* ============================================================================
PRINT
============================================================================ */

void matchTimeline_print(matchTimeline mt)
{
    fprintf(
        stdout, "            Home %u -  %u Away \n", 
        matchTimeline_get_score(mt, Home), 
        matchTimeline_get_score(mt, Away)
    );

    struct s_node *aux = mt->head;
    while (aux != NULL)
    {
        unsigned int t = aux->t;
        char *e;
        switch (aux->e)
        {
        case Goal:
            e = "    Goal   ";
            break;
        case YellowCard:
            e = "Yellow Card";
            break;
        case RedCard:
            e = "  Red Card ";
            break;
        }
        unsigned int pn = aux->pn;

        if (aux->team == Home) {
            fprintf(stdout, "%u - %s - %u' \n", pn, e, t);
        }
        else {
            fprintf(stdout, "                   %u' - %s - %u \n", t, e, pn);
        }

        aux = aux->next;
    }
}

/* ============================================================================
ARRAY
============================================================================ */

event *matchTimeline_events_array(matchTimeline mt)
{
    event *array = NULL;
    
    // COMPLETAR

    return array;
}

/* ============================================================================
DESTRUCTOR!
============================================================================ */

static struct s_node *destroy_node(struct s_node *node)
{
    
    // COMPLETAR
    return node;
}

matchTimeline matchTimeline_destroy(matchTimeline mt)
{
    assert(invrep(mt));

    // COMPLETAR

    return mt;
}
