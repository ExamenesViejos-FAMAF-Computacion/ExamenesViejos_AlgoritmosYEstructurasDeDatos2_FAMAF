#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "walk.h"
#include "helpers.h"

#define ADD_N    'n'
#define ADD_E    'e'
#define ADD_X    'x'
#define SIMPLIFY 's'
#define EXTEND   't'
#define EMPTY    'v'
#define QUIT     'q'

#define RESULT_PREFIX "\t-> "

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s\n\n", program_name);
}

char print_menu(void) {
    char result = '\0';
    char *line = NULL;

    printf("\nChoose what you want to do. Options are:\n"
	   "\n"
	   "\t************************************************\n"
	   "\t* n: Move to the north                         *\n"
	   "\t* e: Move to the east                          *\n"
	   "\t* x: Move to the northeast                     *\n"
	   "\t* s: Simplify the walk                         *\n"
	   "\t* t: Extend the walk                           *\n" 
	   "\t* v: Empty the walk                            *\n" 
	   "\t* q: Quit                                      *\n"
	   "\t************************************************\n"
	   "\nPlease enter your choice: ");

    line = readline_from_stdin();
    if (line != NULL) {
	result = line[0];
    }

    free(line);
    return(result);
}

bool is_valid_option(char option) {
    bool result = false;

    result = (option == ADD_N ||
	      option == ADD_E ||
	      option == ADD_X ||
	      option == SIMPLIFY ||
	      option == EMPTY ||
	      option == EXTEND ||
	      option == QUIT);
    return(result);
}

char *get_input(const char *message) {
    char *result = NULL;
    printf("\t%s: ", message);
    result = readline_from_stdin();
    assert(result != NULL);
    return(result);
}

int read_uint(const char * message, unsigned int * v) {
    int count = 0;
    char * word = NULL;
    word  = get_input(message);
    count = sscanf(word,"%u",v);
    free(word);
    return count;
}

static walk_t on_extend(walk_t walk) {
    unsigned int width  = 0;
    unsigned int height = 0;
    unsigned int count_w = 0;
    unsigned int count_h = 0;

    count_w  = read_uint("Number of steps to east" ,&width);
    count_h  = read_uint("Number of steps to north",&height);
    if(count_w > 0 && count_h > 0) {
	walk = walk_extend(walk,width,height);
    }
    else {
	printf(RESULT_PREFIX "Invalid unsigned integer.\n");
    }
    return walk;
}


int main(void) {
    char option = '\0';
    walk_t current = walk_empty();
    do {
        printf("Your walk: \n");
        walk_dump(current);
        option = print_menu();
        switch (option) {
        case ADD_N:  current = walk_north(current); break;
        case ADD_E:  current = walk_east(current); break;
        case ADD_X:  current = walk_northeast(current); break;
        case EMPTY:
            //complete here
        case EXTEND: on_extend(current); break;
        case QUIT:
            //complete here
        default:
            printf("\n\"%c\" is invalid. Please choose a valid "
               "option.\n\n", option);
	}
    } while (option != QUIT);
    return(EXIT_SUCCESS);
}
