/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_six_to_infinity_args.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 05:26:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 17:11:54 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_lstnew_ps(void *content, int ord)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	if (new)
	{
		//new->stack_nbr = (int *)content;
		new->stack_order_nbr = ord;
		new->next = NULL;
	}
	return (new);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack		*begin;

	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	if (lst && (*lst) && new)
	{
		begin = (*lst);
		if (begin == NULL)
			(*lst) = new;
		else
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
		}
	}
}

int	ft_lstsize_ps(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	else
		return (NULL);
	return (lst);
}


void	swap_stack(t_stack **stack)
{
	t_stack	*elem1;
	t_stack	*elem2;

	elem1 = *stack;
	if (!elem1 || !elem1->next)
		return ;
	elem2 = elem1->next;
	*stack = elem2;
	elem1->next = elem2->next;
	elem2->next = elem1;
}

void	push_stack(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	if (!tmp)
		return ;
	*src = tmp->next;
	tmp->next = 0;
	ft_lstadd_front_ps(dest, tmp);
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*first_node;

	first_node = *stack;
	if (!first_node || !first_node->next)
		return ;
	*stack = first_node->next;
	first_node->next = 0;
	ft_lstadd_back_ps(stack, first_node);
}

void	rev_rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_node;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = 0;
	ft_lstadd_front_ps(stack, last_node);
}


int	find_spec_next(t_stack *che, int len, int num)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = che;
	while (tmp != NULL)
	{
		if (tmp->stack_order_nbr == num)
		{
			if (count > (len / 2))
				return (0);
			else
				return (1);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int	find_hi(t_stack *stac)
{
	t_stack	*tmp;
	int		ret;

	ret = 0;
	tmp = stac;
	while (stac)
	{
		if (stac->stack_order_nbr > ret)
		{
			ret = stac->stack_order_nbr;
		}
		stac = stac->next;
	}
	stac = tmp;
	return (ret);
}

int	put_back_a(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	n = find_hi(*stack_b);
	while (ft_lstsize_mod(*stack_b) > 0)
	{
		if ((*stack_b)->stack_order_nbr == n)
		{
			//call("push a", stack_a, stack_b);
			push_stack(stack_a, stack_b);
			write(1, "pa\n", 3);
			n--;
		}
		else if (find_spec_next(*stack_b, ft_lstsize_mod(*stack_b), n) == 0)
		{
			while ((*stack_b)->stack_order_nbr != n)
			{
				//call("reverse rotate b", stack_a, stack_b);
				rev_rotate_stack(stack_b);
				write(1, "rrb\n", 4);
			}
		}
		else
		{
			while ((*stack_b)->stack_order_nbr != n)
			{
				//call("rotate b", stack_a, stack_b);
				rotate_stack(stack_b);
				write(1, "rb\n", 3);
			}
		}
	}
	return (1);
}

int	find_next(t_stack *che, int len, int range)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = che;
	while (tmp)
	{
		if (tmp->stack_order_nbr >= (len - range))
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int	get_chunk(t_stack **stack_a, t_stack **stack_b, int llen, int partition)
{
	int	slen;

	slen = ft_lstsize_mod(*stack_b);
	while ((ft_lstsize_mod(*stack_b) - slen) <= (llen / partition))
	{
		if ((*stack_a)->stack_order_nbr >= (llen - (llen / partition)))
		{
			//call("push b", stack_a, stack_b);
			push_stack(stack_b, stack_a);
			write(1, "pb\n", 3);
		}
		else
		{
			if (find_next(*stack_a, llen, (llen / partition)) == 1)
			{
				while (!((*stack_a)->stack_order_nbr >= (llen - (llen / partition))))
				{
					//call("rotate a", stack_a, stack_b);
					rotate_stack(stack_a);
					write(1, "ra\n", 3);
				}
			}
			else
			{
				while (!((*stack_a)->stack_order_nbr >= (llen - (llen / partition))))
				{
					//call("reverse rotate a", stack_a, stack_b);
					rev_rotate_stack(stack_a);
					write(1, "rra\n", 4);
				}
			}
		}
	}
	return (1);
}

void	change_order_stack(t_stack **stack_a)
{
	int	llen;
	t_stack *temp;
	t_stack	*stack_add;

	ft_lstgoto_end_mod(stack_a);
	temp = ft_lstnew_mod((*stack_a)->stack_nbr, (*stack_a)->stack_order_nbr);
	*stack_a = (*stack_a)->previous;
	while (*stack_a != NULL)
	{
		stack_add = ft_lstnew_mod((*stack_a)->stack_nbr, (*stack_a)->stack_order_nbr);
		ft_lstadd_back_mod(&temp, stack_add);
		if ((*stack_a)->previous == NULL)
			break ;
		*stack_a = (*stack_a)->previous;
	}

	*stack_a = temp;
}

int	check_sort(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		tmp = (long)stack->stack_nbr;
		stack = stack->next;
		if (tmp >= (long)stack->stack_nbr)
			return (0);
	}
	return (1);
}

void	three_elems_sort(t_stack **stack_a)
{
	while (!check_sort(*stack_a))
	{
		if ((*stack_a)->stack_order_nbr == 2)
		{
			rotate_stack(stack_a);
			write(1, "ra\n", 3);
		}
		else if ((*stack_a)->next->stack_order_nbr > (*stack_a)->stack_order_nbr)
		{
			rev_rotate_stack(stack_a);
			write(1, "rra\n", 4);
		}
		else if ((*stack_a)->stack_order_nbr > (*stack_a)->next->stack_order_nbr)
		{
			swap_stack(stack_a);
			write(1, "sa\n", 3);
		}
	}
}

void	sorting_six_to_infinity_args(t_stack **stack_a, t_stack **stack_b)
{
	int	partition;
	int	llen;

	change_order_stack(stack_a);

	llen = ft_lstsize_mod(*stack_a);
	if (is_stack_a_in_order(*stack_a) == 1)
		return ;
	if (llen > 101)
		partition = 11;
	else
		partition = 5;
	while (ft_lstsize_mod(*stack_a) >= 5)
	{
		get_chunk(stack_a, stack_b, llen - 1, partition);
		llen = ft_lstsize_mod(*stack_a);
	}
	while ((*stack_a)->stack_order_nbr != 3)
	{
		//call("rotate a", stack_a, stack_b);
		rotate_stack(stack_a);
		write(1, "ra\n", 3);
	}

	//call("push b", stack_a, stack_b);
	push_stack(stack_b, stack_a);
	write(1, "pb\n", 3);

	three_elems_sort(stack_a);

	put_back_a(stack_a, stack_b);
	while (is_stack_a_in_order(*stack_a) == 0)
	{
		//call("reverse rotate a", stack_a, stack_b);
		rev_rotate_stack(stack_a);
		write(1, "rra\n", 4);
	}
}
