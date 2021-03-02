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

#include "main.h"

void br(void)
{
	printf("|----------------------------------------------------|\n");
}

void listremove_if(void)
{
	printf("\n=====================================\n");
	printf("========== FT_REMOVE_IF =============\n");
	printf("=====================================\n\n");

	t_list *list = ft_create_elem((void *)ft_strdup("milk"));
	ft_list_push_back(&list, (void *)ft_strdup("milk"));
	ft_list_push_back(&list, (void *)ft_strdup("milk"));
	char *void_ref = ft_strdup("milk");
	printf("remove : \"%s\" | avant :\n", void_ref);
	printlist(list);
	ft_list_remove_if(&list, (void *)void_ref, strcmp, free);
	free(void_ref);
	printf("apres :\n");
	printlist(list);
	freelist(list);

	br();	
	list = ft_create_elem((void *)ft_strdup("Apple"));
	ft_list_push_back(&list, (void *)ft_strdup("bread"));
	ft_list_push_back(&list, (void *)ft_strdup("milk"));
	void_ref = ft_strdup("bread");
	printf("remove : \"%s\" | avant :\n", void_ref);
	printlist(list);
	ft_list_remove_if(&list, (void *)void_ref, strcmp, free);
	free(void_ref);
	printf("apres :\n");
	printlist(list);
	freelist(list);

	br();
	list = ft_create_elem((void *)ft_strdup("Apple"));
	void_ref = ft_strdup("Apple");
	printf("remove : \"%s\" | avant :\n", void_ref);
	printlist(list);
	ft_list_remove_if(&list, (void *)void_ref, strcmp, free);
	free(void_ref);
	printf("apres :\n");
	printlist(list);
	freelist(list);

	br();	
	list = NULL;
	void_ref = ft_strdup("bread");
	printf("remove : \"%s\" | avant :\n", void_ref);
	printlist(list);
	ft_list_remove_if(&list, (void *)void_ref, strcmp, free);
	free(void_ref);
	printf("apres :\n");
	printlist(list);
	freelist(list);

	br();	
	list = ft_create_elem((void *)ft_strdup("Apple"));
	ft_list_push_back(&list, (void *)ft_strdup("bread"));
	ft_list_push_back(&list, (void *)ft_strdup("milk"));
	void_ref = NULL;
	printf("remove : \"%s\" | avant :\n", void_ref);
	printlist(list);
	ft_list_remove_if(&list, (void *)void_ref, strcmp, free);
	//free(void_ref);
	printf("apres :\n");
	printlist(list);
	freelist(list);


	br();	
	list = ft_create_elem((void *)ft_strdup("Apple"));
	ft_list_push_back(&list, (void *)ft_strdup("bread"));
	ft_list_push_back(&list, (void *)ft_strdup("milk"));
	void_ref = ft_strdup("bread");
	printf("remove : \"%s\" | avant :\n", void_ref);
	printf("strcmp : NULL\n");
	printlist(list);
	ft_list_remove_if(&list, (void *)void_ref, NULL, free);
	free(void_ref);
	printf("apres :\n");
	printlist(list);
	freelist(list);

	br();	
	list = ft_create_elem((void *)ft_strdup("Apple"));
	ft_list_push_back(&list, (void *)ft_strdup("bread"));
	ft_list_push_back(&list, (void *)ft_strdup("milk"));
	void_ref = ft_strdup("bread");
	printf("remove : \"%s\" | avant :\n", void_ref);
	printf("free_fct : NULL\n");
	printlist(list);
	ft_list_remove_if(&list, (void *)void_ref, strcmp, NULL);
	free(void_ref);
	printf("apres :\n");
	printlist(list);
	freelist(list);


}

void listsort(void)
{
	printf("\n=====================================\n");
	printf("========== FT_LIST_SORT =============\n");
	printf("=====================================\n\n");


	t_list *list = ft_create_elem((void *)ft_strdup("Apple"));
	ft_list_push_back(&list, (void *)ft_strdup("bread"));
	ft_list_push_back(&list, (void *)ft_strdup("milk"));
	printf("avant :\n");
	printlist(list);
	ft_list_sort(&list, strcmp);
	printf("apres :\n");
	printlist(list);
	freelist(list);

	br();	
	list = ft_create_elem((void *)ft_strdup("milk"));
	ft_list_push_back(&list, (void *)ft_strdup("Apple"));
	ft_list_push_back(&list, (void *)ft_strdup("bread"));
	printf("avant :\n");
	printlist(list);
	ft_list_sort(&list, strcmp);
	printf("apres :\n");
	printlist(list);
	freelist(list);

	br();	
	list = ft_create_elem((void *)ft_strdup("milk"));
	ft_list_push_back(&list, (void *)ft_strdup("Apple"));
	ft_list_push_back(&list, (void *)ft_strdup("bread"));
	printf("avant :\n");
	printf("strcmp : NULL\n");
	printlist(list);
	ft_list_sort(&list, NULL);
	printf("apres :\n");
	printlist(list);
	freelist(list);
}

void listpushfront_and_size(void)
{	
	printf("\n===========================================\n");
	printf("========== FT_LIST_PUSH_FRONT =============\n");
	printf("===========================================\n\n");


	t_list *list = ft_create_elem((void *)ft_strdup("milk"));
	ft_list_push_front(&list, (void *)ft_strdup("Apple"));
	ft_list_push_front(&list, (void *)ft_strdup("bread"));
	printf("list :\n");
	printlist(list);
	printf("\n=====================================\n");
	printf("========== FT_LIST_SIZE =============\n");
	printf("=====================================\n\n");

	printf("size : %d\n", ft_list_size(list));
	freelist(list);
}

void atoi_base(void)
{

	printf("\n=====================================\n");
	printf("========== FT_ATOI_BASE =============\n");
	printf("=====================================\n\n");


	printf("ft_atoi_base(\"7f\", \"0123456789abcdef\")");
	printf(" = %d\n\n", ft_atoi_base("7f", "0123456789abcdef"));
	printf("ft_atoi_base(\"10\", \"0123456789\")");
	printf(" = %d\n\n", ft_atoi_base("10", "0123456789"));
	printf("ft_atoi_base(\"10000\", \"0123456789\")");
	printf(" = %d\n\n", ft_atoi_base("10000", "0123456789"));
	printf("ft_atoi_base(\"NULL\", \"0123456789\")");
	printf(" = %d\n\n", ft_atoi_base("NULL", "0123456789"));
	printf("ft_atoi_base(\"100\", \"NULL\")");
	printf(" = %d\n\n", ft_atoi_base("100", "NULL"));
}


int main(void)
{
	ft_check_strdup();
	ft_check_strcpy();
	check_strlen();
	check_strcmp();
	check_write();
	check_read();
	listremove_if();
	listsort();
	listpushfront_and_size();
	atoi_base();
	return (0);
}
