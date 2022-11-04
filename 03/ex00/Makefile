NAME		=	claptrap

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g -Werror=implicit-fallthrough=0

# directories
SRC_DIR		=	./
OBJ_DIR		=	obj/
INC_DIR		=	include/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#source files
SRC_FILES	=	main.cpp ClapTrap.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: eclown $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@rm -rf $(OBJ_DIR);

#fclean rule
fclean: clean
	@rm -f $(NAME);

#re rule
re: fclean all

eclown:
	@printf "             _\n"
	@printf "    ___  ___| | _____      ___ __ \n"
	@printf "   / _ \/ __| |/ _ \ \ /\ / / '_ \ \n"
	@printf "  |  __/ (__| | (_) \ V  V /| | | | \n"
	@printf "   \___|\___|_|\___/ \_/\_/ |_| |_| \n"
	@printf "                                        \n"
	@printf "          _                 _   ____  _\n"
	@printf " ___  ___| |__   ___   ___ | | |___ \/ |\n"
	@printf "/ __|/ __| '_ \ / _ \ / _ \| |   __) | |\n"
	@printf "\__ \ (__| | | | (_) | (_) | |  / __/| |\n"
	@printf "|___/\___|_| |_|\___/ \___/|_| |_____|_|\n"
	@printf "\n"

#phony
.PHONY: all clean fclean re eclown