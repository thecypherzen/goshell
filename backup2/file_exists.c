#include "gosh.h"
#define MAX_INPUT_SIZE 100

/**
* file_exist - a function to check if file exists and is X_OK
* @command: the executable command passed
* @directory: the path to which the cmd will be concatenated
* Return: 0 if file is F_OK & X_OK or -1 if not.
*/
int file_exist(const char *command, const char *directory) {
  char path[MAX_INPUT_SIZE];
  size_t i = 0, j = 0;
  int Kup;

  while (directory[i] != '\0' && i < MAX_INPUT_SIZE - 1) {
    path[i] = directory[i];
    i++;
  }

  if (i < MAX_INPUT_SIZE - 1) {
    path[i] = '/';
    i++;
  }

  while (command[j] != '\0' && i < MAX_INPUT_SIZE - 1) {
    path[i] = command[j];
    i++, j++;
  }
  path[i] = '\0';
  gosh_printf("the path is: %s\n", path);
  Kup = (access(path, F_OK | X_OK));
  gosh_printf("kup: %d\n", Kup);
  if (Kup == 0)
    return (0);
  else
    return (-1);
}