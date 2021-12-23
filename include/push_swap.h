#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_elem	t_elem;

struct s_elem
{
	int		value;
	int		index;
	int		id;
	t_elem	*next;
	t_elem	*prev;
};

typedef struct s_stack
{
	int		nb_elem;
	t_elem	*begin;
	t_elem	*end;
}	*t_stack;

typedef struct s_var
{
	int	nb;
	int	i;
	int	j;
	int	k;
	int	check;
}	t_var;

int		len_ac(int ac);
int		*sort_tab(int *tab, int len);
int		len_tab(t_stack s);
int		check_doublon(int *tab, int len);
int		biggest_groupid(t_stack s);
int		nbr_groupid(t_stack s);
int		put_in_tab(t_stack s);
int		one_groupid(t_stack s);
int		put_in_tab_b(t_stack s);
int		reindex_b(int *tab, t_stack s);
int		reindex(int *tab, t_stack s);
int		which_stack(t_stack a, t_stack b);
int		already_sort_b(t_stack s, int nb);
int		count_push(t_stack s, int mid);
int		len_argv(int ac, char **av);
int		already_sort(t_stack s);
int		ft_strlen(char *str);
int		is_digit(char *str);
int		ft_atoi(char *str, int *check);
int		is_smaller(int index, int mid);
int		rotate_in_decoupe(t_stack s, int stack, int nbr_rotate, t_elem **tmp);
int		count_push(t_stack s, int mid);
int		main_func(t_stack a, t_stack b, int stack);
char	**ft_split(char const *str, char c);

void	suite_sort_b(t_stack a, t_stack b, int mid, int end);
void	final_sort(t_stack s, t_stack b);
void	suite_final_sort2(t_stack s, t_stack b);
void	suite_final_sort1(t_stack s, t_stack b);
void	sort_a(t_stack a, t_stack b);
void	init_struct(t_elem **elem);
void	insert_index(int *tab, t_stack a, int ac);
void	print_list(t_stack a);
void	reset_id(t_stack s);
void	sort(t_stack a, t_stack b);
void	double_swap(t_stack a, t_stack b);
void	init_var(t_var *v);
void	ft_rotate(t_stack s, int nbr_rotate, int stack);
void	push_in_decoupe(t_stack s, t_stack d, int stack, t_elem **tmp);
void	sort_b(t_stack a, t_stack b);

t_stack	trie_a(t_stack a, t_stack b, int mid);
t_stack	trie_b(t_stack a, t_stack b, int mid);
t_stack	tab_index(int ac, char **av, t_stack a);
t_stack	suite_tab_index(int ac, char **av, t_stack a, int **tab_index);
t_stack	decoupe(t_stack s, t_stack d, int mid, int stack);
t_stack	decoupe_first(t_stack s, t_stack d, int mid);
t_stack	decoupe_b(t_stack s, t_stack d, int mid, int stack);
t_stack	func_swap(t_stack s);
t_stack	swap(t_stack s, int stack);
t_stack	r_rotate(t_stack s, int stack);
t_stack	rotate(t_stack s, int stack);
t_stack	push(t_stack s, t_stack d, int push);
t_stack	suite_push(t_stack *s, t_stack *d, t_elem **tmp, t_elem **tmp_next);
t_stack	add_new_elem(int val, t_stack a);
#endif
