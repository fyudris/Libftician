/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:12:14 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/04 11:28:08 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_bzero()
{
    printf("\n=== Testing ft_bzero ===\n\n");

    struct {
        char description[50];
        char buffer[20];
        char expected[20];
        size_t n;
    } tests[] = {
        {"Set 5 bytes to 0",   "1234567890", "1234567890", 5},
        {"Set all bytes to 0", "abcdef",     "abcdef",     6},
        {"Set 0 bytes to 0",   "abcdef",     "abcdef",     0},
        {"Set 10 bytes to 0",  "abcdefghij", "abcdefghij", 10},
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        // Prepare the expected buffer
        memcpy(tests[i].expected, tests[i].buffer, sizeof(tests[i].buffer));
        memset(tests[i].expected, 0, tests[i].n);

        // Test ft_bzero
        ft_bzero(tests[i].buffer, tests[i].n);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_bzero: %s", tests[i].description);

        test_result(test_name, memcmp(tests[i].buffer, tests[i].expected, sizeof(tests[i].buffer)) == 0, 1);
    }

    printf("\n=== End of ft_bzero tests ===\n");
}
#ifdef MAIN
int main()
{
    test_bzero();
    return 0;
}
#endif