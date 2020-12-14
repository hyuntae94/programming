/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 01:01:03 by hyunkim           #+#    #+#             */
/*   Updated: 2020/11/27 01:01:03 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->flag = 0;
	info->width = 0;
	info->prec = 0;
	info->point_zero = 0;
	info->ret = 0;
}

const char	*read_info(va_list ap, const char *form, int *ret)
{
	t_info *info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);//할당되지않는다면 NULL반환
	init_info(info);
	form = read_flag(form, info);
	form = read_width(form, info, ap);
	if (*form == '.')
		form = read_prec(form, info, ap);
	form = print_form_spec(form, info, ap);
	*ret += info->ret;
	free(info);
	info = NULL;
	return (form);
}

int			parse(va_list ap, const char *form)
{
	int		ret;

	ret = 0;
	while (*form)//form이 존재하지않으면 0반환
	{
		if (*form == '%')//%가 아니면 else if
		{
			form++;
			if (!(form = read_info(ap, form, &ret)))
			//read_info반환값이 NULL이라면 return (0)실행
				return (0);
		}
		else if (*form != '%')
		{
			ret++;
			write(1, form, 1);
		}
		form++;
	}
	return (ret);
}

int			ft_printf(const char *form, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, form);
	ret = parse(ap, form);
	va_end(ap);
	return (ret);
}