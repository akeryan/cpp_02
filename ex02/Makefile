# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 14:39:51 by akeryan           #+#    #+#              #
#    Updated: 2024/05/04 14:39:54 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec 

FLAGS =  -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf

SRC_FILES = main.cpp	\
			Fixed.cpp	

INCLUDE_FILES = Fixed.hpp	

OBJ = $(patsubst %.cpp, %.o, $(SRC_FILES))

%.o: %.cpp $(INCLUDE_FILES) 
	$(CC) $(FLAGS) -o $@ -c $<  

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
