#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include "pokemon.h"

bool is_valid_name(char *name);

bool is_valid_type(char type);

bool is_valid_stat(int stat);

bool is_valid_id(pokemon *pokemon_list, int list_size, int id);

bool is_valid_pokemon(pokemon p);

int generate_valid_id(pokemon *pokemon_list, int list_size);

#endif
