#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/validations.h"

const char *valid_types[] = {"fire", "grass", "water", "electric", "ground"};

const int num_types = sizeof(valid_types) / sizeof(valid_types[0]);

bool is_valid_name(char *name)
{
  return strchr(name, ',') == NULL;
}

bool is_valid_type(char *type)
{
  for (int i = 0; i < num_types; i++)
  {
    if (strcmp(type, valid_types[i]) == 0)
      return true;
  }

  return false;
}

bool is_valid_stat(int stat)
{
  return stat > 0;
}

bool is_valid_id(pokemon *pokemon_list, int list_size, int id)
{
  for (int i = 0; i < list_size; i++)
  {
    if (pokemon_list[i].id == id)
      return false;
  }

  return true;
}

int generate_valid_id(pokemon *pokemon_list, int list_size)
{
  int random_id = 1;
  int min = 1;
  int max = 99;

  srand(time(NULL));

  while (!is_valid_id(pokemon_list, list_size, random_id))
  {
    random_id = min + rand() % (max - min + 1);
  }

  return random_id;
}

bool is_valid_pokemon(pokemon p)
{
  if (!is_valid_name(p.name))
    return false;

  if (!is_valid_type(p.type))
    return false;

  const int attrs[] = {p.hp, p.atk, p.def, p.m_atk, p.m_def, p.sp};
  const int attrs_size = sizeof(attrs) / sizeof(attrs[0]);

  for (int i = 0; i < attrs_size; i++)
  {
    if (!is_valid_stat(attrs[i]))
      return false;
  }

  return true;
}
