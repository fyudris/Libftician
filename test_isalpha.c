/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:16:36 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/05 15:01:48 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_isalpha()
{
    printf("\n=== Testing ft_isalpha ===\n\n");

    int test_values[] = {
        'A', 'Z', 'a', 'z',       // Valid alphabetic characters
        '0', '9',                 // Digits (should return 0)
        '@', '[', '`', '{',       // Characters around alphabetic ranges
        '\n', '\t', ' ',          // Control and whitespace characters
        EOF,                      // End of file indicator
        -1, 128,                  // Out-of-bound ASCII values
        0                         // Null character
    };
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    for (int i = 0; i < num_tests; i++)
    {
        int test_char = test_values[i];
        int expected = isalpha(test_char) ? 1 : 0;   // Reference result
        int result = ft_isalpha(test_char);   // Test function result

        char test_name[50];
        if (test_char >= 32 && test_char <= 126)
            snprintf(test_name, sizeof(test_name), "ft_isalpha('%c') [ASCII %d]", test_char, test_char);
        else
            snprintf(test_name, sizeof(test_name), "ft_isalpha([ASCII %d])", test_char);

        test_result(test_name, result, expected);
    }
    printf("\n=== End of ft_isalpha tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_isalpha();
    return 0;
}
#endif
