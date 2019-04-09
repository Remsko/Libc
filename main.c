#include "list_42.h"
#include "string_42.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_rand
{
    char *test;
    t_list list;
    int nugget;
} t_rand;

int main(void)
{
    t_rand *test;
    t_rand *tmp;
    t_rand list;

    list_head_init(&list.list);
    int i = 0;
    while (i < 5)
    {
        tmp = (t_rand *)malloc(sizeof(t_rand));
        if (i == 0)
            tmp->test = ft_strdup("1");
        if (i == 1)
            tmp->test = ft_strdup("2");
        if (i == 2)
            tmp->test = ft_strdup("3");
        if (i == 3)
            tmp->test = ft_strdup("4");
        if (i == 4)
            tmp->test = ft_strdup("5");
        list_head_init(&tmp->list);
        list_add(&(tmp->list), &(list.list));
        ++i;
    }
    t_list *stop = &list.list;
    t_list *pos = stop->next;
        list_del(pos->prev, pos->next);
    while (pos != stop)
    {
        tmp = LIST_ENTRY(pos, t_rand, list);
        printf("%s\n", tmp->test);
        pos = pos->next;
    }
    return (0);
}