NAME:= libftp.a

CFLAGS?= -Wall -Werror -Wextra

${NAME}: | silence
	@make -C ./libft
	@ar rc ${NAME} libft/*.o
	@make -C ./gnl
	@ar rc ${NAME} gnl/*.o

all: $(NAME)

silence:
	@:

clean:
	@make -C ./libft clean
	@make -C ./gnl clean

fclean: clean
	@rm -f ${NAME}
	@make -C ./libft fclean
	@make -C ./gnl fclean

re: fclean
	@make -C ./libft fclean
	@make -C ./gnl fclean
	@make all

.PHONY: clean fclean re