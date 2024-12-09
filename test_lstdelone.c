/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:59:15 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:59:47 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void del_content(void *content)
{
    free(content);
}

void test_lstdelone()
{
    printf("\n=== Testing ft_lstdelone ===\n\n");

    // Test 1: Delete a single node
    t_list *node = ft_lstnew(malloc(10)); // Allocate some memory for content
    if (node && node->content)
        memset(node->content, 'A', 10); // Fill with dummy data
    ft_lstdelone(node, del_content);   // Delete the node
    test_result("Delete a single node", 1, 1); // Assume PASS if no crash

    // Test 2: NULL node (should do nothing)
    ft_lstdelone(NULL, del_content);
    test_result("Delete NULL node", 1, 1); // Assume PASS if no crash

    // Test 3: NULL del function (should do nothing)
    node = ft_lstnew(malloc(10));
    if (node && node->content)
        memset(node->content, 'B', 10); // Fill with dummy data
    ft_lstdelone(node, NULL);          // Pass NULL as del (should not crash)
    test_result("Delete with NULL del function", 1, 1);

    printf("\n=== End of ft_lstdelone tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_lstdelone();
    return 0;
}
#endif
