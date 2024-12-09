/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_listnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:29:32 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:31:25 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_lstnew()
{
    printf("\n=== Testing ft_lstnew ===\n\n");

    struct {
        void *content;
        const char *description;
        int is_string;
    } tests[] = {
        {"Hello, World!", "Create a node with a string", 1},
        {(void *)42, "Create a node with an integer (casted to void *)", 0},
        {NULL, "Create a node with NULL content", 0},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        t_list *node = ft_lstnew(tests[i].content);

        char test_name[200];
        if (tests[i].is_string && tests[i].content) {
            snprintf(test_name, sizeof(test_name), "ft_lstnew(\"%s\"): %s",
                     (char *)tests[i].content, tests[i].description);
        } else if (tests[i].content) {
            snprintf(test_name, sizeof(test_name), "ft_lstnew(%p): %s",
                     tests[i].content, tests[i].description);
        } else {
            snprintf(test_name, sizeof(test_name), "ft_lstnew(NULL): %s",
                     tests[i].description);
        }

        // Validate the node's creation and fields
        int pass = (node != NULL) &&
                   (node->content == tests[i].content) &&
                   (node->next == NULL);

        test_result(test_name, pass, 1);

        free(node); // Free allocated memory
        i++;
    }

    printf("\n=== End of ft_lstnew tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_lstnew();
    return 0;
}
#endif

