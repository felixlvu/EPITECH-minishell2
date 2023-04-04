/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"
#include <string.h>

void remove_space(Mysh *mysh, char **test)
{
    char *token;
    mysh->pipes = malloc(sizeof(Pipe) * mysh->num_pipes);
    int p = 0;
    for (p = 0; p < mysh->num_pipes; p++) {
        mysh->pipes[p].args = malloc(sizeof(char *) * (my_strlen(test[p]) + 1));
        token = strtok(test[p], " \t\r\n\a");
        int f = 0;
        while (token != NULL) {
            mysh->pipes[p].args[f] = token;
            f++;
            token = strtok(NULL, " \t\r\n\a");
        }
        mysh->pipes[p].args[f] = NULL;
    }
    mysh->num_cmd = p + 1;
}

void fill_args(Mysh *mysh, char *command)
{
    char *token;
    int i = 0;
    char **test = NULL;

    test = malloc(sizeof(char *) * (my_strlen(command) + 1));
    token = strtok(command, "|");
    while (token != NULL) {
        test[i] = token;
        i++;
        token = strtok(NULL, "|");
    }
    test[i] = NULL;
    mysh->num_pipes = i;
    remove_space(mysh, test);

    free(test);
}
