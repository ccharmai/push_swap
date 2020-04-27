#include "stack.h"

s_stack	*create_head(int element)
{
	s_stack	*head;

	head = (s_stack*)malloc(sizeof(s_stack));
	if (!head)
		raise_memory_error();
	head->element = element;
	return (head);
}

void	append_element(int element, s_stack *stack)
{
	s_stack	*p;
	s_stack	*tmp;

	p = stack;
	while (p->next)
		p = p->next;
	tmp = (s_stack*)malloc(sizeof(s_stack));
	if (!tmp)
		raise_memory_error();
	tmp->element = element;
	tmp->next = NULL;
	p->next = tmp;
}

s_stack	*init_stack_with_mass(int len, int *mass)
{
	s_stack	*head;
	int		i;

	i = 0;
	head = create_head(0);
	while (i < len)
	{
		append_element(mass[i], head);
		i++;
	}
	return (head->next);
}

void	print_stack(s_stack *stack)
{
	while (stack)
	{
		ft_printf("%i ", stack->element);
		stack = stack->next;
	}
	ft_printf("\n");
}
