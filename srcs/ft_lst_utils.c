/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:13 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/24 18:14:22 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*The fle contains the function that works work with circular double linked list
*/
//extract node - set to null/ 1 node / 2 node / 3 node --> change the pointer
#include <stdio.h> /// TO BE DELETED !!!
t_node	*ft_extract_node(t_node **list)
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
//what is the difference between this function and above?
void	ft_add_list_back_node(t_node **list, int i)
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
	t_node	*head;

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