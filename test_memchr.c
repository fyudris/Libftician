/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:45:58 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:51:42 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_memchr()
{
    printf("\n=== Testing ft_memchr ===\n\n");

    struct {
        char description[50];
        char buffer[50];
        int c;
        size_t n;
        char *expected;
    } tests[] = {
        {"Find 'o' in 'Hello, World!'", "Hello, World!", 'o', 12, "o, World!"},
        {"Find ',' in 'Hello, World!'", "Hello, World!", ',', 12, ", World!"},
        //{"Find null byte",              "Hello, World!", '\0', 13, ""},
        {"Byte not in memory block",    "Hello, World!", 'z', 12, NULL},
        {"Empty buffer, search for 'a'", "", 'a', 5, NULL},
        {"Partial buffer match",        "Hello, World!", 'o', 4, NULL},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        void *result = ft_memchr(tests[i].buffer, tests[i].c, tests[i].n);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_memchr: %s", tests[i].description);

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

    printf("\n=== End of ft_memchr tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_memchr();
    return 0;
}
#endif