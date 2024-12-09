/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:26:01 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/04 15:34:10 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strlcpy()
{
    printf("\n=== Testing ft_strlcpy ===\n\n");

    struct {
        char description[50];
        char src[50];
        char expected[50];
        size_t size;
    } tests[] = {
        {"Copy full string",        "Hello",       "Hello",       6},
        {"Truncate string",         "Hello, World!", "Hello",     6},
        {"Empty src",               "",            "",            6},
        {"Zero size",               "Hello, World!", "",          0},
        {"Exact size match",        "Hello",       "Hell",        5},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char dest[50] = {0}; // Reset destination buffer

        // Call ft_strlcpy and calculate the result
        size_t result = ft_strlcpy(dest, tests[i].src, tests[i].size);

        // Prepare expected destination buffer
        char expected_dest[50] = {0};
        if (tests[i].size > 0)
        {
            strncpy(expected_dest, tests[i].src, tests[i].size - 1);
            expected_dest[tests[i].size - 1] = '\0'; // Null-terminate
        }

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strlcpy: %s", tests[i].description);

        // Compare results
        int pass = (memcmp(dest, expected_dest, sizeof(dest)) == 0) &&
                   (result == strlen(tests[i].src));

        test_result(test_name, pass, 1);
    }

    printf("\n=== End of ft_strlcpy tests ===\n");
}

#ifdef MAIN
int main()
{
    test_strlcpy();
    return 0;
}
#endif