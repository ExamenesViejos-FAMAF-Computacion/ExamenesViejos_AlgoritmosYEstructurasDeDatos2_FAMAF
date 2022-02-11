#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "sorted_list.h"
#include "list.h"

sorted_list_t sorted_list_empty()
{
    // COMPLETE HERE
}

bool sorted_list_is_empty(sorted_list_t list)
{
	// COMPLETE HERE
}

elem_t sorted_list_head(sorted_list_t list)
{
	// COMPLETE HERE
}

sorted_list_t sorted_list_append(sorted_list_t list, elem_t elem)
{
   // COMPLETE HERE
}

sorted_list_t sorted_list_tail(sorted_list_t list)
{
    // COMPLETE HERE
}

unsigned int sorted_list_length(sorted_list_t list)
{
   // COMPLETE HERE
}

elem_t sorted_list_elem_at(sorted_list_t list, unsigned int index)
{
  // COMPLETE HERE
}

sorted_list_t sorted_list_take(sorted_list_t list, unsigned int num)
{
   // COMPLETE HERE
}

sorted_list_t sorted_list_drop(sorted_list_t list, unsigned int num)
{
   // COMPLETE HERE
}

void sorted_list_print(sorted_list_t list)
{
   // COMPLETE HERE
}

sorted_list_t sorted_list_destroy(sorted_list_t list)
{
   // COMPLETE HERE 
}
