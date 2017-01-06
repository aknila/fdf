/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:37:54 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:37:56 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_key_code1(int kc, t_ptr *ptr)
{
	if (kc == 83 || kc == 86 || kc == 89)
		fdf_key_code2_1(kc, ptr);
	if (kc == 84 || kc == 87 || kc == 91)
		fdf_key_code2_2(kc, ptr);
	if (kc == 85 || kc == 88 || kc == 92)
		fdf_key_code2_3(kc, ptr);
	if (kc == 82 || kc == 65)
		fdf_key_code3(kc, ptr);
	if (kc == 123 || kc == 124 || kc == 125 || kc == 126)
		fdf_key_code4(kc, ptr);
	if (kc == 78 || kc == 69)
		fdf_key_code5(kc, ptr);
	if (kc == 53 || kc == 71 || kc == 36)
		fdf_key_code6(kc, ptr);
	if (ptr->form == 0)
		fdf_map_in_windows(ptr);
	if (ptr->form == 1)
		fdf_map_in_windows2(ptr);
	return (0);
}
