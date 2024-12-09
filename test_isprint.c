/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:39:18 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/05 14:58:24 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_isprint()
{
    printf("\n=== Testing ft_isprint ===\n\n");

    int test_values[] = {
        32, 33, 48, 57, 65, 90, 97, 122, 126, // Printable characters
        0, 31, 127,                          // Control characters
        -1, 128                              // Out-of-range values
    };
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++)
    {
        int test_char = test_values[i];
        int expected = isprint(test_char) ? 1 : 0; // Normalize to 1 or 0
        int result = ft_isprint(test_char);

        char test_name[50];
        if (test_char >= 32 && test_char <= 126)
            snprintf(test_name, sizeof(test_name), "ft_isprint('%c') [ASCII %d]", test_char, test_char);
        else
            snprintf(test_name, sizeof(test_name), "ft_isprint([ASCII %d])", test_char);

        test_result(test_name, result, expected);
    }

    printf("\n=== End of ft_isprint tests ===\n\n");
}


#ifdef MAIN
int main()
{
    test_isprint();
    return 0;
}
#endif
