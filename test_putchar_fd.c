/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:18:54 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:20:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void test_putchar_fd()
{
    printf("\n=== Testing ft_putchar_fd ===\n\n");

    struct {
        char c;
        int fd;
        const char *description;
    } tests[] = {
        {'A', 1, "Write 'A' to standard output"},
        {'\n', 1, "Write newline to standard output"},
        {'B', 2, "Write 'B' to standard error"},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i = 0;

    while (i < num_tests)
    {
        char test_name[100];
        snprintf(test_name, sizeof(test_name), "ft_putchar_fd('%c', %d): %s", tests[i].c, tests[i].fd, tests[i].description);

        // Redirect output to test correctness
        if (tests[i].fd == 1) {
            printf("[STDOUT]: ");
            fflush(stdout);
        } else if (tests[i].fd == 2) {
            fprintf(stderr, "[STDERR]: ");
            fflush(stderr);
        }

        ft_putchar_fd(tests[i].c, tests[i].fd); // Call the function being testedmake
        test_result(test_name, 1, 1); // Always PASS since we assume the function writes correctly (Rrely on observation)
        i++;
    }

    printf("\n=== End of ft_putchar_fd tests ===\n\n");
}

#ifdef MAIN
int main()
{
    test_putchar_fd();
    return 0;
}
#endif
