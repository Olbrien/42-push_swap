#include "includes/push_swap.h"
void	set_ord(int *ar, size_t n, t_stack *stack)
{
	t_stack	*tmp;
	size_t	e;

	tmp = stack;
	while (stack != NULL)
	{
		e = 0;
		while (e < n)
		{
			if (ar[e] == (long long)stack->content)
				stack->ord = e;
			e++;
		}
		stack = stack->next;
	}
	stack = tmp;
}

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	sort_int_tab(int *tab, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (tab[j + 1] == tab[j])
				return (0);
			if (tab[j + 1] < tab[j])
			{
				ft_swap(&tab[j + 1], &tab[j]);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	order_att(t_stack *stack, size_t n)
{
	t_stack		*tmp;
	int			*ar;

	tmp = stack;
	ar = (int *)malloc(sizeof(int) * n + 1);
	n = 0;
	while (stack != NULL)
	{
		ar[n] = (long long)stack->content;
		n++;
		stack = stack->next;
	}
	if (!sort_int_tab(ar, n))
	{
		free(ar);
		return (0);
	}
	stack = tmp;
	set_ord(ar, n, stack);
	free(ar);
	return (1);
}
