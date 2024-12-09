/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:41:29 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:41:38 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strncmp()
{
    printf("\n=== Testing ft_strncmp ===\n\n");

    struct {
        char description[50];
        char s1[50];
        char s2[50];
        size_t n;
        int expected;
    } tests[] = {
        {"Equal strings, n = 3",           "abc", "abc", 3, 0},
        {"Different strings, n = 3",       "abc", "abd", 3, -1},
        {"Shorter s1, n = 3",              "abc", "abcd", 3, 0},
        {"Shorter s2, n = 3",              "abcd", "abc", 3, 0},
        {"Equal strings, n = 0",           "abc", "abc", 0, 0},
        {"Case-sensitive difference",      "abc", "ABC", 3, 'a' - 'A'},
        {"Extended ASCII",                 "\xFA", "\xFB", 1, -1},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        int result = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strncmp: %s", tests[i].description);

        // Compare the results
        if (tests[i].expected < 0)
            test_result(test_name, result < 0, 1);
        else if (tests[i].expected > 0)
            test_result(test_name, result > 0, 1);
        else
            test_result(test_name, result == 0, 1);

        i++;
    }

    printf("\n=== End of ft_strncmp tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strncmp();
    return 0;
}
#endif