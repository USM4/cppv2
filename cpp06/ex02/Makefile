CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = dynamic
GREEN = \033[32m
COLOR_OFF = \033[0m
SOURCES = ./src/main.cpp ./src/Base.cpp  ./src/A.cpp ./src/B.cpp ./src/C.cpp
INCLUDES =  ./includes/Base.hpp ./includes/A.hpp ./includes/B.hpp ./includes/C.hpp
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