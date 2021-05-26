#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

typedef struct s_stack
{
	void			*content;
	int				ord;
	struct s_stack	*next;
}				t_stack;

void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew_ps(void *content, int ord);
int			ft_lstsize_ps(t_stack *lst);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast_ps(t_stack *lst);
int			find_next(t_stack *che, int len, int range);
int			find_hi(t_stack *stac);
void		print_op(char *op);

int			order_att(t_stack *stack, size_t n);
void		sort(t_stack **stack_a, t_stack **stack_b, int llen);
int			find_spec_next(t_stack *che, int len, int num);
int			get_chunk(t_stack **stack_a, t_stack **stack_b, int llen);

int			check_input_only_digits(char *to_test);
int			fill_stack_a(int no_elems, char **elems, t_stack **stack);
int			check_sort(t_stack *stack);
void		sort_nums(t_stack **stack_a, t_stack **stack_b);
void		push_stack(t_stack **dest, t_stack **src);
void		rotate_stack(t_stack **stack);
void		rev_rotate_stack(t_stack **stack);
void		three_elems_sort(t_stack **stack_a);
void		swap_stack(t_stack **stack);
void		ft_lstclear_ps(t_stack **lst);
int			op1(t_stack **stack_a);
int			op2(t_stack **stack_b);
int			op3(t_stack **stack_a);
int			op4(t_stack **stack_a);
#endif