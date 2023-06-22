#include <stdio.h>
#include <stdlib.h>
#include "../include/storage.h"

const char *FILEPATH = "./storage/pokedex.txt";

void save_list_to_file(pokemon *list, int size)
{
  FILE *f = fopen(FILEPATH, "w");

  if (f == NULL)
  {
    printf("something went wrong while creating file at '%s'\n", FILEPATH);
    return;
  }

  fprintf(f, "%d\n", size);

  for (int i = 0; i < size; i++)
  {
    fprintf(f, "%d,%s,%c,%d,%d,%d,%d,%d,%d\n",
            list[i].id, list[i].name, list[i].type,
            list[i].hp, list[i].atk, list[i].def,
            list[i].m_atk, list[i].m_def, list[i].sp);
  }

  fclose(f);
}

void read_list_from_file(pokemon **list, int *size)
{
  FILE *f = fopen(FILEPATH, "r");

  if (f == NULL)
  {
    *size = 0;
    *list = (pokemon *)malloc((*size) * sizeof(pokemon));
    save_list_to_file(*list, *size);
    return;
  }

  fscanf(f, "%d\n", size);

  *list = (pokemon *)malloc((*size) * sizeof(pokemon));

  for (int i = 0; i < *size; i++)
  {
    fscanf(f, "%d,%[^,],%c,%d,%d,%d,%d,%d,%d\n",
           &((*list)[i].id), (*list)[i].name, &(*list)[i].type,
           &((*list)[i].hp), &((*list)[i].atk), &((*list)[i].def),
           &((*list)[i].m_atk), &((*list)[i].m_def), &((*list)[i].sp));
  }

  fclose(f);
}
