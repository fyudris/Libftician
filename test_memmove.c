/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:01 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/05 02:49:54 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_memmove()
{
    printf("\n=== Testing ft_memmove ===\n\n");

    struct {
        char description[50];
        char buffer[20];
        char expected[20];
        size_t n;
        size_t dest_offset;
        size_t src_offset;
    } tests[] = {
        {"Move 5 bytes forward",   "1234567890", "1234567890", 5, 5, 0},
        {"Move 5 bytes backward",  "1234567890", "1234567890", 5, 0, 5},
        {"Copy 0 bytes",           "abcdef",     "abcdef",     0, 3, 0},
        {"Copy entire buffer",     "abcdefghij", "abcdefghij", 10, 0, 0},
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        // Reset the buffer and expected arrays
        memcpy(tests[i].expected, tests[i].buffer, sizeof(tests[i].buffer));
        memcpy(tests[i].buffer, tests[i].expected, sizeof(tests[i].expected));

        // Use memmove for expected result
        memmove(tests[i].expected + tests[i].dest_offset,
                tests[i].expected + tests[i].src_offset, tests[i].n);

        // Test ft_memmove
        ft_memmove(tests[i].buffer + tests[i].dest_offset,
                   tests[i].buffer + tests[i].src_offset, tests[i].n);

        // Compare results
        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_memmove: %s", tests[i].description);

        test_result(test_name,
                    memcmp(tests[i].buffer, tests[i].expected, sizeof(tests[i].buffer)) == 0, 1);
    }

    printf("\n=== End of ft_memmove tests ===\n");
}


#ifdef MAIN
int main()
{
    test_memmove();
    return 0;
}
#endif
