#include "stack.h"

void	free_stack(t_stack *stack)
{
	t_stack	*prev;
	t_stack	*p;

	prev = NULL;
	while (stack->next)
	{
		prev = stack;
		stack = stack->next;
		free(prev);
	}
	free(stack);
}
