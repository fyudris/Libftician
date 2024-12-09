/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:26:52 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:32:53 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strtrim()
{
    printf("\n=== Testing ft_strtrim ===\n\n");

    struct {
        char description[50];
        char s1[50];
        char set[50];
        char expected[50];
    } tests[] = {
        {"Trim spaces",               "  Hello, World!  ", " ", "Hello, World!"},
        {"Trim specific characters",  "xxHello, World!xx", "x", "Hello, World!"},
        {"Trim both ends",            "**Hello**", "*", "Hello"},
        {"No characters to trim",     "Hello", " ", "Hello"},
        {"Empty string",              "", " ", ""},
        {"Empty set",                 "Hello", "", "Hello"},
        {"Trim all characters",       "aaaa", "a", ""},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_strtrim(tests[i].s1, tests[i].set);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strtrim: %s", tests[i].description);

        test_result(test_name, result && strcmp(result, tests[i].expected) == 0, 1);

        free(result); // Free the allocated memory
        i++;
    }

    printf("\n=== End of ft_strtrim tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strtrim();
    return 0;
}
#endif
