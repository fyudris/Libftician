/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:37:32 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:45:51 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void	test_lstsize(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	t_list	*next;

	printf("\n=== Testing ft_lstsize ===\n\n");
	// Test 1: Empty list
	head = NULL;
	test_result("Empty list", ft_lstsize(head) == 0, 1);
	// Test 2: List with one node
	head = ft_lstnew("first");
	test_result("List with one node", ft_lstsize(head) == 1, 1);
	// Test 3: List with multiple nodes
	second = ft_lstnew("second");
	ft_lstadd_front(&head, second);
	third = ft_lstnew("third");
	ft_lstadd_front(&head, third);
	test_result("List with multiple nodes", ft_lstsize(head) == 3, 1);
	// Free the list
	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	printf("\n=== End of ft_lstsize tests ===\n\n");
}

#ifdef MAIN
int	main(void)
{
	test_lstsize();
	return (0);
}
#endif
