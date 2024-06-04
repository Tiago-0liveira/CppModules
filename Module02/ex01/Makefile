NAME = fixed
C = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJ_DIR = obj

INCLUDES = -I.

SRC_FILES = main.cpp Fixed.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@echo "Compiling $@..."
	@$(C) $(FLAGS) -o $@ $^ $(INCLUDES)
	@echo "Ready!"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	@$(C) $(FLAGS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned $(NAME) and object directory."

re: fclean all

.PHONY: all clean fclean re