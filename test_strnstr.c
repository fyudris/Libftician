/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:58:30 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:59:05 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strnstr()
{
    printf("\n=== Testing ft_strnstr ===\n\n");

    struct {
        char description[50];
        char big[50];
        char little[50];
        size_t len;
        char *expected;
    } tests[] = {
        {"Match in the middle",          "Hello, World!", "World", 12, "World!"},
        {"Match at the start",           "Hello, World!", "Hello", 12, "Hello, World!"},
        {"Match with len limiting",      "Hello, World!", "World", 5, NULL},
        {"Empty substring",              "Hello, World!", "", 12, "Hello, World!"},
        {"Substring not in string",      "Hello, World!", "Earth", 12, NULL},
        {"Exact match at end",           "Hello, World!", "World!", 13, "World!"},
        {"Partial match at end",         "Hello, World!", "World!!", 13, NULL},
        {"Empty string and substring",   "", "", 0, ""},
        {"Empty string, non-empty substring", "", "Hello", 5, NULL},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_strnstr(tests[i].big, tests[i].little, tests[i].len);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strnstr: %s", tests[i].description);

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

    printf("\n=== End of ft_strnstr tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strnstr();
    return 0;
}
#endif
