/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:33:47 by marvin            #+#    #+#             */
/*   Updated: 2021/05/25 06:52:42 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** Free
*/

void				free_array(char **array);

/*
** Is
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isstringalpha(char *string);
int					ft_isstringdigit(char *string);

/*
** Lst
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

typedef struct s_list2
{
	void			*content;
	struct s_list2	*next;
	struct s_list2	*previous;
}				t_list2;

t_list2				*ft_lstnew2(void *content);
void				ft_lstadd_back2(t_list2 **lst, t_list2 *new);
void				ft_lstclear2(t_list2 **lst);
t_list2				*ft_lstgoto_end2(t_list2 **lst);
t_list2				*ft_lstgoto_begin2(t_list2 **lst);
void				ft_lstadd_front2(t_list2 **lst, t_list2 *new);
int					ft_lstsize2(t_list2 *lst);
void				ft_lstremove_last2(t_list2 **lst);
void				ft_lstremove_first2(t_list2 **lst);

void				ft_swap2(t_list2 **stack_a);
void				ft_push2(t_list2 **stack_a, t_list2 **stack_b);
void				ft_rotate2(t_list2 **stack_a);
void				ft_reverse_rotate2(t_list2 **stack_a);



/*
** Math
*/

long long			ft_pow(int number, unsigned int power);

/*
** Mem
*/

void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *str1, const void *str2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nitems, size_t size);

/*
** Put
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** String
*/

char				**ft_split(char const *s, char c);
char				**ft_split2(char const *s, const char *delimiters);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinchr(char *s1, char s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, char *src);

/*
** To
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_unsigned_longlong(unsigned long long int n);
char				*ft_itoa_longlong(long long n);

#endif
