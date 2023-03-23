/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:42:04 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/23 12:15:45 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;
	void	*cont_tmp;

	head = 0;
	while (lst)
	{
		cont_tmp = f(lst->content);
		tmp = ft_lstnew(cont_tmp);
		if (tmp == 0)
		{
			free(cont_tmp);
			ft_lstclear(&head, del);
			return (0);
		}
		if (head)
			tail->next = tmp;
		else
			head = tmp;
		tail = tmp;
		lst = lst->next;
	}
	return (head);
}
