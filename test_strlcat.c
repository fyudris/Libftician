/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:40:23 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:12:52 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

#include "test_libft.h"

void test_strlcat()
{
    printf("\n=== Testing ft_strlcat ===\n\n");

    struct {
        char description[50];
        char dst[50];
        char src[50];
        char expected[50];
        size_t size;
        size_t expected_len;
    } tests[] = {
        {"Append with enough space", "Hello", ", World!", "Hello, World!", 50, 13},
        {"Append with truncation",   "Hello", ", World!", "Hello, Wo",    10, 13},
        {"Empty dst",                "", "Hello", "Hello", 10, 5},
        {"Empty src",                "Hello", "", "Hello", 10, 5},
        //{"Zero size",                "Hello", ", World!", "Hello", 0, 13}, // dst untouched
        {"Exact size match",         "Hello", ", World!", "Hello", 6, 13}, // dst null-terminated
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        // Prepare destination buffer for the test
        char dst[50];
        strncpy(dst, tests[i].dst, sizeof(dst));

        // Call ft_strlcat and capture the result
        size_t result = ft_strlcat(dst, tests[i].src, tests[i].size);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strlcat: %s", tests[i].description);

        // Compare the results
        int pass = (memcmp(dst, tests[i].expected, sizeof(dst)) == 0) &&
                   (result == tests[i].expected_len);

        test_result(test_name, pass, 1);
    }

    printf("\n=== End of ft_strlcat tests ===\n");
}

#ifdef MAIN
int main()
{
    test_strlcat();
    return 0;
}
#endif