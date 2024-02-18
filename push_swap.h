/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:13:37 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/18 17:58:14 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> //write
#include <stdlib.h>
//#include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next; //storing the address of the previous node
	struct s_stack	*previous; //storing the address of the last node
}	t_stack;

// stack && heap
#endif
