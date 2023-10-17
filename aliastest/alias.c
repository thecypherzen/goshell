#include "gosh.h"

/**
* gosh_print_aliases - a function that prints alias to stdout
* Return: void
*/

static struct alias alias_list[MAX_A_VAR_SIZE];
int alias_count = 0;

/* Function to print aliases */
int gosh_print_aliases(void)
{
        for (int i = 0; i < alias_count; i++)
        {
                gosh_printf("alias %s='%s'\n", alias_list[i].a_name, alias_list[i].a_value);
        }
        return (0);
}

/* Function to find an alias by name */
struct alias *gosh_find_alias(char *name)
{
        for (int i = 0; i < alias_count; i++) 
        {
                if (strcmp(name, alias_list[i].a_name) == 0)
                {
                       return (&alias_list[i]);
                }
        }
        return (NULL);
}

/* Function to define or update an alias */
int gosh_define_alias(char *name, char *value)
{
        struct alias *existing = gosh_find_alias(name);

        if (existing)
        {
                /* Update an existing alias */
                strncpy(existing->a_value, value, MAX_A_VALUE);
        }
        else if (alias_count < MAX_A_VAR_SIZE)
        {
                /*Define a new alias */
                strncpy(alias_list[alias_count].a_name, name, MAX_A_NAME);
                strncpy(alias_list[alias_count].a_value, value, MAX_A_VALUE);
                alias_count++;
        }
        else
        {
                printf("Alias limit exceeded. Unable to define alias.\n");
                return (-1);
        }
        return (0);
}