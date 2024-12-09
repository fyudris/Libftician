/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:49:58 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:50:07 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_memcmp()
{
    printf("\n=== Testing ft_memcmp ===\n\n");

    struct {
        char description[50];
        char s1[50];
        char s2[50];
        size_t n;
        int expected;
    } tests[] = {
        {"Identical buffers, n = 5",         "Hello", "Hello", 5, 0},
        {"First buffer < Second, n = 5",     "Hello", "Hella", 5, 'o' - 'a'},
        {"First buffer > Second, n = 5",     "Hella", "Hello", 5, 'a' - 'o'},
        {"Different at last byte, n = 3",    "Hel", "Hea", 3, 'l' - 'a'},
        {"Empty buffers, n = 0",             "", "", 0, 0},
        {"Partial match, n = 3",             "Hello", "Hel", 3, 0},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        int result = ft_memcmp(tests[i].s1, tests[i].s2, tests[i].n);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_memcmp: %s", tests[i].description);

        if (tests[i].expected < 0)
            test_result(test_name, result < 0, 1);
        else if (tests[i].expected > 0)
            test_result(test_name, result > 0, 1);
        else
            test_result(test_name, result == 0, 1);

        i++;
    }

    printf("\n=== End of ft_memcmp tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_memcmp();
    return 0;
}
#endif
