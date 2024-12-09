/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:12:43 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/05 14:58:37 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_isdigit()
{
    printf("\n=== Testing ft_isdigit ===\n\n");

    int test_values[] = {
        '0', '1', '5', '9',       // Valid digits
        'A', 'Z', 'a', 'z',       // Alphabetic characters (should return 0)
        '@', '[', '`', '{',       // Characters around digit ranges
        '\n', '\t', ' ',          // Control and whitespace characters
        EOF,                      // End of file indicator
        -1, 128,                  // Out-of-bound ASCII values
        0                         // Null character
    };
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++)
    {
        int test_char = test_values[i];
        int expected = isdigit(test_char) ? 1 : 0; // Normalize to 1 or 0
        int result = ft_isdigit(test_char);

        char test_name[50];
        if (test_char >= 32 && test_char <= 126)
            snprintf(test_name, sizeof(test_name), "ft_isdigit('%c') [ASCII %d]", test_char, test_char);
        else
            snprintf(test_name, sizeof(test_name), "ft_isdigit([ASCII %d])", test_char);

        test_result(test_name, result, expected);
    }
    printf("\n=== End of ft_isdigit tests ===\n\n");
}


#ifdef MAIN
int main()
{
    test_isdigit();
    return 0;
}
#endif
