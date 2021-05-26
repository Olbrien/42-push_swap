#include "includes/push_swap.h"

int	op2(t_stack **stack_b)
{
	print_op("rrb");
	rev_rotate_stack(stack_b);
	return (1);
}

int	op3(t_stack **stack_a)
{
	print_op("rra");
	rev_rotate_stack(stack_a);
	return (1);
}

int	op4(t_stack **stack_a)
{	
	print_op("ra");
	rotate_stack(stack_a);
	return (1);
}
