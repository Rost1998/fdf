# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 18:49:17 by rtulchiy          #+#    #+#              #
#    Updated: 2018/02/28 21:05:27 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJSRC = main.c connect_pixs.c fill_struct.c ft_exit.c ft_handle_keys.c\
		 ft_new_node.c memfree.c parser.c upgrade_pixs.c validator.c\
		 get_next_line.c

OBJC = $(OBJSRC:%.c=srcs/%.c)
OBJO = $(OBJSRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft
MLXDIR = minilibX

%.o: srcs/%.c
	gcc $(CFLAGS) -c $< -I includes

all: $(NAME)

$(NAME): $(OBJO)
	make -C $(LIBDIR)
	make -C $(MLXDIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJO) -L./$(LIBDIR) -lft -L./$(MLXDIR) -lmlx\
							-framework OpenGL -framework AppKit -I includes

clean:
	make clean -C $(LIBDIR)
	make clean -C $(MLXDIR)
	rm -f $(OBJO)

fclean: clean
	make fclean -C $(LIBDIR)
	make fclean -C $(MLXDIR)
	rm -f $(NAME)

re: fclean all
