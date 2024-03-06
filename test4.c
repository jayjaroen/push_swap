/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:08:45 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/06 23:58:06 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "srcs/push_swap.h"

void	ft_free_node(t_node **list);
void	ft_bzero(void *s, size_t n);

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

// add min add max
void	ft_add_list_back(t_stack *stack, int i)
{
	t_node	*new;
	t_node 	*head;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		ft_free_node(&stack->head); //double pointer >reference of address of head is a double pointer
		return ;
	}

	//need to free after --> error hand - check stack a & b
	head = stack->head;
	new -> value = i;
	/// first node ////
	if (head == NULL)
	{
		new -> previous = NULL;
		new -> next = NULL;
		stack->head = new;
		stack->min = new;
		stack->max = new;
	}
	else if (head->next == NULL)
	{
		new -> next = head;
		new -> previous = head;
		head -> previous = new;
		head -> next = new;
		if (new->value > stack->max->value)
			stack->max = new;
		if (new->value < stack->min->value)
			stack->min = new;
	}
	else
	{
		new -> next = head;
		new -> previous = head -> previous;
		new -> previous -> next = new; // update the last node of the list
		head -> previous = new;
		if (new->value > stack->max->value)
			stack->max = new;
		if (new->value < stack->min->value)
			stack->min = new;
	}
	stack->n += 1; //size of stack every time adding the new node
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
	// int	i;
	t_node	*head;

	// i = 0;
	if (!list)
		return ;
	head = list;
	// printf("the address of ptr: %p\n", head);
	// printf("the address of ptr -> next: %p\n", head->next);
	// printf("the refer of function: %p\n", &list);
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
	// extract->next->previous = extract->previous;
	extract->next->previous = extract->next; /// updating the list
	extract->previous->next = extract->next;
	*list = extract->next;
	return (extract);
}
// ------------- add node after extract ----------------------------
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
		*list = new;
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
// list size // count size
// small soring algo
// sorting function( 2 function: sorting from the head (top && check min))
// bool	ft_check_duplicate_num(t_node **list)
// {

// }

int	ft_count_node(t_node **list)
{
	t_node *ptr;
	int		count;

	count = 0;
	ptr = *list;
	while (1)
	{
		ptr = ptr->next;
		++count;
		if (ptr == *list)
			break ;
	}
	printf("the number of nodes is: %d\n", count);
	return (count);
}

int	ft_is_sort(t_node *head)
{
	t_node	*ptr;

	ptr = head;
	if (ptr->next == NULL)
		return (0);
	while (ptr->next != head)
	{
		if (ptr->value >= ptr->next->value)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

/// The function handle only three elements in stack
void	ft_sort_small(t_stack *stack)
{
    /// the highest number at the first position
	if (stack->head == stack->max)
    {
		ft_rotate_down(&stack->head);
		printf("%d\n", stack->head->value);
		if (stack->head->next == stack->min)
			ft_swap(&stack->head);
		// 3 1 2
		// 3 2 1
    }
	// the lowest number at the first position
	else if (stack->head == stack->min)
	{
		if (stack->head->next < stack->head->previous)
		{
			ft_rotate_up(&stack->head);
			ft_swap(&stack->head);
		}
	}
	// the second highest number is at the first position
	else
	{
		if (stack->head->next == stack->max)
			ft_rotate_up(&stack->head);
		else if (stack->head->next == stack->min)
			ft_swap(&stack->head);
	}
}
/////////////////// update info function ////////////////
void	ft_update_info(t_stack *stack, t_node *extract)
{
///// to update info number of node, min & max
}
////////////////// function push a to b///////////////////
void    ft_push(t_stack *stack_out, t_stack *stack_in)
{
	//// also need to update min max after push, change the stack////
	t_node	*extract;

	extract = ft_extract_node(&stack_out->head);
	// ft_update_info(stack_a, extract);
	ft_add_node(&stack_in->head, extract);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int i;
	int	size_arg;

	ft_bzero(&stack_a, sizeof(t_stack));
	ft_bzero(&stack_b, sizeof(t_stack));
	i = 1;
	while (i < argc)
	{
		ft_add_list_back(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	// check duplicate number
	// if duplicate, exit out
	// count size
	// small sort -> algo (within the stack)
	// ft_check_duplicate_num(&list);
	// size_arg = ft_count_node(&list);
	ft_print_output(stack_a.head); // the address of reference
	printf("the total number of nodes: %zu\n", stack_a.n); //pointer using "->"
	printf("the maximum value of nodes: %d\n", stack_a.max->value);
	printf("the minimum value of nodes: %d\n", stack_a.min->value);
	/// check sort take head && min
	printf("%d\n", ft_is_sort(stack_a.head));
	if (ft_is_sort(stack_a.head) == 0)
		return (0);
	if (stack_a.n == 3)
	{
		ft_sort_small(&stack_a);
	}
	ft_print_output(stack_a.head);
	ft_push(&stack_a, &stack_b);
	printf("------ stack a after push pa -------\n");
	ft_print_output(stack_a.head);
	printf("--------stack b after push pa--------\n");
	ft_print_output(stack_b.head);
}
	///////// The algorithm to rotate the stack && extract the node///////
	// printf("the refer of main %p\n", &list);
	// ft_swap(&list);
	// ft_rotate_down(&list); //234561
	// ft_rotate_up(&list);
	// ft_rotate_up(&list);//612345
	// extract = ft_extract_node(&list);
	// printf("the extracted node: %d\n", extract->value); //6
	// ft_add_node(&list, extract);//612345
	// ft_print_output(list); // the address of reference
	// ft_free_node(&list);
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		*ptr = 0;
		ptr++;
		i++;
	}
}
