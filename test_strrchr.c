/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:21:42 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:21:51 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strrchr()
{
    printf("\n=== Testing ft_strrchr ===\n\n");

    struct {
        char description[50];
        char str[50];
        int c;
        char *expected;
    } tests[] = {
        {"Find 'o' in 'Hello, World!'", "Hello, World!", 'o', "orld!"},
        {"Find 'z' in 'Hello, World!'", "Hello, World!", 'z', NULL},
        {"Find ',' in 'Hello, World!'", "Hello, World!", ',', ", World!"},
        {"Find null character",         "Hello, World!", '\0', ""},
        {"Empty string with 'a'",      "", 'a', NULL},
        {"Empty string with null",     "", '\0', ""},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_strrchr(tests[i].str, tests[i].c);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strrchr: %s", tests[i].description);

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

    printf("\n=== End of ft_strrchr tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strrchr();
    return 0;
}
#endif
