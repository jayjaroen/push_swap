/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:13 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/18 13:15:39 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_extract_node(t_node **list)
{
	t_node	*extract;

	extract = *list;
	if (!(extract))
		return (NULL);
	if ((extract)->next == NULL)
	{
		*list = NULL;
		return (extract);
	}
	if (extract->next->next == extract)
	{
		extract->next->previous = NULL;
		extract->next->next = NULL;
		*list = extract->next;
		return (extract);
	}
	extract->next->previous = extract->previous;
	extract->previous->next = extract->next;
	*list = extract->next;
	return (extract);
}

void	ft_add_node(t_node **list, t_node *new)
{
	t_node	*head;

	head = *list;
	if (head == NULL)
	{
		head = new;
		head->next = NULL;
		head->previous = NULL;
	}
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
		new -> previous -> next = new;
		head -> previous = new;
		*list = new;
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
	ptr -> previous -> next = NULL;
	while (ptr != NULL)
	{
		next = ptr -> next;
		free(ptr);
		ptr = next;
	}
}

int	ft_count_node(t_node *list)
{
	t_node	*ptr;
	int		count;

	count = 0;
	ptr = list;
	while (1)
	{
		ptr = ptr->next;
		++count;
		if (ptr == list)
			break ;
	}
	return (count);
}

/////////////Parking Lot///////////////////////////
// void	ft_add_list_back_node(t_node **list, int i)
// {
// 	t_node	*new;
// 	t_node 	*head;

// 	new = malloc(sizeof(t_node));
// 	if (!new)
// 	{
// 		ft_free_node(list);
// 		return ;
// 	}
// 	head = *list;
// 	new -> value = i;
// 	if (head == NULL)
// 	{
// 		new -> previous = NULL;
// 		new -> next = NULL;
// 		*list = new;
// 	}
// 	else if (head->next == NULL)
// 	{
// 		new -> next = head;
// 		new -> previous = head;
// 		head -> previous = new;
// 		head -> next = new;
// 	}
// 	else
// 	{
// 		new -> next = head;
// 		new -> previous = head -> previous;
// 		new -> previous -> next = new;
// 		head -> previous = new;
// 	}
// }