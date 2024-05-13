CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

$(NAME): $(NAME).cpp
	@printf "$(CURSIVE)$(GRAY)Compiling $(NAME)... $(RESET)\n"
	$(CC) $(FLAGS) $(NAME).cpp -o $(NAME)
	@printf "$(GREEN)Compiled $(NAME)!$(RESET)\n"

all: $(NAME)

clean:
	@printf "$(GRAY)Nothing to clean!$(RESET)\n"

fclean:
	@rm $(NAME)
	@printf "$(YELLOW)Executable removed!$(RESET)\n"

re: fclean all