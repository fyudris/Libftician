/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:08:56 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/10 00:10:47 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void *duplicate_content(void *content)
{
    return (strdup((char *)content));
}

void free_content(void *content)
{
    free(content);
}

void print_list(t_list *head)
{
    while (head)
    {
        printf("%s -> ", (char *)head->content);
        head = head->next;
    }
    printf("NULL\n");
}

void test_lstmap()
{
    printf("\n=== Testing ft_lstmap ===\n\n");

    // Create the original list
    t_list *node1 = ft_lstnew(strdup("first"));
    t_list *node2 = ft_lstnew(strdup("second"));
    t_list *node3 = ft_lstnew(strdup("third"));
    node1->next = node2;
    node2->next = node3;

    printf("Original list:\n");
    print_list(node1);

    // Test 1: Create a new list with duplicated content
    t_list *new_list = ft_lstmap(node1, duplicate_content, free_content);
    test_result("Create a new list with duplicated content", new_list != NULL, 1);

    printf("New list:\n");
    print_list(new_list);

    // Test 2: Handle allocation failure
    t_list *failed_list = ft_lstmap(NULL, duplicate_content, free_content);
    test_result("Handle NULL list gracefully", failed_list == NULL, 1);

    // Free original and new lists
    ft_lstclear(&node1, free_content);
    ft_lstclear(&new_list, free_content);

    printf("\n=== End of ft_lstmap tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_lstmap();
    return 0;
}
#endif
