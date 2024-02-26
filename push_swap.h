/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:13:37 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/26 16:13:00 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> //write
#include <stdlib.h>
//#include "libft/libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*previous;
} t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*max;
	t_node	*min;
	size_t	n;
} t_stack;

// submodule to the library? / Make file

/*Handling the list of the agruments -> create a node of arguments and add
to the list*/

// operations to be change later
void	ft_add_node(t_node **list, t_node *new);
void	ft_swap(t_node **list);
void	ft_rotate_down(t_node **list);
void	ft_rotate_up(t_node **list);
void	ft_print_output(t_node *list);
void	ft_free_node(t_node **list);
void	ft_add_list_back(t_node **list, int i);
t_node	*ft_extract_node(t_node **list);

#endif
