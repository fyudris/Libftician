/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:01:54 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/10 00:02:32 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void del_content(void *content)
{
    free(content);
}

void test_lstclear()
{
    printf("\n=== Testing ft_lstclear ===\n\n");

    // Test 1: Clear an empty list
    t_list *head = NULL;
    ft_lstclear(&head, del_content);
    test_result("Clear an empty list", head == NULL, 1);

    // Test 2: Clear a list with one node
    head = ft_lstnew(malloc(10)); // Allocate memory for content
    ft_lstclear(&head, del_content);
    test_result("Clear a list with one node", head == NULL, 1);

    // Test 3: Clear a list with multiple nodes
    head = ft_lstnew(malloc(10));
    t_list *second = ft_lstnew(malloc(20));
    t_list *third = ft_lstnew(malloc(30));
    head->next = second;
    second->next = third;
    ft_lstclear(&head, del_content);
    test_result("Clear a list with multiple nodes", head == NULL, 1);

    printf("\n=== End of ft_lstclear tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_lstclear();
    return 0;
}
#endif
