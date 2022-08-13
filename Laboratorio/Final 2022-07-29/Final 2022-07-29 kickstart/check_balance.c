#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"

#define GREEN "\033[38;2;0;200;0m"
#define RED "\033[0;31m"
#define NOCOLOR "\033[0m"

static void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <expression-to-check>\n\n"
           "Check if the expression has balanced parenthesis.\n",
           program_name);
}

static char* parse_expression(int argc, char *argv[]) {
    /* Parse the expression given by command line argument. */
    char *result=NULL;
    /* Program takes exactly one argument */
    if (argc != 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Use the first argument ass the expression */
    result = argv[1];
    /* return expression */
    return result;
}

static bool
is_parenthesis(char c) {
    return c=='(' || c==')';
}

int main(int argc, char *argv[]) {
    // Parse arguments and get the expression to be analysed
    char *expression = parse_expression(argc, argv);
    size_t expression_length= // COMPLETAR;
    size_t i=0;
    bool is_balanced=true;
    stack s = stack_empty();

    while (i < expression_length && is_balanced) {
        char chr = expression[i];
        if (is_parenthesis(chr)) {
            /*
             * COMPLETAR
             *
             */
        }
        i++;
    }

    is_balanced = is_balanced && /* COMPLETAR */;

    if (is_balanced) {
        printf(GREEN "The given expression is balanced\n" NOCOLOR);
    } else {
        printf(RED "The given expresión is not balanced\n" NOCOLOR);

    }
    // Free all memory used by the stack
    // COMPLETAR
    return EXIT_SUCCESS;
}

