/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:23:36 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/05 15:02:26 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_isalnum()
{
    printf("\n=== Testing ft_isalnum ===\n\n");

    int test_values[] = {
        '0', '1', '5', '9',       // Valid digits
        'A', 'Z', 'a', 'z',       // Valid alphabetic characters
        '@', '[', '`', '{',       // Symbols near alphanumeric ranges
        '\n', '\t', ' ',          // Control and whitespace characters
        EOF,                      // End of file indicator
        -1, 128,                  // Out-of-bound ASCII values
        0                         // Null character
    };
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++)
    {
        int test_char = test_values[i];
        int expected = isalnum(test_char) ? 1 : 0;    // Reference result
        int result = ft_isalnum(test_char);   // Test function result

        char test_name[50];
        if (test_char >= 32 && test_char <= 126)
            snprintf(test_name, sizeof(test_name), "ft_isalnum('%c') [ASCII %d]", test_char, test_char);
        else
            snprintf(test_name, sizeof(test_name), "ft_isalnum([ASCII %d])", test_char);

        test_result(test_name, result, expected);
    }

    printf("\n=== End of ft_isalnum tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_isalnum();
    return 0;
}
#endif
