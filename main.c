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

ssize_t ft_write(int fildes, void const *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
size_t ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dst, const char *src);
char *ft_strdup(const char *s);
int ft_atoi_base(char *str, char *base);

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
int main(void)
{
	char *str;

	//printf("\nret = %zd", ft_write(1, "i", 1));
	//printf("\nret = %zd", ft_read(0, str, 7));
	//printf("string read : %s\n", str);
	//printf("len = %zd\n", ft_strlen("bonjour"));
	//printf("strcmp = %d\n", ft_strcmp("bonjour", "bonjour"));
	//ft_check_strcpy();
	//ft_check_strdup();
	printf("ret = %d\n", ft_atoi_base("10", "01"));
	return (0);
}

