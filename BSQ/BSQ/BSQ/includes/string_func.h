/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:58:16 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 20:59:22 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_FUNC_H
# define STRING_FUNC_H

# include <unistd.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_strncpy(char *dest, char *src, int num);
void	print_err_msg(void);
void	ft_putchar(char c);

#endif
