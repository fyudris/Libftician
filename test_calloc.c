/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:16 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 19:55:23 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_calloc()
{
    printf("\n=== Testing ft_calloc ===\n\n");

    struct {
        char description[50];
        size_t nmemb;
        size_t size;
        int expected_result; // 1 if allocation succeeds, 0 if it should fail
    } tests[] = {
        {"Allocate 10 bytes", 10, 1, 1},
        {"Allocate 0 bytes", 0, 1, 1},
        {"Allocate 0 members", 1, 0, 1},
        {"Allocate large array", 100, 100, 1},
        {"Overflow test", __SIZE_MAX__, 2, 0},
        {"Allocate single element", 1, sizeof(int), 1},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        void *result = ft_calloc(tests[i].nmemb, tests[i].size);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_calloc: %s", tests[i].description);

        if (tests[i].expected_result == 0)
        {
            // Allocation should fail
            test_result(test_name, result == NULL, 1);
        }
        else
        {
            // Allocation should succeed
            if (result != NULL)
            {
                // Check if memory is zero-initialized
                int is_zero = 1;
                size_t j = 0;
                while (j < tests[i].nmemb * tests[i].size)
                {
                    if (((unsigned char *)result)[j] != 0)
                    {
                        is_zero = 0;
                        break;
                    }
                    j++;
                }
                test_result(test_name, is_zero, 1);
                free(result);
            }
            else
            {
                test_result(test_name, 0, 1); // Allocation failed unexpectedly
            }
        }
        i++;
    }

    printf("\n=== End of ft_calloc tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_calloc();
    return 0;
}
#endif
