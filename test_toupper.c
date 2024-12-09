/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:15:23 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:16:36 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_toupper()
{
    printf("\n=== Testing ft_toupper ===\n\n");

    int test_values[] = {
        'a', 'z', // Lowercase letters
        'A', 'Z', // Uppercase letters (should remain unchanged)
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
        int expected = toupper(test_char);
        int result = ft_toupper(test_char);

        char test_name[50];
        if (test_char >= 32 && test_char <= 126)
            snprintf(test_name, sizeof(test_name), "ft_toupper('%c') [ASCII %d]", test_char, test_char);
        else
            snprintf(test_name, sizeof(test_name), "ft_toupper([ASCII %d])", test_char);

        test_result(test_name, result, expected);
        i++;
    }

    printf("\n=== End of ft_toupper tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_toupper();
    return 0;
}
#endif
