/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitesp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:04:45 by avishnev          #+#    #+#             */
/*   Updated: 2017/11/06 15:04:48 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitesp(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\r' || c == '\f'));
}
