# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:48:15 by yfuks             #+#    #+#              #
#    Updated: 2017/11/24 16:07:28 by yfuks            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
				  $(ASMDIR)parse.c \
				  $(ASMDIR)parse_id.c \
				  $(ASMDIR)parse_label.c \
				  $(ASMDIR)check_commentchar.c \
				  $(ASMDIR)check_namechar.c \
				  $(ASMDIR)check_labelschar.c \
				  $(ASMDIR)check_double_label.c \
				  $(ASMDIR)add_instruction.c \
				  $(ASMDIR)parse_instruction.c \
				  $(TOOLSDIR)ft_strrchr.c \
				  $(TOOLSDIR)ft_strlen.c \
				  $(TOOLSDIR)ft_putstr_fd.c \
				  $(TOOLSDIR)ft_memalloc.c \
				  $(TOOLSDIR)ft_bzero.c \
				  $(TOOLSDIR)ft_strnew.c \
				  $(TOOLSDIR)get_next_line.c \
				  $(TOOLSDIR)ft_realloc.c \
				  $(TOOLSDIR)ft_strndup.c \
				  $(TOOLSDIR)ft_strdel.c \
				  $(TOOLSDIR)ft_strcpy.c \
				  $(TOOLSDIR)ft_memdel.c \
				  $(TOOLSDIR)ft_strcat.c \
				  $(TOOLSDIR)ft_strsub.c \
				  $(TOOLSDIR)ft_strcmp.c \
				  $(TOOLSDIR)ft_strdup.c \
				  $(TOOLSDIR)ft_strchr.c \
				  $(TOOLSDIR)ft_strtrim.c \
				  $(TOOLSDIR)ft_split_t_sp.c \
				  $(TOOLSDIR)ft_strncpy.c


SRCSCOREWAR		= $(COREWARDIR)main.c \
				  $(TOOLSDIR)ft_strlen.c \
				  $(TOOLSDIR)ft_putstr_fd.c \
				  $(TOOLSDIR)ft_strcmp.c \
				  $(COREWARDIR)print_usage.c \
				  $(COREWARDIR)parse_arguments.c \
				  $(COREWARDIR)parse_options.c \
				  $(COREWARDIR)parse_champion.c \
				  $(TOOLSDIR)ft_isdigit.c \
				  $(TOOLSDIR)ft_isspace.c \
				  $(TOOLSDIR)ft_atoi.c \
				  $(TOOLSDIR)ft_atol.c \
				  $(COREWARDIR)parse_file.c \
				  $(COREWARDIR)new_champion.c \
				  $(TOOLSDIR)ft_bzero.c \
				  $(TOOLSDIR)ft_strdup.c \
				  $(TOOLSDIR)ft_itoa_base.c \
				  $(TOOLSDIR)ft_putnbr_fd.c \
				  $(TOOLSDIR)ft_itoa.c \
				  $(TOOLSDIR)reverse_uint.c \
				  $(TOOLSDIR)ft_uitoa_base.c \
				  $(TOOLSDIR)ft_ustoa_base.c \
				  $(TOOLSDIR)ft_put_hex.c \
				  $(TOOLSDIR)ft_strcpy.c \
				  $(TOOLSDIR)ft_memcpy.c \
				  $(COREWARDIR)add_champion_in_arena.c \
				  $(COREWARDIR)init_arena.c \
				  $(COREWARDIR)print_champ.c \
				  $(COREWARDIR)print_map_arena.c \
				  $(COREWARDIR)new_process.c \
				  $(COREWARDIR)add_process_to_champion.c \
				  $(COREWARDIR)play.c \
				  $(COREWARDIR)check_process.c \
				  $(COREWARDIR)check_deads.c \
				  $(COREWARDIR)exec_command.c \
				  $(TOOLSDIR)op.c \
				  $(COREWARDIR)check_opcode.c \
				  $(COREWARDIR)cmd_sti.c \
				  $(COREWARDIR)is_valid_param.c \
				  $(COREWARDIR)next_index.c \
				  $(TOOLSDIR)ctos.c \
				  $(TOOLSDIR)ctoi.c \
				  $(COREWARDIR)get_command_arguments.c \
				  $(COREWARDIR)add_to_index.c \
				  $(COREWARDIR)copy_int_to_arena.c \
				  $(TOOLSDIR)ft_uctoa_base.c \
				  $(TOOLSDIR)split_int_in_char.c \
				  $(TOOLSDIR)ft_putendl_fd.c \
				  $(COREWARDIR)cmd_and.c \
				  $(COREWARDIR)cmd_live.c \
				  $(COREWARDIR)cmd_st.c \
				  $(COREWARDIR)cmd_zjmp.c \
				  $(COREWARDIR)cmd_ld.c \
				  $(COREWARDIR)cmd_or.c \
				  $(COREWARDIR)cmd_xor.c \
				  $(COREWARDIR)cmd_lld.c \
				  $(COREWARDIR)cmd_add.c \
				  $(COREWARDIR)cmd_sub.c \
				  $(COREWARDIR)cmd_ldi.c \
				  $(COREWARDIR)get_memory.c \
				  $(COREWARDIR)cmd_aff.c \
				  $(TOOLSDIR)ft_putchar_fd.c \
				  $(COREWARDIR)cmd_lldi.c \

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
