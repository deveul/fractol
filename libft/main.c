/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:57:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/19 14:01:03 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

int		main()
{
	unsigned long long nb;

	nb = 18446744073709551615;
	ft_printf("len is :%d", ft_unslololen(nb));
}
