#include <stdio.h>
#include <string.h>
#include "../include/pokemon.h"

pokemon create_pokemon(int id, char *name, char type, int hp, int atk, int def, int m_atk, int m_def, int sp)
{
  pokemon new_pokemon;

  new_pokemon.id = id;
  strcpy(new_pokemon.name, name);
  new_pokemon.type = type;
  new_pokemon.hp = hp;
  new_pokemon.atk = atk;
  new_pokemon.def = def;
  new_pokemon.m_atk = m_atk;
  new_pokemon.m_def = m_def;
  new_pokemon.sp = sp;

  return new_pokemon;
}

void show_simple_stats(pokemon p)
{
  printf("id: %d\n", p.id);
  printf("name: %s\n", p.name);
}

void show_all_stats(pokemon p)
{
  printf("id: %d\n", p.id);
  printf("name: %s\n", p.name);
  printf("type: %c\n", p.type);
  printf("hp: %d\n", p.hp);
  printf("attack: %d\n", p.atk);
  printf("defense: %d\n", p.def);
  printf("special attack: %d\n", p.m_atk);
  printf("special defense: %d\n", p.m_def);
  printf("special points: %d\n", p.sp);
}

int find_pokemon_by_id(pokemon *pokemon_list, int list_size, int id)
{
  for (int i = 0; i < list_size; i++)
  {
    if (pokemon_list[i].id == id)
      return i;
  }

  return -1;
}
