#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/pokemon.h"
#include "../include/validations.h"
#include "../include/storage.h"

pokemon *all_pokemon = NULL;

int all_pokemon_size = 0;

void clear_screen()
{
  system("clear");
}

void show_simple_list()
{
  if (all_pokemon_size == 0)
  {
    printf("list is empty\n");
    return;
  }

  for (int i = 0; i < all_pokemon_size; i++)
  {
    show_simple_stats(all_pokemon[i]);
    printf("\n");
  }
}

void show_detailed_list()
{
  if (all_pokemon_size == 0)
  {
    printf("list is empty\n");
    return;
  }

  for (int i = 0; i < all_pokemon_size; i++)
  {
    show_all_stats(all_pokemon[i]);
    printf("\n");
  }
}

bool insert_new_pokemon()
{
  int id, hp, atk, def, m_atk, m_def, sp;
  char name[64], type[16];

  id = generate_valid_id(all_pokemon, all_pokemon_size);

  printf("name: ");
  scanf("%s", name);

  printf("type: ");
  scanf("%s", type);

  printf("hp: ");
  scanf("%d", &hp);

  printf("attack: ");
  scanf("%d", &atk);

  printf("defense: ");
  scanf("%d", &def);

  printf("special attack: ");
  scanf("%d", &m_atk);

  printf("special defense: ");
  scanf("%d", &m_def);

  printf("special points: ");
  scanf("%d", &sp);

  pokemon new_pokemon = create_pokemon(id, name, type, hp, atk, def, m_atk, m_def, sp);

  bool pokemon_is_valid = is_valid_pokemon(new_pokemon);

  if (!pokemon_is_valid)
    return false;

  all_pokemon = (pokemon *)realloc(all_pokemon, (all_pokemon_size + 1) * sizeof(pokemon));

  all_pokemon[all_pokemon_size] = new_pokemon;

  all_pokemon_size++;

  return true;
}

bool remove_pokemon()
{
  int id;

  printf("id to be removed: ");
  scanf("%d", &id);

  int id_pos = find_pokemon_by_id(all_pokemon, all_pokemon_size, id);

  if (id_pos == -1)
    return false;

  // swaping last pokemon with the one to be removed
  all_pokemon[id_pos] = all_pokemon[all_pokemon_size - 1];

  // now removing last position
  all_pokemon = (pokemon *)realloc(all_pokemon, (all_pokemon_size - 1) * sizeof(pokemon));
  all_pokemon_size--;

  return true;
}

void handle_option(int opt)
{
  switch (opt)
  {
  case 1:
    show_simple_list();
    break;
  case 2:
    show_detailed_list();
    break;
  case 3:
    bool insert_success = insert_new_pokemon();

    if (insert_success)
    {
      printf("new pokemon successfully inserted!\n");
      save_list_to_file(all_pokemon, all_pokemon_size);
    }
    else
    {
      printf("error while inserting, please try again\n");
    }
    break;
  case 4:
    bool remove_success = remove_pokemon();

    if (remove_success)
    {
      printf("pokemon removed!\n");
      save_list_to_file(all_pokemon, all_pokemon_size);
    }
    else
    {
      printf("this pokemon id was not found, try again\n");
    }
    break;
  default:
    break;
  }
}

void show_menu()
{
  printf("enter an option:\n\n");
  printf("1 - simple list\n");
  printf("2 - detailed list\n");
  printf("3 - insert new pokemon\n");
  printf("4 - remove pokemon\n");
  printf("5 - start battle\n");
  printf("0 - exit\n");
  printf("\n");
}

int main()
{
  int opt = 0;

  read_list_from_file(&all_pokemon, &all_pokemon_size);

  do
  {
    show_menu();

    scanf("%d", &opt);

    clear_screen();

    handle_option(opt);

  } while (opt != 0);

  free(all_pokemon);

  return 0;
}
