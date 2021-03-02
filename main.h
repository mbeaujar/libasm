#ifndef MAIN_H
# define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "fcntl.h"

typedef struct s_list
{
	void *data;
	struct s_list *next;
}	t_list;

ssize_t ft_write(int fildes, void const *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
size_t ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dst, const char *src);
char *ft_strdup(const char *s);
int ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void ft_check_strdup(void);
void ft_clear_buffer(char *buffer, int size);
void ft_check_strcpy(void);
int cmp(char *data, char *data_ref);
t_list *ft_create_elem(void *data);
void ft_list_push_back(t_list **begin_list, void *data);
void printlist(t_list *begin);
void freelist(t_list *begin);
char *ft_strdup(const char *s1);
void check_strlen(void);
void check_strcmp(void);
void check_write(void);
void check_read(void);
int ft_list_size(t_list *begin_list);

#endif 
