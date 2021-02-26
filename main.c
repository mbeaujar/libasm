/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:07:52 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/22 22:02:30 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define WRITE 1

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

	void ft_check_strdup()
{
	char *str1 = "Hello world !";
	char *str2 = "";
	char *save;
	char *save2;

    printf("\n*******************************\n");
    printf("*********** FT_STRDUP *********\n");
    printf("*******************************\n\n");
	printf("%-20s: \"%s\"\n", "char *", str1);
	save = strdup(str1);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(str1);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	printf("%-20s: \"%s\"\n", "char *", str2);
	save = strdup(str2);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(str2);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

}
void ft_clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void ft_check_strcpy()
{
	char buffer[30];

	char *str1 = "";
	char *str2 = "Hello world !";
	char *str3 = "abcdefghijklmnopqrstuvwxyz";

    printf("\n*******************************\n");
    printf("*********** FT_STRCPY *********\n");
    printf("*******************************\n\n");
	printf("%-20s: \"%s\"\n", "char []", str1);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, str1));
	ft_clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, str1));
	ft_clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", str2);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, str2));
	ft_clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, str2));
	ft_clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", str3);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, str3));
	ft_clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, str3));
	ft_clear_buffer(buffer, 30);
	printf("\n");
}


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

int cmp(void *data, void *data_ref)
{
	if ((int)data > (int)data_ref)
		return (1);
	return (0);
}

t_list	*ft_create_elem(void *data)
{
	t_list *element;

	if (!(element = malloc(sizeof(t_list))))
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (! list)
	{
		list = ft_create_elem(data);
	}
	else
	{
		while ((list)->next)
		{
			list = list->next;
		}
		list->next = ft_create_elem(data);
	}
}

void printlist(t_list *begin)
{
	if (!begin)
		return;
	printf("| ");
	while (begin->next != NULL)
	{
		printf("%c -> ", (char)begin->data);
		begin = begin->next;
	}
	if (begin->next == NULL)
		printf("%c -> NULL |\n", (char)begin->data);
}

void freelist(t_list *begin)
{
	t_list *tmp;

	if (!begin)
		return;
	while (begin->next != NULL)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
	free(begin);
}
	
void ft_list_sort(t_list **begin_list, int (*cmp)());

int main(void)
{
	t_list *list = ft_create_elem((void *)'a');
	ft_list_push_back(&list, (void *)'z');
	ft_list_push_back(&list, (void *)'q');
	ft_list_push_back(&list, (void *)'r');
	ft_list_push_back(&list, (void *)'t');
	printlist(list);
	//ft_list_remove_if(&list, (void *)9, cmp, free);
	ft_list_sort(&list, cmp);
	printlist(list);
	freelist(list);
	return (0);
}

