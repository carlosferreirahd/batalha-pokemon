#ifndef POKEMON_H
#define POKEMON_H

typedef struct pokemon_struct
{
  int id;
  char name[64];
  char type;
  int hp;
  int atk;
  int def;
  int m_atk;
  int m_def;
  int sp;
} pokemon;

pokemon create_pokemon(int id, char *name, char type, int hp, int atk, int def, int m_atk, int m_def, int sp);

void show_simple_stats(pokemon p);

void show_all_stats(pokemon p);

int find_pokemon_by_id(pokemon *pokemon_list, int list_size, int id);

#endif
