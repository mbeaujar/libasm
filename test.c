#include "main.h"

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}


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

int cmp(char *data, char *data_ref)
{
	if (data[0] != data_ref[0])
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
		printf("%s -> ", (char *)begin->data);
		begin = begin->next;
	}
	if (begin->next == NULL)
		printf("%s -> NULL |\n", (char *)begin->data);
}

void freelist(t_list *begin)
{
	t_list *tmp;

	if (!begin)
		return;
	if (!begin->data)
		return;
	while (begin->next != NULL)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp->data);
		free(tmp);
	}
	free(begin->data);
	free(begin);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void check_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(empty));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(hello_world));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(hello_world));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(alphabet));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(alphabet));
	printf("\n");
	
	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", alphabet);
	// printf("%-20s: 0\n", "expected lenght");
	// printf("%-20s: %zu\n", "libc", strlen(NULL));	
	// printf("%-20s: %zu\n", "libasm", ft_strlen(NULL));
	// printf("\n");
}


void check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";
	
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_human));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_human));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_world2));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_world2));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world2, empty));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world2, empty));
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", hello_world2);
	// printf("%-20s: %s\n", "compared to", "NULL");
	// printf("%-20s: \"%d\"\n", "libc", strcmp(NULL, hello_world2));
	// printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(NULL, empty));
	// printf("\n");
}


void check_write()
{
	char *hello_world = "Coucou\n";
	char *empty = "";

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, hello_world, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, empty, 0));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, empty, 0));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(-7, NULL, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(-7, NULL, 7));
	// printf("\n");
	
}


void check_read()
{
	int fd = open("main.c", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	printf("%-20s: \n", "header main.c | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("main.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header main.c | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("test", O_RDONLY);
	printf("%-20s: \n", "file test | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("test", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "file test | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("wrong", O_RDONLY);
	printf("%-20s: \n", "wrong | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "wrong | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
}
