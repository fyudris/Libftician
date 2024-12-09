/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:49:19 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:55:07 by fyudris          ###   ########.fr       */
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

void test_lstlast()
{
    printf("\n=== Testing ft_lstlast ===\n\n");

    // Test 1: Empty list
    t_list *head = NULL;
    test_result("Empty list", ft_lstlast(head) == NULL, 1);

    // Test 2: List with one node
    head = ft_lstnew("first");
    test_result("List with one node", ft_lstlast(head) == head, 1);

    // Test 3: List with multiple nodes
    t_list *second = ft_lstnew("second");
    t_list *third = ft_lstnew("third");
    head->next = second;  // Link first -> second
    second->next = third; // Link second -> third
    test_result("List with multiple nodes", ft_lstlast(head) == third, 1);

    // Print the list for manual verification
    printf("\nList:\n");
    print_list(head);

    // Free the list
    t_list *current = head;
    while (current)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }

    printf("\n=== End of ft_lstlast tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_lstlast();
    return 0;
}
#endif
