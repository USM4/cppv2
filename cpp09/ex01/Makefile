CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN
GREEN = \033[32m
COLOR_OFF = \033[0m
SOURCES = ./src/main.cpp ./src/RPN.cpp
INCLUDES =  ./includes/RPN.hpp
OBJECTS = $(SOURCES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o : %.cpp $(INCLUDES)
	@printf "${GREEN}Compiling $<... ${COLOR_OFF}\r"
	@$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	@rm -f $(OBJECTS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: fclean clean re all