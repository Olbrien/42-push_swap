#include "includes/push_swap.h"

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
