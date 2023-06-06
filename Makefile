NAME		=	FdF
LIBFT		=	libft/
MLX			=	mlx_linux/minilibx-linux/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	gcc
INCLUDE 	=	inclue
RM			=	rm -f
SRCS		=	fdf.c \
				map.c \
				utils.c \

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(MLX_A)
				@$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -lz -lX11 -lXext -L$(LIBFT) -lft -L$(MLX) -lm -o $(NAME)
				@echo "Linked into executable \033[0;32mfdf\033[0m."

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)
				@echo "Compiled $(LIBFT_A)."

# $(GNL_A):
# 				@$(MAKE) -s -C $(GNL)
# 				@echo "Compiled $(GNL_A)."

$(MLX_A):
				@$(MAKE) -s -C $(MLX)
				@echo "Compiled $(MLX_A)."



localclean:
				@$(RM) $(OBJS)
				@echo "Removed object files."

clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT)
				@echo "Clean libft."
				# 
				@$(MAKE) clean -s -C $(MLX)
				@echo "Clean mlx."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(MAKE) clean -s -C $(MLX)
				@echo "Clean mlx."
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus


# @$(MAKE) clean -s -C $(GNL)
# 				# @echo "Clean gnl."
