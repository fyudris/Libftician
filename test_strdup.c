/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:06:27 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:06:42 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strdup()
{
    printf("\n=== Testing ft_strdup ===\n\n");

    struct {
        char description[50];
        char input[50];
    } tests[] = {
        {"Regular string",         "Hello, World!"},
        {"Empty string",           ""},
        {"Single character",       "A"},
        {"String with spaces",     "   leading and trailing   "},
        {"Special characters",     "!@#$%^&*()_+"},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_strdup(tests[i].input);
        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strdup: %s", tests[i].description);

        if (result)
        {
            test_result(test_name, strcmp(result, tests[i].input) == 0, 1);
            free(result); // Free the allocated memory
        }
        else
        {
            test_result(test_name, 0, 1); // Fail if memory allocation fails
        }

        i++;
    }

    printf("\n=== End of ft_strdup tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strdup();
    return 0;
}
#endif
