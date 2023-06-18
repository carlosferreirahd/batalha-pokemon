#ifndef STORAGE_H
#define STORAGE_H

#include "pokemon.h"

void save_list_to_file(pokemon *list, int size);

void read_list_from_file(pokemon **list, int *size);

#endif
