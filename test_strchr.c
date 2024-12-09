/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:28:18 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:28:28 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strchr()
{
    printf("\n=== Testing ft_strchr ===\n\n");

    struct {
        char description[50];
        char str[50];
        int c;
        char *expected;
    } tests[] = {
        {"Find 'o' in 'Hello, World!'", "Hello, World!", 'o', "o, World!"},
        {"Find ',' in 'Hello, World!'", "Hello, World!", ',', ", World!"},
        {"Find null terminator",         "Hello, World!", '\0', ""},
        {"Find 'z' in 'Hello, World!'", "Hello, World!", 'z', NULL},
        {"Empty string with 'a'",       "", 'a', NULL},
        {"Empty string with null",      "", '\0', ""},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_strchr(tests[i].str, tests[i].c);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strchr: %s", tests[i].description);

        if (tests[i].expected)
        {
            test_result(test_name, result && strcmp(result, tests[i].expected) == 0, 1);
        }
        else
        {
            test_result(test_name, result == NULL, 1);
        }
        i++;
    }

    printf("\n=== End of ft_strchr tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strchr();
    return 0;
}
#endif
