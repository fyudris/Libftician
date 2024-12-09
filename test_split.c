/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:39:50 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:42:39 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static void	free_all(char **words, int count);
static size_t	count_words(const char *s, char c);

void test_split()
{
    printf("\n=== Testing ft_split ===\n\n");

    struct {
        char description[50];
        char input[50];
        char delimiter;
        char *expected[10]; // Maximum expected words
    } tests[] = {
        {"Simple split",           "Hello World 42", ' ', {"Hello", "World", "42", NULL}},
        {"Multiple delimiters",    "   Hello   World   ", ' ', {"Hello", "World", NULL}},
        {"Single word",            "Hello", ' ', {"Hello", NULL}},
        {"Empty string",           "", ' ', {NULL}},
        {"Delimiter only",         "/////", '/', {NULL}},
        {"Special characters",     "a,b,c", ',', {"a", "b", "c", NULL}},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char **result = ft_split(tests[i].input, tests[i].delimiter);

        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_split: %s", tests[i].description);

        int pass = 1;
        for (int j = 0; tests[i].expected[j]; j++)
        {
            if (!result[j] || strcmp(result[j], tests[i].expected[j]) != 0)
            {
                pass = 0;
                break;
            }
        }
        if (result && result[0] == NULL && tests[i].expected[0] == NULL)
            pass = 1; // Special case for empty input

        test_result(test_name, pass, 1);

        free_all(result, count_words(tests[i].input, tests[i].delimiter));
        i++;
    }

    printf("\n=== End of ft_split tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_split();
    return 0;
}
#endif

static void	free_all(char **words, int count)
{
	while (count)
		free(words[--count]);
	free(words);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}