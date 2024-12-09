/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:20:55 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/04 14:31:26 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_memcpy()
{
    printf("\n=== Testing ft_memcpy ===\n\n");

    struct {
        char description[50];
        char src[20];
        char dest[20];
        char expected[20];
        size_t n;
    } tests[] = {
        {"Copy 5 bytes",          "1234567890", "abcdefghij", "12345fghij", 5},
        {"Copy entire array",     "abcdef",     "123456",     "abcdef",     6},
        {"Copy 0 bytes",          "abcdef",     "123456",     "123456",     0},
        {"Copy partial overlap",  "abcdefghij", "abcdefghij", "abcdefghij", 4}, // Unsafe, just for test
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        // Prepare the expected buffer using the reference memcpy
        memcpy(tests[i].expected, tests[i].dest, sizeof(tests[i].dest));
        memcpy(tests[i].expected, tests[i].src, tests[i].n);

        // Test ft_memcpy
        ft_memcpy(tests[i].dest, tests[i].src, tests[i].n);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_memcpy: %s", tests[i].description);

        test_result(test_name, memcmp(tests[i].dest, tests[i].expected, sizeof(tests[i].dest)) == 0, 1);
    }

    printf("\n=== End of ft_memcpy tests ===\n");
}

#ifdef MAIN
int main()
{
    test_memcpy();
    return 0;
}
#endif