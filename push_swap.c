/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:19:29 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/26 02:34:09 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	debugger(t_stack *stack_a, t_stack *stack_b)
{
	int size_a;
	int size_b;

	ft_lstgoto_begin_mod(&stack_a);
	ft_lstgoto_begin_mod(&stack_b);
	size_a = ft_lstsize_mod(stack_a) - 1;
	size_b = ft_lstsize_mod(stack_b) - 1;
	ft_lstgoto_end_mod(&stack_a);
	ft_lstgoto_end_mod(&stack_b);

	printf("--------------------------------------------------------\n");
	printf("stack a:			stack b:\n");
	printf("				\n");

	if (size_a > size_b)
	{
		while (size_a >= 0)
		{
			if (size_a > size_b)
				printf("lst%i:	%i	order:	%i\n",size_a, stack_a->stack_nbr, stack_a->stack_order_nbr);
			else
			{
				printf("lst%i:	%i	order:	%i",size_a, stack_a->stack_nbr, stack_a->stack_order_nbr);
				printf("	lst%i:	%i	order:	%i\n",size_b, stack_b->stack_nbr, stack_b->stack_order_nbr);
				if (stack_b->previous == NULL)
					break ;
				stack_b = stack_b->previous;
				size_b--;
			}
			if (stack_a->previous == NULL)
				break ;
			stack_a = stack_a->previous;
			size_a--;
		}
	}
	else if (size_a == size_b)
	{
		while (size_a >= 0)
		{
			printf("lst%i:	%i	order:	%i",size_a, stack_a->stack_nbr, stack_a->stack_order_nbr);
			printf("	lst%i:	%i	order:	%i\n",size_b, stack_b->stack_nbr, stack_b->stack_order_nbr);
			if (stack_b->previous == NULL)
				break ;
			stack_b = stack_b->previous;
			size_b--;
			if (stack_a->previous == NULL)
				break ;
			stack_a = stack_a->previous;
			size_a--;
		}
	}
	else if (size_b > size_a)
	{
		while (size_b >= 0)
		{
			if (size_b > size_a)
				printf("				lst%i:	%i	order:	%i\n",size_b, stack_b->stack_nbr, stack_b->stack_order_nbr);
			else
			{
				printf("lst%i:	%i	order:	%i",size_a, stack_a->stack_nbr, stack_a->stack_order_nbr);
				printf("	lst%i:	%i	order:	%i\n",size_b, stack_b->stack_nbr, stack_b->stack_order_nbr);
				if (stack_a->previous == NULL)
					break ;
				stack_a = stack_a->previous;
				size_a--;
			}
			if (stack_b->previous == NULL)
				break ;
			stack_b = stack_b->previous;
			size_b--;
		}
	}
	printf("				\n");
}



int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (error_handling(argc, argv) == 0)
		return (exit_error("Error\n"));

	initialize_stacks(&stack_a, &stack_b, argv, argc);

	//debugger(stack_a, stack_b);

	if (argc == 3)
		sorting_two_args(&stack_a, &stack_b);
	else if (argc == 4)
		sorting_three_args(&stack_a, &stack_b);
	else if (argc == 5 || argc == 6)
		sorting_four_to_five_args(&stack_a, &stack_b);


	//debugger(stack_a, stack_b);

	ft_lstclear_mod(&stack_a);
	ft_lstclear_mod(&stack_b);



	//printf("--------------------------------------------------------\n");

}
