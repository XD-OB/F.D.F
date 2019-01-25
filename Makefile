# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:55:40 by obelouch          #+#    #+#              #
#    Updated: 2018/12/20 00:48:22 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft/libft.a

SRC = src/*.c

LIBFT_SRC = libft/*.c

LIBFT_OBJ = *.o

LIBFT_H = libft/libft.h

HEAD = include/fdf.h

OBJ = *.o

LIB = -L ./mlx -lmlx -L ./libft -lft 

FRAME = -framework OpenGL -framework Appkit

FLAG = -Wall -Wextra -Werror

all: $(LIB_NAME) $(NAME)

$(LIBFT): $(LIBFT_H)
	@cc -c $(FLAG)	$(LIBFT_SRC)
	@ar rc $(LIBFT) $(LIBFT_OBJ)
	@ranlib $(LIBFT)

$(NAME): $(HEAD) $(LIBFT)
	@cc -c -I mlx/ -I include/ $(SRC)
	@cc $(OBJ) $(FRAME) $(FLAG) $(LIB) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	@/bin/rm -f $(NAME) $(LIBFT)

re: fclean all
