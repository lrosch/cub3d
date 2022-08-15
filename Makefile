CC	=	gcc

NAME =	cub3D

FLAGS =	-Wall -Wextra -Werror

MLX	=	-Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC	=	cub3d.c rgb.c get_ceil_flo.c get_walls.c utils.c \
		free.c cast_rays_wip_stuff.c parsing.c map_validation.c get_colours.c \
		rotate_orientation.c movement_events.c get_player_info.c \
		initialize_images.c	tex_img_put.c create_frame.c ray_examination.c \
		exit.c

OBJECTS:=  $(SRC:c=o)

$(NAME): $(OBJECTS) | silence
	@make -C ./libftp
	@cp libftp/libftp.a libftp.a
	@$(CC) $^ $(CFLAGS) -L. -lftp $(MLX) -o $@
	@printf "\n		successfully compiled \n\n"

%.o: %.c
	$(CC) $(RDINC) $< -c $(CFLAGS) -o $@

all: $(NAME)

silence:
	@:

clean:
	@find . -type f -name '*.o' -delete
	@make -C ./libftp clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libftp.a
	@make -C ./libftp fclean

re: fclean
	@make -C ./libftp fclean
	@make all

.PHONY: clean fclean re