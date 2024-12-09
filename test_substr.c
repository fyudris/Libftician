/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:13:39 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:13:49 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_substr()
{
    printf("\n=== Testing ft_substr ===\n\n");

    struct {
        char description[50];
        char input[50];
        unsigned int start;
        size_t len;
        char expected[50];
    } tests[] = {
        {"Extract valid substring",    "Hello, World!", 7, 5, "World"},
        {"Start out of range",         "Hello", 10, 3, ""},
        {"Length exceeds input",       "Hello", 2, 10, "llo"},
        {"Empty string input",         "", 0, 5, ""},
        {"Zero length",                "Hello, World!", 5, 0, ""},
        {"Start at string end",        "Hello", 5, 5, ""},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_substr(tests[i].input, tests[i].start, tests[i].len);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_substr: %s", tests[i].description);

        test_result(test_name, result && strcmp(result, tests[i].expected) == 0, 1);

        free(result); // Free the allocated memory
        i++;
    }

    printf("\n=== End of ft_substr tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_substr();
    return 0;
}
#endif
