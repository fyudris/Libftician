/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:38:22 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/04 14:29:24 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strlen()
{
    printf("\n=== Testing ft_strlen ===\n\n");

    const char *test_strings[] = {
        "",                      // Empty string
        "a",                     // Single character
        "Hello",                 // Normal string
        "Hello, World!",         // String with punctuation
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.", // Long string
        "\0hidden",              // Null character at the start
        "hidden\0more",          // Null character in the middle
        "\t\n\r\v\f",            // Control characters
        " ",                     // Space
        NULL                     // Null pointer
    };
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (int i = 0; i < num_tests; i++)
    {
        const char *test_str = test_strings[i];
        size_t expected, result;

        if (test_str != NULL)
        {
            expected = strlen(test_str);
            result = ft_strlen(test_str);

            char test_name[100];
            snprintf(test_name, sizeof(test_name), "ft_strlen(\"%s\")", test_str[0] ? test_str : "(empty)");

            test_result(test_name, result, expected);
        }
        else
        {
            printf("[SKIP] ft_strlen(NULL) - Behavior undefined\n");
        }
    }

    printf("\n=== End of ft_strlen tests ===\n");
}

#ifdef MAIN
int main()
{
    test_strlen();
    return 0;
}
#endif