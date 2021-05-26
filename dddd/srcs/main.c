#include "includes/push_swap.h"

int	free_lists(t_stack	**stack_a, t_stack	**stack_b)
{
	ft_lstclear_ps(stack_a);
	ft_lstclear_ps(stack_b);
	return (1);
}

int	sort_stacks(t_stack	**stack_a, t_stack	**stack_b)
{
	if (check_sort(*stack_a))
	{
		free_lists(stack_b, stack_a);
		return (0);
	}
	order_att(*stack_a, ft_lstsize_ps(*stack_a));
	if (ft_lstsize_ps(*stack_a) <= 3)
	{
		three_elems_sort(stack_a);
		ft_lstclear_ps(stack_a);
		return (0);
	}
	sort(stack_a, stack_b, ft_lstsize_ps(*stack_a));
	free_lists(stack_b, stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	stack_a = NULL;
	i = 0;
	if (argc <= 1)
		return (-1);
	while (argv[++i])
	{
		if (!check_input_only_digits(argv[i]))
			return (write(1, "Error\n", 6));
	}
	if (fill_stack_a(argc, argv, &stack_a) == -1)
	{
		free_lists(&stack_b, &stack_a);
		return (write(1, "Error\n", 6));
	}
	sort_stacks(&stack_a, &stack_b);
	return (0);
}
