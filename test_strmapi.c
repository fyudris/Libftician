/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:51:42 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:59:31 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

// Test function: Converts letters to uppercase if index is even
char test_function(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return (c - 32); // Convert to uppercase
    return (c);
}

void test_strmapi()
{
    printf("\n=== Testing ft_strmapi ===\n\n");

    struct {
        char input[50];
        char expected[50];
    } tests[] = {
        {"abcdef", "AbCdEf"},     // Mixed letters
        {"", ""},                 // Empty string
        {"!@#", "!@#"},           // Special characters
        {"HELLO", "HELLO"},       // All uppercase letters
        {"a1b2c3", "A1B2C3"},     // Mixed characters
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_strmapi(tests[i].input, test_function);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strmapi(\"%s\")", tests[i].input);

        test_result(test_name, result && strcmp(result, tests[i].expected) == 0, 1);

        free(result); // Free allocated memory
        i++;
    }

    printf("\n=== End of ft_strmapi tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strmapi();
    return 0;
}
#endif
