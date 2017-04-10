.PHONY: all clean fclean re

CC = clang++
CFLAGS = -Werror -Wall -Wextra

FILES = \
		main.cpp			\
		Game.cpp			\
		Spaceship.cpp		\
		AEntity.cpp			\
		Projectil.cpp		\
		Boss.cpp		\
		
OFILES = $(FILES:.cpp=.o)

NAME = ft_retro


all: $(NAME)


%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@  $<

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME) -lncurses



clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
