/*
  @file bakery_product.c
  @brief Implements bakery product structure and methods
*/
#include <stdlib.h>
#include "bakery_product.h"

static const int AMOUNT_OF_PRODUCT_VARS = 7;

BakeryProduct bakery_product_from_file(FILE* file)
{
    BakeryProduct product;
    // COMPLETAR
    if (res != AMOUNT_OF_PRODUCT_VARS)
    {
        fprintf(stderr, "Invalid product data.\n");
        exit(EXIT_FAILURE);
    }
    return product;
}
