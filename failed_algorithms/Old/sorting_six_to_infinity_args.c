/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_six_to_infinity_args.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:03:59 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/28 23:16:42 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/*
void	fit_stack_b_for_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	ft_lstgoto_begin_mod(stack_b);
	while (*stack_b != NULL)
	{
		if ((*stack_a)->stack_order_nbr < (*stack_b)->stack_order_nbr)
			i++;
		if ((*stack_b)->next == NULL)
			break ;
		(*stack_b) = (*stack_b)->next;
	}
	while (i > 0)
	{
		debugger(*stack_a, *stack_b);
		call("reverse rotate b", stack_a, stack_b);
		ft_lstgoto_end_mod(stack_b);
		i--;
	}
	ft_lstgoto_end_mod(stack_a);
}

int	nearest_reverse_rotate_a(t_chunk chunk, t_stack **stack_a, int i, int rev_rot_a)
{
	int	was_found;
	int	loop;

	was_found = 0;
	loop = 0;

	ft_lstgoto_end_mod(stack_a);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->stack_order_nbr >= chunk.chunks_range[i][0]
			&& (*stack_a)->stack_order_nbr <= chunk.chunks_range[i][1])
		{
			rev_rot_a = loop;
			was_found = 1;
			break ;
		}
		if ((*stack_a)->previous == NULL)
			break ;
		(*stack_a) = (*stack_a)->previous;
		loop++;
	}

	if (was_found == 1)
		return (rev_rot_a);
	return (-999999);
}

int	nearest_rotate_a(t_chunk chunk, t_stack **stack_a, int i, int rot_a)
{
	int	was_found;
	int	loop;

	was_found = 0;
	loop = 0;

	ft_lstgoto_begin_mod(stack_a);
	while ((*stack_a) != NULL)
	{
		loop++;
		if ((*stack_a)->stack_order_nbr >= chunk.chunks_range[i][0]
			&& (*stack_a)->stack_order_nbr <= chunk.chunks_range[i][1])
		{
			rot_a = loop;
			was_found = 1;
			break ;
		}
		if ((*stack_a)->next == NULL)
			break ;
		(*stack_a) = (*stack_a)->next;
	}

	if (was_found == 1)
		return (rot_a);
	return (-999999);
}

int	location_nearest_number(t_chunk chunk, t_stack **stack_a, int i)
{
	int	rot_a;
	int	rev_rot_a;


	rot_a = nearest_rotate_a(chunk, stack_a, i, 0);
	rev_rot_a = nearest_reverse_rotate_a(chunk, stack_a, i, 0);

	ft_lstgoto_end_mod(stack_a);

	if (rot_a == -999999 || rev_rot_a == -999999)
		return (-999999);
	else if (rev_rot_a < rot_a)
		return (rev_rot_a);
	else if (rev_rot_a > rot_a)
	{
		if (rot_a != 0)
			rot_a *= -1;
		return (rot_a);
	}
	else
		return (rot_a);

}

void	set_chunks3(t_chunk *chunk)
{
	int	i;

	i = 0;
	while ((*chunk).chunks_size[i] > 0)
	{
		if (i == 0)
		{
			(*chunk).chunks_range[i][0] = 0;
			(*chunk).chunks_range[i][1] = (*chunk).chunks_size[i];
		}
		else
		{
			(*chunk).chunks_range[i][0] = (*chunk).chunks_size[i - 1];
			(*chunk).chunks_range[i][1] = (*chunk).chunks_size[i];
		}
		i++;
	}
	(*chunk).chunks_range[i][0] = -1;
	(*chunk).chunks_range[i][1] = -1;
}

void	set_chunks2(t_chunk *chunk, int args, int args_count, int i)
{
	while (1)
	{
		args_count += (*chunk).chunks_of;
		if (args_count > args)
		{
			if (args_count - args <= 0)
			{
				(*chunk).chunks_size[i] = -1;
				break ;
			}
			else
			{
				if ((args_count - args - (*chunk).chunks_of) * -1 != 0)
					(*chunk).chunks_size[i++] = (*chunk).chunks_of + (*chunk).chunks_size[i - 1] - 1;
				(*chunk).chunks_size[i] = -1;
				break ;
			}
		}
		else if (i == 0)
			(*chunk).chunks_size[i] = (*chunk).chunks_of;
		else
			(*chunk).chunks_size[i] = (*chunk).chunks_of + (*chunk).chunks_size[i - 1];
		i++;
	}
}

void	set_chunks(t_chunk *chunk, int args)
{
	(*chunk).nbr_args = args;
	if (args <= 10)
		(*chunk).chunks_of = (int)(args / 2) + 1;
	else if (args <= 50)
		(*chunk).chunks_of = (int)(args / 4) + 1;
	else if (args <= 100)
		(*chunk).chunks_of = (int)(args / 8) + 1;
	else if (args <= 250)
		(*chunk).chunks_of = (int)(args / 10) + 1;
	else
		(*chunk).chunks_of = (int)(args / 14) + 1;
	set_chunks2(chunk, args, 0, 0);
	set_chunks3(chunk);
}

void sorting_six_to_infinity_args(t_stack **stack_a, t_stack **stack_b,
									int args)
{
	t_chunk	chunk;
	int		i;
	int		nearest_number;

	i = 0;
	set_chunks(&chunk, args);

	while (is_stack_a_in_order(stack_a) == 0 || chunk.chunks_range[i][0] != -1)
	{
		nearest_number = location_nearest_number(chunk, stack_a, i);
		if (nearest_number == -999999)
		{
			i++;
			continue ;
		}
		else if (nearest_number < 0 && nearest_number != -999999)
		{
			nearest_number *= -1;
			while (nearest_number > 0)
			{
				if ((*stack_a)->stack_order_nbr > (*stack_a)->previous->stack_order_nbr
					&& nearest_number != 1)
					call("swap a", stack_a, stack_b);
				call("reverse rotate a", stack_a, stack_b);
				ft_lstgoto_end_mod(stack_a);
				nearest_number--;
			}
			if (*stack_b == NULL)
				call("push b", stack_a, stack_b);
			else if ((*stack_b)->next == NULL)
			{
				call("push b", stack_a, stack_b);
				ft_lstgoto_end_mod(stack_b);
				if ((*stack_b)->stack_order_nbr > (*stack_b)->previous->stack_order_nbr)
					call("swap b", stack_a, stack_b);
			}
			else
			{
				while (is_stack_a_in_order(stack_b) == 0)
				{
					call("rotate b", stack_a, stack_b);
					//debugger(*stack_a, *stack_b);
				}
				fit_stack_b_for_push_b(stack_a, stack_b);
				call("push b", stack_a, stack_b);
			}
			//debugger(*stack_a, *stack_b);
		}
		else if (nearest_number >= 0)
		{
			//debugger(*stack_a, *stack_b);
			while (nearest_number > 0)
			{
				if ((*stack_a)->stack_order_nbr > (*stack_a)->previous->stack_order_nbr
					&& nearest_number != 1)
					call("swap a", stack_a, stack_b);
				call("rotate a", stack_a, stack_b);
				ft_lstgoto_end_mod(stack_a);
				nearest_number--;
			}
			if (*stack_b == NULL)
				call("push b", stack_a, stack_b);
			else if ((*stack_b)->next == NULL)
			{
				call("push b", stack_a, stack_b);
				ft_lstgoto_end_mod(stack_b);
				if ((*stack_b)->stack_order_nbr > (*stack_b)->previous->stack_order_nbr)
					call("swap b", stack_a, stack_b);
			}
			else
			{
				while (is_stack_a_in_order(stack_b) == 0)
				{
					call("rotate b", stack_a, stack_b);
					//debugger(*stack_a, *stack_b);
				}
				fit_stack_b_for_push_b(stack_a, stack_b);
				call("push b", stack_a, stack_b);
			}
			//debugger(*stack_a, *stack_b);
			if (chunk.chunks_range[i][0] == -1)
				break ;
		}
	}

	while (is_stack_a_in_order(stack_b) == 0)
	{
		call("rotate b", stack_a, stack_b);
		//debugger(*stack_a, *stack_b);
	}

	while (*stack_b != NULL)
	{
		call("reverse rotate b", stack_a, stack_b);
		call("push a", stack_a, stack_b);
		//debugger(*stack_a, *stack_b);
	}
*/
//debugger(*stack_a, *stack_b);
/*	printf("-->%i\n", chunk.nbr_args);
	printf("Nearest Number-->%i\n", nearest_number);

	for(i = 0; chunk.chunks_size[i] > 0; i++)
		printf("chunk size[%i]= %i\n",i, chunk.chunks_size[i]);
	printf("chunk size[%i]= %i\n",i, chunk.chunks_size[i]);

	printf("\n");

	for(i = 0; chunk.chunks_size[i] > 0; i++)
		printf("chunk range[%i]= %i %i\n",i, chunk.chunks_range[i][0], chunk.chunks_range[i][1]);
	printf("chunk range[%i]= %i %i\n",i, chunk.chunks_range[i][0], chunk.chunks_range[i][1]);

*/

/*
}
*/
