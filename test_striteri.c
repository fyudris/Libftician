/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:02:41 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 15:09:37 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

// Test function 1: Convert lowercase to uppercase
void to_uppercase(unsigned int i, char *c)
{
    if (i >= 0 && *c >= 'a' && *c <= 'z')
        *c -= 32;
}

// Test function 2: Increment by index
void increment_by_index(unsigned int i, char *c)
{
    *c += i % 10;
}

void test_striteri()
{
    printf("\n=== Testing ft_striteri ===\n\n");

    struct {
        char input[50];
        void (*f)(unsigned int, char *);
        char expected[50];
    } tests[] = {
        {"abcdef", to_uppercase, "ABCDEF"},      // Convert to uppercase
        {"hello, 42!", to_uppercase, "HELLO, 42!"},
        {"abc", increment_by_index, "ace"},     // Increment by index
        {"", to_uppercase, ""},                 // Empty string
        //{"!@#", increment_by_index, "!B%"},     // Special characters
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char result[50];
        strcpy(result, tests[i].input); // Copy input to result for in-place modification

        ft_striteri(result, tests[i].f);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_striteri(\"%s\")", tests[i].input);

        test_result(test_name, strcmp(result, tests[i].expected) == 0, 1);

        i++;
    }

    printf("\n=== End of ft_striteri tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_striteri();
    return 0;
}
#endif
