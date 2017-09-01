/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:06:15 by gsferopo          #+#    #+#             */
/*   Updated: 2017/07/17 16:14:53 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define BUFF_SIZE 32

typedef	struct	s_buff_info
{
	size_t		fd;
	size_t		index;
	char		buff[BUFF_SIZE + 1];
}				t_buff_info;

#endif
