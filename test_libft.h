/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:46:56 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:49:02 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIBFT_H
# define TESTLIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
#include <limits.h>

# include "../libft.h"

void test_result(const char *test_name, int result, int expected);
void test_string_result(const char *test_name, const char *result, const char *expected);

#endif
