/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "my.h"
#include "mym.h"

int main(int arc, char *arv[], char **env)
{
    Mysh *mysh;
    int ret = 0;
    mysh = malloc(sizeof(Mysh));

    if (env[0] == NULL)
        return (84);
    if (arc != 1)
        return (84);
    ret = main_loop(env, mysh);
    if (mysh->retur != 0)
        return (mysh->retur);
    return (ret);
}
