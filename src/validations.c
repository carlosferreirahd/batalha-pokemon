#include <string.h>
#include <stdbool.h>
#include "../include/validations.h"

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

bool is_valid_id(pokemon *pokemon_list, int id)
{
  const int list_size = sizeof(pokemon_list) / sizeof(pokemon_list[0]);

  for (int i = 0; i < list_size; i++)
  {
    if (pokemon_list[i].id == id)
      return false;
  }

  return true;
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
