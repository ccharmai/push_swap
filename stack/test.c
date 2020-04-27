#include "stack.h"

void	test_stack()
{
	int mass[] = {4,5,6,7,8,3,3,2,5,6};
	int len_mass = 10;
	t_stack	*stack_from_mass = init_stack_with_mass(len_mass, mass);

	ft_printf("print stack from mass\n");
	print_stack(stack_from_mass);
	free_stack(stack_from_mass);
}