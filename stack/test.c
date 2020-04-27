#include "stack.h"

void	test_stack()
{
	s_stack	*stack_only_head = create_head(0);

	int mass[] = {4,5,6,7,8,3,3,2,5,6};
	int len_mass = 10;
	s_stack	*stack_from_mass = init_stack_with_mass(len_mass, mass);

	ft_printf("print first stack:\n");
	print_stack(stack_only_head);

	ft_printf("****\nend\nprint stack from mass\n");
	print_stack(stack_from_mass);
}