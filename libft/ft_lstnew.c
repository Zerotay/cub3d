/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:26:16 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/23 12:28:35 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*s;

	if (!(s = (t_list *)malloc(sizeof(t_list))))
		return (0);
	s->content = content;
	s->next = 0;
	s->prev = 0;
	return (s);
}
