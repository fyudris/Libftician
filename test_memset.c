/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:43:03 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/04 14:31:34 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_memset()
{
    printf("\n=== Testing ft_memset ===\n\n");

    // Define test cases
    struct {
        char description[50];
        char buffer[20];
        char expected[20];
        int value;
        size_t n;
    } tests[] = {
        {"Set 5 bytes to 'A'",       "1234567890", "AAAAA67890", 'A', 5},
        {"Set all bytes to '\\0'",   "1234567890", "\0\0\0\0\0\0\0\0\0\0", '\0', 10},
        {"Set 3 bytes to '1'",       "abcdef",     "111def",     '1', 3},
        {"Set 0 bytes to 'Z'",       "abcdef",     "abcdef",     'Z', 0},
        {"Set 8 bytes to '\\xFF'",   "abcdefghij", "\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFFij", '\xFF', 8},
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char *result = ft_memset(tests[i].buffer, tests[i].value, tests[i].n); // Call ft_memset
        memset(tests[i].expected, tests[i].value, tests[i].n);                 // Call reference memset

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_memset: %s", tests[i].description);

        test_result(test_name, memcmp(result, tests[i].expected, sizeof(tests[i].buffer)) == 0, 1);
    }

    printf("\n=== End of ft_memset tests ===\n\n");
}
#ifdef MAIN
int main()
{
    test_memset();
    return 0;
}
#endif