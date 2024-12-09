/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:34:39 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/04 01:37:25 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_isascii()
{
    printf("\n=== Testing ft_isascii ===\n\n");

    int test_values[] = {
        0, 127,                   // ASCII boundary values
        32, 64, 96,               // Printable ASCII values
        -1, 128,                  // Values just outside the ASCII range
        -128, 255,                // Extreme out-of-range values
        EOF                       // End of file indicator
    };
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++)
    {
        int test_char = test_values[i];
        int expected = isascii(test_char);
        int result = ft_isascii(test_char);

        char test_name[50];
        if (test_char >= 32 && test_char <= 126)
            snprintf(test_name, sizeof(test_name), "ft_isascii('%c') [ASCII %d]", test_char, test_char);
        else
            snprintf(test_name, sizeof(test_name), "ft_isascii([ASCII %d])", test_char);

        test_result(test_name, result, expected);
    }

    printf("\n=== End of ft_isascii tests ===\n\n");
}
#ifdef MAIN
int main()
{
    test_isascii();
    return 0;
}
#endif
