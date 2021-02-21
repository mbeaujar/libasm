/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:07:52 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/21 22:13:40 by mbeaujar         ###   ########.fr       */
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

int main(void)
{
    char *str;
    
    printf("\nret = %zd", ft_write(1, "i", 1));
    printf("\nret = %zd", ft_read(0, str, 7));
    printf("string read : %s\n", str);
    printf("len = %zd\n", ft_strlen("bonjour"));
    printf("strcmp = %d\n", ft_strcmp("bonjour", "bonjour"));
    printf("strcpy = %s\n", ft_strcpy("        merci", "bonjour"));
    return (0);
}

