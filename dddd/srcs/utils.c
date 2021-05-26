#include "includes/push_swap.h"

int	check_sort(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		tmp = (long)stack->content;
		stack = stack->next;
		if (tmp >= (long)stack->content)
			return (0);
	}
	return (1);
}

int	check_double_elems(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	fill_stack_a(int no_elems, char **elems, t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 2;
	*stack = ft_lstnew_ps((void *)(long long)ft_atoi(elems[1]), 0);
	while (i < no_elems)
	{
		tmp = ft_lstnew_ps((void *)(long long)ft_atoi(elems[i]), 0);
		ft_lstadd_back_ps(stack, tmp);
		i++;
	}
	if (check_double_elems(*stack))
		return (-1);
	return (1);
}

int	check_input_only_digits(char *to_test)
{
	int	i;

	i = 0;
	if (ft_atoi(to_test) == -19999999)
		return (0);
	if (to_test[0] == '-')
	{	
		while (to_test[++i])
			if (!ft_isdigit(to_test[i]))
				return (0);
	}
	else if (ft_isdigit(to_test[0]))
	{	
		while (to_test[++i])
			if (!ft_isdigit(to_test[i]))
				return (0);
	}
	else
		return (0);
	return (1);
}

int	op1(t_stack **stack_b)
{
	print_op("rb");
	rotate_stack(stack_b);
	return (1);
}
