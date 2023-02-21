#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "position.h"

struct _position {
        unsigned int row;
        unsigned int column;
        unsigned int dimension;
};


position_t position_initial(unsigned int dimension)
{
        // COMPLETE HERE
}

position_t position_absolute(unsigned int row, unsigned int column,
                             unsigned int dimension)
{
        // COMPLETE HERE
}

position_t position_left(position_t pos)
{
        // COMPLETE HERE
}

position_t position_right(position_t pos)
{
        // COMPLETE HERE
}

position_t position_down(position_t pos)
{
        // COMPLETE HERE
}

position_t position_up(position_t pos)
{
        // COMPLETE HERE
}

unsigned int position_row(position_t pos)
{
        // COMPLETE HERE
}

unsigned int position_column(position_t pos)
{
        // COMPLETE HERE
}

unsigned int **position_board(position_t pos)
{
        // COMPLETE HERE
}

list_t position_movements(position_t pos)
{
        // COMPLETE HERE
}

position_t position_destroy(position_t pos)
{
        // COMPLETE HERE
}
