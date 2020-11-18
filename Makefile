# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 11:22:12 by anel-bou          #+#    #+#              #
#    Updated: 2019/10/25 19:23:28 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = biggest_n.o\
	ft_printf.o\
	get_arg_format.o\
	incr.o\
	inval.o\
	my_decilen.o\
	my_putnbr.o\
	print_base.o\
	print_c.o\
	print_d.o\
	print_s.o\
	print_u.o\
	set_for_p.o\
	set_t_arg.o\
	pf_conv.o\
	float/add.o\
	float/calculate_float.o\
	float/mult.o\
	float/pow.o\
	float/print_fl.o\
	float/rounding.o\

LIBFTOBJ = libft/ft_abs.o\
		libft/ft_atoi.o\
		libft/ft_bzero.o\
		libft/ft_clettercount.o\
		libft/ft_cwordcount.o\
		libft/ft_decilen.o\
		libft/ft_del_char.o\
		libft/ft_isalnum.o\
		libft/ft_isalpha.o\
		libft/ft_isascii.o\
		libft/ft_isdigit.o\
		libft/ft_islower.o\
		libft/ft_isprint.o\
		libft/ft_isupper.o\
		libft/ft_iswhitespace.o\
		libft/ft_itoa.o\
		libft/ft_lst_nb_chr.o\
		libft/ft_lst_nb_chr_n_add.o\
		libft/ft_lstadd.o\
		libft/ft_lstadd_end.o\
		libft/ft_lstdel.o\
		libft/ft_lstdelone.o\
		libft/ft_lstiter.o\
		libft/ft_lstmap.o\
		libft/ft_lstnew.o\
		libft/ft_lstsize.o\
		libft/ft_memalloc.o\
		libft/ft_memccpy.o\
		libft/ft_memchr.o\
		libft/ft_memcmp.o\
		libft/ft_memcpy.o\
		libft/ft_memdel.o\
		libft/ft_memmove.o\
		libft/ft_memset.o\
		libft/ft_printstr2.o\
		libft/ft_putchar.o\
		libft/ft_putchar_fd.o\
		libft/ft_putcol.o\
		libft/ft_putendl.o\
		libft/ft_putendl_fd.o\
		libft/ft_putnbr.o\
		libft/ft_putnbr_fd.o\
		libft/ft_putnchar.o\
		libft/ft_putnchar_fd.o\
		libft/ft_putnstr.o\
		libft/ft_putnstr_fd.o\
		libft/ft_putstr.o\
		libft/ft_putstr_fd.o\
		libft/ft_sort_int_tab.o\
		libft/ft_stralloc.o\
		libft/ft_strcat.o\
		libft/ft_strchr.o\
		libft/ft_strclr.o\
		libft/ft_strcmp.o\
		libft/ft_strcpy.o\
		libft/ft_strdel.o\
		libft/ft_strdup.o\
		libft/ft_strequ.o\
		libft/ft_striter.o\
		libft/ft_striteri.o\
		libft/ft_strjoin.o\
		libft/ft_strlcat.o\
		libft/ft_strlen.o\
		libft/ft_strmap.o\
		libft/ft_strmapi.o\
		libft/ft_strncat.o\
		libft/ft_strncmp.o\
		libft/ft_strncpy.o\
		libft/ft_strnequ.o\
		libft/ft_strnew.o\
		libft/ft_strnjoin.o\
		libft/ft_strnstr.o\
		libft/ft_strrchr.o\
		libft/ft_strsplit.o\
		libft/ft_strstock.o\
		libft/ft_strstr.o\
		libft/ft_strsub.o\
		libft/ft_strtrim.o\
		libft/ft_table2_len.o\
		libft/ft_table3_len.o\
		libft/ft_tolower.o\
		libft/ft_toupper.o\

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

all : $(NAME)

$(NAME): $(OBJ) ft_printf.h
		make -C libft/
		ar rc $(NAME) $(OBJ) $(LIBFTOBJ)

%.o : %.c
		gcc $(FLAGS) -c $< -o $@

clean : 
		make clean -C libft/
		rm -rf $(OBJ)


fclean : clean
		make fclean -C libft/
		rm -f $(NAME)

re : fclean all
