/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:51:51 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:52:02 by fyudris          ###   ########.fr       */
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

void test_lstadd_back()
{
    printf("\n=== Testing ft_lstadd_back ===\n\n");

    // Test 1: Add to an empty list
    t_list *head = NULL;
    t_list *new_node = ft_lstnew("first");
    ft_lstadd_back(&head, new_node);
    test_result("Add to empty list", head == new_node && head->next == NULL, 1);

    // Test 2: Add to a non-empty list
    t_list *second_node = ft_lstnew("second");
    ft_lstadd_back(&head, second_node);
    test_result("Add to non-empty list",
                head != NULL && ft_lstlast(head) == second_node, 1);

    // Test 3: Add NULL node (should do nothing)
    ft_lstadd_back(&head, NULL);
    test_result("Add NULL node", ft_lstlast(head) == second_node, 1);

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

    printf("\n=== End of ft_lstadd_back tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_lstadd_back();
    return 0;
}
#endif
