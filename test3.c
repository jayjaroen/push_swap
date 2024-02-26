/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:56:53 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/26 12:44:43 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	ft_free_node(t_node **list);

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (sign * num);
}

void	ft_add_list_back(t_node **list, int i)
{
	t_node	*new;
	t_node 	*head;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		ft_free_node(list);
		return ;
	}
	
	//need to free after --> error hand - check stack a & b
	
	head = *list;
	new -> value = i;
	/// first node ////
	if (head == NULL)
	{
		new -> previous = NULL;
		new -> next = NULL;
		*list = new;
	}
	else if (head->next == NULL)
	{
		new -> next = head;
		new -> previous = head;
		head -> previous = new;
		head -> next = new;
	}
	else 
	{
		new -> next = head;
		new -> previous = head -> previous;
		new -> previous -> next = new; // update the last node of the list
		head -> previous = new;
	}
}

void	ft_free_node(t_node **list)
{
	t_node	*ptr;
	t_node	*next;
	
	if (!(*list))
		return ;
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}		
	ptr = *list;
	ptr -> previous -> next = NULL; // ending the loop // loop has more than 2 nodes
	while (ptr != NULL)
	{
		next = ptr -> next;
		free(ptr);
		ptr = next;
	}
}

void	ft_print_output(t_node *list)
{
	int	i;
	t_node	*head;

	i = 0;
	if (!list)
		return ;
	head = list;
	printf("the address of ptr: %p\n", head);
	printf("the address of ptr -> next: %p\n", head->next);
	printf("the refer of function: %p\n", &list);
	while (1)
	{
		// if (list)
		// {
		// 	printf("%d\n", list -> value);
		// 	list = list -> next;
		printf("addr: %p,  %d\n", list, list->value);
		if (!list->next)
			break ;
		list = list->next;
		if (list == head)
			break;
	}
}
void	ft_rotate_up(t_node **list) //the first element become last one
{
	if (!(*list) || (*list)->next == NULL)
		return ;
	*list = (*list)->previous;
}

void	ft_rotate_down(t_node **list)
{
	if(!(*list) || (*list)->next == NULL)
		return ;
	*list = (*list)->next;
}

void	ft_swap(t_node **list)
{
	t_node	*a;
	t_node	*b;
/// need to thinking about the only one node // two nodes///
	if ((*list) -> next == NULL)
		return ;
	if ((*list) -> next == *list)
	{
		*list = (*list)->next; //looping condition already set at the previous function
		return ;
	}
	a = *list;
	b = (*list)->next;
	a->next = b->next;
	b->next = a;
	a->next->previous = a;
	b->previous = a->previous;
	a->previous = b;
	b->previous->next = b; // closing the circular loop
	*list = b;
	// b->previous = a;
	// a->previous = b;
	// a->next = b->next;
	// b->previous = a->previous;
	// b->previous->next = b;	
}

t_node	*ft_extract_node(t_node **list) //extract node - set to null/ 1 node / 2 node / 3 node --> change the pointer
{
	t_node	*extract;
	extract = *list;
	if (!(extract))
		return (NULL);
	if ((extract)->next == NULL) // one node
	{
		*list = NULL;
		return (extract);
	}
	/// two nodes ////
	if (extract->next->next == extract)//two nodes pointing at itself
	{
		extract->next->previous = NULL;
		extract->next->next = NULL;
		*list = extract->next;//change the head node
		return (extract);
	}
	// more than two nodes
	extract->next->previous = extract->previous;
	extract->previous->next = extract->next;
	*list = extract->next;
	return (extract);
}

void	ft_add_node(t_node **list, t_node *new)
{
	t_node	*head;
	// nothing in the list
	head = *list;
	if(head == NULL)
	{
		head = new;
		head->next = NULL;
		head->previous = NULL;
	}
	/// if one node in the list 
	else if (head->next == NULL)
	{
		new -> next = head;
		new -> previous = head;
		head -> previous = new;
		head -> next = new;
		*list = new;
	}
	else
	{
		new -> next = head;
		new -> previous = head -> previous;
		new -> previous -> next = new; // update the last node of the list
		head -> previous = new;
		*list = new;
	}
}

int	main(void)
{
	t_node	*list;
	t_node	*extract;
	int num[6] = {1,2,3,4,5,6};
	int i;
	
	list = NULL;
	i = 0;
	// add back to the node
	while (i < 6)
	{
		ft_add_list_back(&list, num[i]);
		i++;
		printf("hiiii\n");
	}
	printf("the refer of main %p\n", &list);
	// ft_swap(&list);
	ft_rotate_down(&list); //234561
	ft_rotate_up(&list); 
	ft_rotate_up(&list);//612345
	extract = ft_extract_node(&list);
	printf("the extracted node: %d\n", extract->value); //6
	ft_add_node(&list, extract);//612345
	ft_print_output(list); // the address of reference 
	ft_free_node(&list);
}

