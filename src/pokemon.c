#include <string.h>
#include "../include/pokemon.h"

pokemon create_pokemon(int id, char *name, char *type, int hp, int atk, int def, int m_atk, int m_def, int sp)
{
  pokemon new_pokemon;

  new_pokemon.id = id;
  strcpy(new_pokemon.name, name);
  strcpy(new_pokemon.type, type);
  new_pokemon.hp = hp;
  new_pokemon.atk = atk;
  new_pokemon.def = def;
  new_pokemon.m_atk = m_atk;
  new_pokemon.m_def = m_def;
  new_pokemon.sp = sp;

  return new_pokemon;
}
