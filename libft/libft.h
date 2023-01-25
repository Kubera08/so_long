/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:07:57 by cmsjus            #+#    #+#             */
/*   Updated: 2023/01/24 16:17:29 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen( char *s);
char	*ft_strncpy(char *str, int nb);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*get_next_line2(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_swap(char *s1, char *s2);
int		ft_content_pos_x(char **map, char c);
int		ft_content_pos_y(char **map, char c);
int		ft_printf(const char *str, ...);
int		ft_printf_s(va_list arg);
int		ft_printf_d(va_list arg);
int		ft_params(char flag, va_list arg);

#endif
