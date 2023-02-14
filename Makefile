DIRSRC = ./srcs/

DIRCINC = ./includes/

DIRLIB = ./libft/

DIRMLX = ./mlx/

SRC =	main \
		get_map \
		check_map \
		free \
		utils00 \
		utils01 \
		utils02 \
		check_path \
		display \
		moves \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = ${SRCS:.c=.o}

NAME = so_long
LFT = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -I . -lXext -lX11

.c.o:
	@${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} -I${DIRMLX} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@cd ${DIRMLX} && ${MAKE}
	@${CC} ${CFLAGS} ${MLX_FLAGS} -o ${NAME} ${OBJS} libft/libft.a mlx/libmlx.a
	@echo "✅ so_long created"

all: ${NAME}

clean:
	@${RM} ${OBJS}
	@cd ${DIRLIB} && ${MAKE} clean
	@echo "🧽 Directory is clean"

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@cd ${DIRLIB} && ${MAKE} fclean
	@echo "🧹 Directory is fclean"

re : fclean all

.PHONY : all clean fclean re

