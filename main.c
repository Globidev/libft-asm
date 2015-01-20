/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 22:45:40 by gudepard          #+#    #+#             */
/*   Updated: 2015/01/21 00:02:04 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_bzero(void *, size_t);

int main(int argc, char **argv)
{
	int i;
	char b[5] = { 1, 1, 1, 1, 1 };

	for (i = 0; i < 5; ++i)
		printf("%d", b[i]);

	printf("\n");
	ft_bzero(b, sizeof(b));

	for (i = 0; i < 5; ++i)
		printf("%d", b[i]);

	return 0;
}
