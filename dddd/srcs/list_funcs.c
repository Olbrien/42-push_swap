#include "includes/push_swap.h"

t_stack	*ft_lstnew_ps(void *content, int ord)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->ord = ord;
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
