/*
** EPITECH PROJECT, 2022
** my.r
** File description:
** my.r
*/

#ifndef MYM_H
    #define MYM_H

typedef struct {
    int num_args;
    char **args;
} Pipe;

typedef struct {
    char **new_env;
    char **args;
    char *home;
    char *pwd;
    char *hold;
    char *oldpwd;
    char *path;
    int retur;
    int num_cmd;
    int index;
    int num_pipes;
    int find_env;
    int len_env;
    int find_pwd;
    int find_oldpwd;
    Pipe *pipes;
} Mysh;

    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <signal.h>

    int main(int arc, char *arv[], char **env);
    int main_loop(char **env, Mysh *mysh);
    int find_command(char *command, Mysh *mysh);
    int execute_command(char *command);
    void print_env(Mysh *mysh);
    char* my_strnncat(char* dest, const char* src, size_t n, size_t m);
    int all_builtins(char **args, Mysh *mysh);
    void execute_cd(Mysh *mysh, char **args);
    void change_pwd(Mysh *mysh);
    char* find_command_path(Mysh *mysh, char **args);
    int check_child_command(char *command, char **args, char *path, Mysh *mysh);
    void change_oldpwd(Mysh *mysh, char *cwd);
    void event_setenv(Mysh *mysh, char **args);
    char **event_unsetenv(Mysh *mysh, char **args);
    char **copy_array(char **array);
    char **copy_array_remove(char **array, int remove_line);
    char **copy_array_add(char **array, int add_line);
    char* my_strnncat(char* dest, const char* src, size_t n, size_t m);
    char **str_to_word_array(char *str, char separator);
    int check_type_child_next(char *command, char **args,
    char *path, Mysh *mysh);
    int search_pipe(char **args);
    char* my_strdup(const char* str);
    int exe_separator(Mysh *mysh, char *command);
    int search_separator(char **args);
    void fill_args(Mysh *mysh, char *command);
    int exe_pipe(Mysh *mysh, char *command);
#endif
