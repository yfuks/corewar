#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:48:15 by yfuks             #+#    #+#              #
#    Updated: 2017/11/13 13:45:26 by alansiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# EXECUTABLES
NAME_ASM 		= asm
NAME_COREWAR 	= corewar

# COMPILATION
CC				= clang
FLAGS			= -Wall -Wextra -Werror -g3

# DIRECTORYS
SRCDIR			= src/
INCDIR			= inc/
OBJDIR			= obj/
ASMDIR			= $(SRCDIR)asm/
COREWARDIR		= $(SRCDIR)corewar/
TOOLSDIR		= $(SRCDIR)tools/

# FILES
SRCSASM			= $(ASMDIR)main.c \
				  $(ASMDIR)error_stdin.c \
				  $(TOOLSDIR)ft_strrchr.c \
				  $(TOOLSDIR)ft_strlen.c \
				  $(TOOLSDIR)ft_putstr_fd.c \

SRCSCOREWAR		= $(COREWARDIR)main.c \
				  $(TOOLSDIR)ft_strlen.c \
				  $(TOOLSDIR)ft_putstr_fd.c \
# OBJ FILES
OBJSASM 		= $(SRCSASM:$(SRCDIR)%.c=$(OBJDIR)%.o)
OBJSCOREWAR 	= $(SRCSCOREWAR:$(SRCDIR)%.c=$(OBJDIR)%.o)

# INC FILES 
INC 			= -I./$(INCDIR)

# =================================== Colors ================================= #

CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"

# ============================================================================ #

.PHONY: all clean fclean re
.SILENT:

all: check $(NAME_ASM) $(NAME_COREWAR)

$(OBJDIR)%.o : $(SRCDIR)%.c 
	$(CC) $(FLAGS) -c $< -o $@ $(INC)
	echo "["$(PURPLE)"√"$(EOC)"]" $@

check:
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)asm || mkdir $(OBJDIR)asm
	test -d $(OBJDIR)corewar || mkdir $(OBJDIR)corewar
	test -d $(OBJDIR)tools || mkdir $(OBJDIR)tools	

$(NAME_ASM): $(OBJSASM)
	$(CC) $(FLAGS) -o $(NAME_ASM) $(OBJSASM) $(INC)
	printf $(GREEN)"➪ $@ compiled!\n"$(EOC)

$(NAME_COREWAR): $(OBJSCOREWAR)
	$(CC) $(FLAGS) -o $(NAME_COREWAR) $(OBJSCOREWAR) $(INC)
	printf $(GREEN)"➪ $@ compiled!\n"$(EOC)

clean:
	rm -rf $(OBJDIR)
	printf $(YELLOW)"♲ Objects files deleted\n"$(EOC)

fclean: clean
	rm -rf $(NAME_ASM) 
	rm -rf $(NAME_COREWAR)
	printf $(YELLOW)"♲ Exec $(NAME_ASM) and $(NAME_COREWAR) deleted\n"$(EOC)

re: fclean 
	@$(MAKE) all	

