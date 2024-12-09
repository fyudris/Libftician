/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:03:14 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/10 00:07:41 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void print_content(void *content)
{
    printf("%s ", (char *)content);
}

void modify_content(void *content)
{
    if (!content) // Ensure content is not NULL
        return;

    char *str = (char *)content;
    while (*str)
    {
        *str = (*str >= 'a' && *str <= 'z') ? *str - 32 : *str; // Convert to uppercase
        str++;
    }
}

void test_lstiter()
{
    printf("\n=== Testing ft_lstiter ===\n\n");

    // Test 1: Apply a function to print each node
    t_list *node1 = ft_lstnew(strdup("first"));
    t_list *node2 = ft_lstnew(strdup("second"));
    t_list *node3 = ft_lstnew(strdup("third"));
    node1->next = node2;
    node2->next = node3;

    printf("Printing list contents:\n");
    ft_lstiter(node1, print_content);
    printf("\n");
    test_result("Print each node's content", 1, 1);

    // Test 2: Apply a function to modify each node's content
    ft_lstiter(node1, modify_content);
    printf("Modified list contents:\n");
    ft_lstiter(node1, print_content);
    printf("\n");
    test_result("Modify each node's content", 1, 1);

    // Free the list and its content
    t_list *current = node1;
    while (current)
    {
        t_list *next = current->next;
        free(current->content); // Free the allocated string
        free(current);
        current = next;
    }

    printf("\n=== End of ft_lstiter tests ===\n\n");
}


#ifdef MAIN
int main()
{
    test_lstiter();
    return 0;
}
#endif
