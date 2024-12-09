/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:47:38 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:47:47 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_itoa()
{
    printf("\n=== Testing ft_itoa ===\n\n");

    struct {
        int input;
        char expected[20];
    } tests[] = {
        {123, "123"},
        {-456, "-456"},
        {0, "0"},
        {INT_MAX, "2147483647"},
        {INT_MIN, "-2147483648"},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char *result = ft_itoa(tests[i].input);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_itoa(%d)", tests[i].input);

        test_result(test_name, result && strcmp(result, tests[i].expected) == 0, 1);

        free(result); // Free allocated memory
        i++;
    }

    printf("\n=== End of ft_itoa tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_itoa();
    return 0;
}
#endif
