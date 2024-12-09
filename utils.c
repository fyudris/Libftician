/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:22:56 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/04 01:38:08 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

// ANSI color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define GREEN       "\033[32m"
#define RED         "\033[31m"
#define YELLOW      "\033[33m"

// Test result function for integer comparisons
void test_result(const char *test_name, int result, int expected)
{
    if (result == expected)
    {
        printf(GREEN "[PASS] " RESET "%s\n", test_name);
	}
    else
    {
        printf(RED "[FAIL] " RESET "%s\n", test_name);
        printf(YELLOW "  -> Expected: %d, Got: %d\n" RESET, expected, result);
    }
}

// Test result function for string comparisons
void test_string_result(const char *test_name, const char *result, const char *expected)
{
    if (strcmp(result, expected) == 0)
    {
        printf(GREEN "[PASS] " RESET "%s\n", test_name);
	}
    else
    {
        printf(RED "[FAIL] " RESET "%s\n", test_name);
        printf(YELLOW "  -> Expected: \"%s\"\n" RESET, expected);
        printf(YELLOW "  -> Got:      \"%s\"\n" RESET, result);
    }
}
