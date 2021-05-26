#include "includes/push_swap.h"

void	three_elems_sort(t_stack **stack_a)
{
	while (!check_sort(*stack_a))
	{
		if ((*stack_a)->ord == 2)
		{
			print_op("ra");
			rotate_stack(stack_a);
		}
		else if ((*stack_a)->next->ord > (*stack_a)->ord)
		{
			print_op("rra");
			rev_rotate_stack(stack_a);
		}
		else if ((*stack_a)->ord > (*stack_a)->next->ord)
		{
			print_op("sa");
			swap_stack(stack_a);
		}
	}
}

int	find_next(t_stack *che, int len, int range)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = che;
	while (tmp)
	{
		if (tmp->ord >= (len - range))
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int	put_back_a(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	n = find_hi(*stack_b);
	while (ft_lstsize_ps(*stack_b) > 0)
	{
		if ((*stack_b)->ord == n)
		{
			print_op("pa");
			push_stack(stack_a, stack_b);
			n--;
		}
		else if (find_spec_next(*stack_b, ft_lstsize_ps(*stack_b), n) == 0)
		{
			while ((*stack_b)->ord != n)
				op2(stack_b);
		}
		else
		{
			while ((*stack_b)->ord != n)
				op1(stack_b);
		}
	}
	return (1);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{	
	while (ft_lstsize_ps(*stack_a) > 3)
	{
		if (find_next(*stack_a, ft_lstsize_ps(*stack_a), 1) == 0)
		{
			while ((*stack_a)->ord > 1)
			{
				print_op("ra");
				rotate_stack(stack_a);
			}
			print_op("pb");
			push_stack(stack_b, stack_a);
		}
		else
		{
			while ((*stack_a)->ord > 1)
			{
				print_op("rra");
				rev_rotate_stack(stack_a);
			}
			print_op("pb");
			push_stack(stack_b, stack_a);
		}
	}
	three_elems_sort(stack_a);
	put_back_a(stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b, int llen)
{
	if (ft_lstsize_ps(*stack_a) == 5)
	{
		sort_5(stack_a, stack_b);
		return ;
	}
	while (ft_lstsize_ps(*stack_a) >= 5)
	{
		get_chunk(stack_a, stack_b, llen - 1);
		llen = ft_lstsize_ps(*stack_a);
	}
	while (((*stack_a)->ord) != 3)
	{
		print_op("ra");
		rotate_stack(stack_a);
	}
	print_op("pb");
	push_stack(stack_b, stack_a);
	three_elems_sort(stack_a);
	put_back_a(stack_a, stack_b);
	while (!check_sort(*stack_a))
	{
		print_op("rra");
		rev_rotate_stack(stack_a);
	}
}
