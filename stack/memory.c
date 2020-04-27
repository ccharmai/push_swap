#include "stack.h"

void	free_stack(s_stack *stack)
{
	s_stack	*prev;
	s_stack	*p;

	prev = NULL;
	while (stack->next)
	{
		prev = stack;
		stack = stack->next;
		free(prev);
	}
	free(stack);
}
