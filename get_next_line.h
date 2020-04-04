/*
** EPITECH PROJECT, 2020
** getnextline.h
** File description:
** getnextline.h
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef READ_SIZE
#define READ_SIZE (3)
#endif

#define MALLOC (3000000)

#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define COP_COND (ptr = (*str), recup[i++] = (*str)->c, \
                  (*str) = (*str)->next, free(ptr))

#define OT_COP_COND (ptr = (*str), (*str) = (*str)->next, free(ptr))

typedef struct list {
    char c;
    int data;
    struct list *next;
} t_list;

t_list *push_to_list(t_list *list, char c);
int check_list_string(t_list *str);
char *to_from(t_list **str);
char *get_next_line(int fd);

#endif
