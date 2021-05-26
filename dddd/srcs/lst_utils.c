#include "includes/push_swap.h"
long long	lst_max(t_list *stack)
{
	long long	max;

	if (!stack)
		return (2147483647);
	max = (long long)stack->content;
	while (stack)
	{
		if (max < (long long)stack->content)
			max = (long long)stack->content;
		stack = stack->next;
	}
	return (max);
}

long long	lst_min(t_list *stack)
{
	long long	min;

	if (!stack)
		return (-2147483648);
	min = (long long)stack->content;
	while (stack)
	{
		if ((long long)stack->content < min)
			min = (long long)stack->content;
		stack = stack->next;
	}
	return (min);
}

void	ft_lstclear_ps(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
