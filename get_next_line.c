/*
** EPITECH PROJECT, 2020
** bttf gnl with linked list
** File description:
** bttf gnl with linked list
*/

#include "get_next_line.h"

t_list *push_to_list(t_list *list, char c)
{
    t_list *ret = list;
    t_list *one_char = malloc(sizeof(t_list));

    if (one_char == NULL)
        return (NULL);
    one_char->c = c;
    one_char->next = NULL;
    if (list == NULL)
        return (one_char);
    while (ret->next != NULL)
        ret = ret->next;
    ret->next = one_char;
    return (list);
}

int check_n_and_zero(t_list *str)
{
    for (t_list *ret = str; ret != NULL; ret = ret->next) {
        if (ret->c == '\n' || ret->c == '\0')
            return (1);
    }
    return (0);
}

char *to_from(t_list **str)
{
    int i = 0;
    t_list *ptr;
    char *recup = malloc(sizeof(char) * MALLOC + 1);

    if (recup == NULL)
        return (NULL);
    else if ((*str) == NULL)
        return (NULL);
    while ((*str) != NULL && (*str)->c != '\n' && (*str)->c != '\0')
        COP_COND;
    ((*str) != NULL) ? OT_COP_COND : 0;
    recup[i] = '\0';
    return (recup);
}

char *get_next_line(int fd)
{
    char buffer[READ_SIZE];
    static t_list *str;
    int i = 0;
    int cnt = 0;

    while (i < READ_SIZE)
        buffer[i++] = '\0';
    if ((cnt = read(fd, buffer, READ_SIZE)) < 0)
        return (NULL);
    else if (cnt == 0)
        return (to_from(&str));
    for (i = 0; i < cnt; i++)
        str = push_to_list(str, buffer[i]);
    return ((check_n_and_zero(str) == 1) ? to_from(&str) : get_next_line(fd));
}
