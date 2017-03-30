/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:35:06 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/05 20:35:09 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
// static int        uctoutf8(const char *dest, wchar_t ch)
// {
// 	unsigned char    *p;
//
// 	p = (unsigned char *)dest;
// 	if (ch < 0x80)
// 		*p++ = (unsigned char)(ch);
// 	else if (ch < 0x800)
// 	{
// 		*p++ = (unsigned char)((ch >> 6) | 0xC0);
// 		*p++ = (unsigned char)((ch & 0x3F) | 0x80);
// 	}
// 	else if (ch < 0x10000)
// 	{
// 		*p++ = (unsigned char)(((ch >> 12)) | 0xE0);
// 		*p++ =  (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
// 		*p++ =  (unsigned char)((ch & 0x3F) | 0x80);
// 	}
// 	else if (ch < 0x110000)
// 	{
// 		*p++ = (unsigned char)(((ch >> 18)) | 0xF0);
// 		*p++ = (unsigned char)(((ch >> 12) & 0x3F) | 0x80);
// 		*p++ = (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
// 		*p++ = (unsigned char)((ch & 0x3F) | 0x80);
// 	}
// 	return ((int)p != (int)dest ? 1 : 0);
// }

void    ft_putchar(int _c)
{
	// wchar_t    c;
	//
	// (void)uctoutf8((char *)&c, _c);
	// if (_c < 0x80)
	// 	write(1, &c, 1);
	// else if (_c < 0x800)
	// 	write(1, &c, 2);
	// else if (_c < 0x10000)
	// 	write(1, &c, 3);
	// else if (_c < 0x110000)
	// 	write(1, &c, 4);
	write(1, &_c, 1);
}
