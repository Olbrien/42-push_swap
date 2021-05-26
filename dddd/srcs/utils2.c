#include "includes/push_swap.h"

int	find_hi(t_stack *stac)
{
	t_stack	*tmp;
	int		ret;

	ret = 0;
	tmp = stac;
	while (stac)
	{
		if (stac->ord > ret)
		{
			ret = stac->ord;
		}
		stac = stac->next;
	}
	stac = tmp;
	return (ret);
}

int	find_spec_next(t_stack *che, int len, int num)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = che;
	while (tmp != NULL)
	{
		if (tmp->ord == num)
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

int	get_chunk(t_stack **stack_a, t_stack **stack_b, int llen)
{
	int	slen;

	slen = ft_lstsize_ps(*stack_b);
	while ((ft_lstsize_ps(*stack_b) - slen) <= (llen / 5))
	{
		if ((*stack_a)->ord >= (llen - (llen / 5)))
		{
			print_op("pb");
			push_stack(stack_b, stack_a);
		}
		else
		{
			if (find_next(*stack_a, llen, (llen / 5)) == 1)
			{
				while (!((*stack_a)->ord >= (llen - (llen / 5))))
					op4(stack_a);
			}
			else
			{
				while (!((*stack_a)->ord >= (llen - (llen / 5))))
					op3(stack_a);
			}
		}
	}
	return (1);
}

void	print_op(char *op)
{
	int	i;

	i = 0;
	while (op[i])
	{
		write(1, &op[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
