#include "push_swap.h"

int	check_descending(t_list *a, t_list *b)
{
	if (a == NULL || b != NULL)
		return (0);
	while (a->next != NULL)
	{
		if (a->n >= (a->next->n))
		{
			return (0);
		}
		a = a->next;
	}
	return (1);
}
