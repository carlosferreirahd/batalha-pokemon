#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include <stdbool.h>
#include "pokemon.h"

bool is_valid_type(char *type);

bool is_valid_stat(int stat);

bool is_valid_id(pokemon* pokemon_list, int id);

bool is_valid_pokemon(pokemon p);

#endif
