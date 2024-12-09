/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:19:04 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:19:36 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_strjoin()
{
    printf("\n=== Testing ft_strjoin ===\n\n");

    struct {
        char description[50];
        char s1[50];
        char s2[50];
        char expected[100];
    } tests[] = {
        {"Concatenate two strings",      "Hello, ", "World!", "Hello, World!"},
        {"Empty first string",           "", "World!", "World!"},
        {"Empty second string",          "Hello", "", "Hello"},
        {"Both strings empty",           "", "", ""},
        {"Strings with spaces",          "Hello ", "World ", "Hello World "},
        {"Special characters",           "@#$", "123", "@#$123"},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_strjoin(tests[i].s1, tests[i].s2);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_strjoin: %s", tests[i].description);

        test_result(test_name, result && strcmp(result, tests[i].expected) == 0, 1);

        free(result);
        i++;
    }

    printf("\n=== End of ft_strjoin tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_strjoin();
    return 0;
}
#endif
