#ifndef POKEMON_H
#define POKEMON_H

typedef struct pokemon_struct
{
  int id;
  char name[64];
  char type[16];
  int hp;
  int atk;
  int def;
  int m_atk;
  int m_def;
  int sp;
} pokemon;

const char *valid_types[] = {"fire", "grass", "water", "electric", "ground"};

const int num_types = sizeof(valid_types) / sizeof(valid_types[0]);

pokemon create_pokemon(int id, char *name, char *type, int hp, int atk, int def, int m_atk, int m_def, int sp);

#endif
