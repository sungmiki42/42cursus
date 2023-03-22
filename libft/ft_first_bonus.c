/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:58:33 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/22 17:29:28 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0)
	{
		errno = EINVAL;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	count;
	
	count = 0;
	while (lst && 0 <= count++)
		lst = lst->next;
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
	{
		errno = EINVAL;
		return ;
	}
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
