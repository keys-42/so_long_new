NAME 		=	so_long
CC			=	cc
# CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined
# CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ./include/

GNLDIR		=	get_next_line
GNLNAME		=	$(GNLDIR)/gnl.a
GNL			=	$(GNLNAME)

FTDIR		=	libft
FTNAME		=	$(FTDIR)/libft.a
FT			=	$(FTNAME)

SRCS		= 	srcs/main.c					\
				srcs/checks/check.c			\
				srcs/checks/check_wall.c	\
				srcs/checks/check_player.c	\
				srcs/checks/check_square.c	\
				srcs/checks/check_exit.c	\
				srcs/checks/check_collectible.c	\
				srcs/checks/check_useless_characters.c	\
				srcs/checks/check_can_finish.c	\
				srcs/utils/get_struct.c 	\
				srcs/utils/free.c 			\
				srcs/utils/utils.c 			\
				srcs/make/make_map.c


OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME):$(OBJS) $(GNL) $(FT)
		$(CC) $(INCLUDE) -o $(NAME) $^ $(CFLAGS)

$(GNL):
		$(MAKE) --no-print-directory -C $(GNLDIR)

$(FT):
		$(MAKE) --no-print-directory -C $(FTDIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<



clean:
		$(MAKE) --no-print-directory clean -C $(GNLDIR)
		$(MAKE) --no-print-directory clean -C $(FTDIR)
		$(RM) -r $(OBJDIR)

fclean: clean
		$(MAKE) --no-print-directory fclean -C $(GNLDIR)
		$(MAKE) --no-print-directory fclean -C $(FTDIR)
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re gnl libft
