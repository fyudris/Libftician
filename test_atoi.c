/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:03:12 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:03:27 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_atoi()
{
    printf("\n=== Testing ft_atoi ===\n\n");

    struct {
        char description[50];
        char input[50];
        int expected;
    } tests[] = {
        {"Convert positive number",        "123", 123},
        {"Convert negative number",        "-123", -123},
        {"Leading whitespace",             "   456", 456},
        {"Trailing characters",            "78abc", 78},
        {"Empty string",                   "", 0},
        {"Only whitespace",                "   ", 0},
        {"Single '+' sign",                "+42", 42},
        {"Single '-' sign",                "-42", -42},
        {"Whitespace and '+'",             "  +99", 99},
        {"Invalid sign combination",       "+-123", 0},
        {"Non-numeric characters",         "abcd", 0},
        {"Zero value",                     "0", 0},
        {"Whitespace and zero",            "  0", 0},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        int result = ft_atoi(tests[i].input);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_atoi: %s", tests[i].description);

        test_result(test_name, result == tests[i].expected, 1);
        i++;
    }

    printf("\n=== End of ft_atoi tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_atoi();
    return 0;
}
#endif
