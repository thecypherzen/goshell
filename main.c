#include "gosh.h"

int main(void) {
  char *gcmd = NULL, *gprompt = "($) ";
  ssize_t ret;
  size_t gsize = 0;
  pid_t gpid;
  char *directory, *pathstep; /* ret = getargs(av) */
char **ac;
  while (1) {
    write(1, gprompt, strlen(gprompt));
    ret = getline(&gcmd, &gsize, stdin);
    if (ret < 0)
      return (-1);

    if (ret > 0 && gcmd[0] != '\n') {
      gcmd[ret - 1] = '\0';
      char *token = strtok(gcmd, " ");

      if (token != NULL) {
        if (strcmp(token, "exit") == 0) {
          /* Handle the "exit" command */
          token = strtok(NULL, " ");
          int status = 0;
          if (token != NULL) {
            status = atoi(token);
          }
          free(gcmd);
          exit(status);
        } else if (strcmp(token, "env") == 0) {
          // Handle the "env" command to print the environment
          char **env = environ;
          while (*env != NULL) {
            printf("%s\n", *env);
            env++;
          }
        } else if (strcmp(token, "setenv") == 0) {

          token = strtok(NULL, " ");
          char *value = strtok(NULL, " ");
          if (token != NULL && value != NULL) {
            if (setenv(token, value, 1) != 0) {
              fprintf(stderr, "Failed to set environment variable: %s=%s\n",
                      token, value);
            }
          } else {
            fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
          }
        } 
        else if (strcmp(token, "unsetenv") == 0) 
        {
          token = strtok(NULL, " ");
          if (token != NULL) 
          {
            if (unsetenv(token) != 0) 
            {
              fprintf(stderr, "Failed to unset environment variable: %s\n",
                      token);
            }
          } 
          else 
          {
            fprintf(stderr, "Usage: unsetenv VARIABLE\n");
          }
        } else {
          int ac = 0;
          char *av[MAX_INPUT_SIZE];

          while (token != NULL && ac < MAX_INPUT_SIZE - 1) {
            av[ac] = token;
            token = strtok(NULL, " ");
            ac++;
          }

          av[ac] = NULL;

          char *path = getenv("PATH");
          printf("PATH IS: %s\n", path);
          if (path != NULL) {
            directory = strtok(path, ":");
            while (directory != NULL) {
              pathstep = pathname(av[0], directory);
              directory = strtok(NULL, ":");
            }
          }
          if (directory == NULL) {
            fprintf(stderr, "Command not found: %s\n", av[0]);
          }
        }
      }
    } 
    else 
    {
      break;
    }
  }
  free(pathstep);
  free(gcmd);
  return 0;