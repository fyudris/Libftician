/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:18:19 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:18:34 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_tolower()
{
    printf("\n=== Testing ft_tolower ===\n\n");

    int test_values[] = {
        'A', 'Z', // Uppercase letters
        'a', 'z', // Lowercase letters (should remain unchanged)
        '0', '9', // Digits (should remain unchanged)
        '@', '[', '`', '{', // Symbols around letter ranges
        '\n', '\t', ' ',    // Control and whitespace characters
        EOF,                // End of file indicator
        -1, 128             // Out-of-bound ASCII values
    };
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    int i = 0;

    while (i < num_tests)
    {
        int test_char = test_values[i];
        int expected = tolower(test_char);
        int result = ft_tolower(test_char);

        char test_name[50];
        if (test_char >= 32 && test_char <= 126)
            snprintf(test_name, sizeof(test_name), "ft_tolower('%c') [ASCII %d]", test_char, test_char);
        else
            snprintf(test_name, sizeof(test_name), "ft_tolower([ASCII %d])", test_char);

        test_result(test_name, result, expected);
        i++;
    }

    printf("\n=== End of ft_tolower tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_tolower();
    return 0;
}
#endif
