# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 13:12:27 by maaugust          #+#    #+#              #
#    Updated: 2026/02/16 22:27:00 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE LIBFTS ============================ #
LIBFT             = libft.a

# ============================== COMPILER FLAGS ============================== #
CC                = cc
CFLAGS            = -Wall -Wextra -Werror
INCLUDES          = -I.
AR                = ar rcs
RM                = rm -f

# ================================== COLORS ================================== #
GREEN             := \033[32m
RED               := \033[31m
YELLOW            := \033[33m
CYAN              := \033[36m
RESET             := \033[0m
BOLD              := \033[1m

# =============================== SOURCE FILES =============================== #
# Mandatory files
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Bonus files
B_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
         ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
         ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Object files
OBJS              = $(SRCS:.c=.o)
B_OBJS            = $(B_SRCS:.c=.o)

# ============================ COMPILATION RULES ============================= #
%.o: %.c
	@printf "$(CYAN)Compiling libft:$(RESET) $(YELLOW)$<$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ============================== BUILD TARGETS =============================== #
all: $(LIBFT)

$(LIBFT): $(OBJS)
	@printf "$(GREEN)✔ Libft mandatory objects built successfully.$(RESET)\n"
	@$(AR) $(LIBFT) $(OBJS)
	@printf "$(GREEN)$(BOLD)✔ Library created → $(LIBFT)$(RESET)\n"

bonus: .bonus

.bonus: $(OBJS) $(B_OBJS)
	@printf "$(GREEN)✔ Libft bonus objects built successfully.$(RESET)\n"
	@$(AR) $(LIBFT) $(OBJS) $(B_OBJS)
	@printf "$(GREEN)$(BOLD)✔ Library created with bonuses → $(LIBFT)$(RESET)\n"
	@touch .bonus

# ============================== CLEAN TARGETS =============================== #
clean:
	@$(RM) $(OBJS) $(B_OBJS) .bonus
	@printf "$(YELLOW)• Cleaned libft object files.$(RESET)\n"

fclean: clean
	@$(RM) $(LIBFT)
	@printf "$(RED)• Libft full clean complete.$(RESET)\n"

re: fclean all

# ============================== PHONY TARGETS =============================== #
.PHONY: all clean fclean re bonus
