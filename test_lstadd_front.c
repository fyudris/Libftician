/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:33:35 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:34:33 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

// Helper function to print the list
void print_list(t_list *head)
{
    while (head)
    {
        printf("%s -> ", (char *)head->content);
        head = head->next;
    }
    printf("NULL\n");
}

void test_lstadd_front()
{
    printf("\n=== Testing ft_lstadd_front ===\n\n");

    // Test 1: Add a new element to an empty list
    t_list *head = NULL;
    t_list *new_node = ft_lstnew("first");
    ft_lstadd_front(&head, new_node);
    test_result("Add to empty list", head == new_node && head->next == NULL, 1);

    // Test 2: Add a new element to a non-empty list
    t_list *second_node = ft_lstnew("second");
    ft_lstadd_front(&head, second_node);
    test_result("Add to non-empty list",
                head == second_node && head->next == new_node && new_node->next == NULL, 1);

    // Test 3: Add NULL node (should do nothing)
    ft_lstadd_front(&head, NULL);
    test_result("Add NULL node", head == second_node && head->next == new_node, 1);

    // Print the list for manual verification
    printf("\nList after additions:\n");
    print_list(head);

    // Free the list
    t_list *current = head;
    while (current)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }

    printf("\n=== End of ft_lstadd_front tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_lstadd_front();
    return 0;
}
#endif
