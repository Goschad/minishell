NAME =	minishell

CC	 =	@gcc

FLAGS = -Wall -Werror -Wextra

SRCS = 	main.c \
		include/global_var.c \
		builtin/env.c \
		builtin/echo.c \
		builtin/pwd.c \
		builtin/exit.c \
		builtin/ft_cd.c \
		builtin/export.c \
		builtin/unset.c \
		utils/path.c \
		utils/basic_utils.c \
		utils/basic_utils2.c \
		utils/basic_check.c \
		utils/basic_check2.c \
		utils/print_type.c \
		utils/init_struct.c \
		utils/copy.c \
		utils/free.c \
		utils/ft_split.c \
		utils/ft_itoa.c \
		utils/cut_cmd_utils.c \
		utils/conversion_utils.c \
		utils/heredoc_utils.c \
		utils/redir_utils.c \
		utils/check_redir.c \
		utils/env_utils.c \
		utils/status.c \
		utils/shlvl.c \
		utils/env_var.c \
		launch/launch_shell.c \
		history/history.c \
		parsing/quotes.c \
		parsing/parse_bull.c \
		parsing/parse.c \
		parsing/remake_line.c \
		parsing/spaces_maker.c \
		parsing/cut_cmd.c \
		parsing/conversion.c \
		signal/signal.c \
		exec/execve.c \
		exec/execute_pipe.c \
		exec/redir.c \
		exec/heredoc.c \
		bonus/find_type.c \
		bonus/utils.c \
		bonus/wildcard.c \
		bonus/first_type.c \
		bonus/seconde_type.c \
		bonus/third_type.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

# utils/errors.c \

READ_LIB = -lreadline -L/Users/$$USER/.brew/opt/readline/lib

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(READ_LIB) -o $(NAME)
	@/bin/echo -n "minishell download "
	@for i in 1 2 3 4 5 6 7 8 9 10; \
    do \
       /bin/echo -n =;  \
	   sleep 0.1; \
    done;
	@sleep 0.1;
	@/bin/echo -n ">"
	@/bin/echo " success download 🥳"
	@/bin/echo "minishell made by mbouaza && jguerin"

clear:
	@rm -rf history/.shellHistory
	@rm -rf .heredoc

clean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@/bin/echo -n "clean "
	@for i in 1 2 3 4 5 6 7 8 9 10;   \
    do \
       /bin/echo -n =;  \
	   sleep 0.05; \
    done;
	@/bin/echo "> success 🥳"

fclean: clean clear
	@rm -rf $(NAME)
	@/bin/echo -n "fclean "
	@for i in 1 2 3 4 5 6 7 8 9 10;   \
    do \
       /bin/echo -n =;  \
	   sleep 0.05; \
    done;
	@/bin/echo "> success 🥳"

re: fclean all

# don't go further ... 

pikapika:
	@/bin/echo -n "p"
	@sleep 0.1
	@/bin/echo -n "i"
	@sleep 0.1
	@/bin/echo -n "k"
	@sleep 0.1
	@/bin/echo -n "a"
	@sleep 0.1
	@/bin/echo -n "c"
	@sleep 0.1
	@/bin/echo -n "h"
	@sleep 0.1
	@/bin/echo -n "u"
	@sleep 0.1
	@/bin/echo -n " i"
	@sleep 0.1
	@/bin/echo -n "s"
	@sleep 0.1
	@/bin/echo -n "n"
	@sleep 0.1
	@/bin/echo -n "'t"
	@sleep 0.1
	@/bin/echo -n " t"
	@sleep 0.1 
	@/bin/echo -n "h"
	@sleep 0.1
	@/bin/echo -n "e"
	@sleep 0.1
	@/bin/echo -n " s"
	@sleep 0.1
	@/bin/echo -n "a"
	@sleep 0.1
	@/bin/echo -n "m"
	@sleep 0.1
	@/bin/echo -n "e"
	@sleep 0.1 
	@/bin/echo -n " p"
	@sleep 0.1
	@/bin/echo -n "e"
	@sleep 0.1
	@/bin/echo -n "r"
	@sleep 0.1
	@/bin/echo -n "s"
	@sleep 0.1
	@/bin/echo -n "o"
	@sleep 0.1
	@/bin/echo "n"
	@sleep 0.1

caca:
	@/bin/echo -n "e"
	@sleep 0.1
	@/bin/echo -n "n"
	@sleep 0.1
	@/bin/echo -n "g"
	@sleep 0.1
	@/bin/echo -n "e"
	@sleep 0.1
	@/bin/echo -n "a"
	@sleep 0.1
	@/bin/echo -n "n"
	@sleep 0.1
	@/bin/echo -n "c"
	@sleep 0.1
	@/bin/echo -n "e"
	@sleep 0.1
	@/bin/echo -n " c"
	@sleep 0.1
	@/bin/echo -n "a"
	@sleep 0.1
	@/bin/echo -n "c"
	@sleep 0.1
	@/bin/echo -n "a"
	@sleep 0.1 
	@/bin/echo -n " e"
	@sleep 0.1
	@/bin/echo "z"
	@sleep 0.1
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢴⣄⡀⠀⠀⠀⠀⠀⠀⠀⢈⣧⣷⡤⠄⠀⠀⠀⠀⠀⠀⢠⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⣽⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣷⡀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠰⠤⣶⡷⢢⡀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⡅⠀⠀⠀⢀⣴⡿⠟⠛⠋⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢹⡇⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠉⠉⠁⠀⠀⠀⠈⣿⣧⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡿⠋⠀⠀⠀⠀⢹⣿⠁⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⢀⣼⡇⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠘⣿⣆⠀⠀⠀⠀⠀⠀⣴⣿⠏⠀⠀⣰⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠘⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢿⡄⠂⠀⠀⠀⠀⢈⣿⡇⠀⠀⠀⠀⠸⣿⡀⠀⠀⠸⣿⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⣀⠞⠀⠀⠀⠀⠸⣿⠀⠀⠀⠀⠀⠀⠀⠑⣄⡀⠀⠀⠀⠀⢻⠀⠀⠀⠀⢴⡟⠋⠀⠀⠀⠀⠀⠀⠹⣿⣜⠁⠀⠙⠷⣄⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠈⣿⠀⠀⠀⠀⠀⣸⡟⠀⠀⠀⠀⠀⠀⠀⠀⢠⣉⡀⠀⠐⠒⠚⠁⠠⠄⠀⢸⣦⠄⠀⠀⠐⠀⠀⠀⠀⠈⢿⡆⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⢠⡿⠀⠀⠀⢀⣼⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠉⣿⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⡄⠀⠀⠀⠀⠀⠀⢀⣴⡟⠁⠀⠀⠀⠀⠀⢀⣀⣀⣦⠀⠀⡄"
	@/bin/echo "⠀⠀⠀⠀⢀⡟⠁⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⠏⠀⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⠀⠀⠀⠀⠀⣴⡟⠁⠀⠀⠀⠀⠀⠀⠀⠘⠶⠖⠛⠈⠉⠀"
	@/bin/echo "⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⣹⠀⠀⠀⠀⠀⠀⢀⣤⡾⠟⠁⠀⠀⠈⠻⢶⣤⣀⣀⠀⠀⠀⠊⠁⠀⠀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠸⡀⠀⠀⠀⠀⠸⡇⠀⠀⠀⠀⢀⣿⠋⠀⠀⠀⠀⢄⣰⠲⡤⡀⠌⠛⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⢸⡏⠐⡂⠐⠀⠀⠀⠈⠙⠒⠲⠤⠤⠾⠟⠛⢻⢷⣦⣀⠀⠀⠀⠀⠀⠀⠈⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣷⡀⠃⠀⠀⡄⠀⠀⠀⠀⢤⠂⠀⠐⠀⢧⡈⠀⢯⡻⣷⡀⠀⠀⠀⠀⠀⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣽⣷⣄⠀⠀⠃⠳⠸⡄⠄⠀⠀⠀⠀⠀⢀⣀⢀⠀⣅⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡾⠟⠉⠀⣨⠙⠛⠶⠤⣀⣀⠀⠀⠀⠀⠰⠤⢣⢸⡘⣌⡆⠘⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⣫⡀⠀⢠⠖⡇⠀⠀⡀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠠⠤⣅⣈⣠⣴⢾⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠑⣿⣡⠤⡏⣠⢯⠀⠊⠁⡀⠀⠀⠀⠀⠈⠉⡟⠛⠐⠰⠀⠀⠇⢷⡀⠟⠛⠻⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣼⡵⠃⢰⠃⢀⡞⢠⠀⠀⠇⠀⠀⠀⠀⣰⠶⠃⠀⠀⠀⠀⠀⠀⠀⠹⣄⠀⢄⠲⠙⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⡿⠟⠉⠀⠀⠁⠀⠈⠀⠈⠀⢠⡶⣆⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡆⠸⣤⡘⠈⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⣠⣾⠟⣥⢰⠆⢠⣄⠀⠀⠀⢀⡀⠀⠀⠘⠁⠙⠀⠀⠁⠀⠀⠀⠀⠀⢀⠀⢤⠘⡆⠸⣄⢳⠀⣇⣹⣶⣿⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⣰⣿⠃⠰⠃⠚⠀⠈⠁⠽⠄⠀⠀⠉⠙⠒⠦⠤⣄⣀⣀⣀⣀⣀⣀⣀⢀⣘⣂⣘⣃⣷⣤⣽⡾⠿⠟⠛⣉⢈⠙⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⢀⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠈⣍⣉⢉⠉⠛⠛⠛⠛⠋⠉⠉⠉⠀⠀⠀⠀⠀⠹⡌⠂⠁⢻⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⢸⣿⠀⢷⣆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢠⠀⠀⠀⠀⠀⠀⠈⠛⠎⠃⠀⠀⠀⠀⢠⠀⣄⠀⡦⠀⢰⠀⠀⡀⢀⠰⡶⡄⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠸⣿⡀⠘⢸⢹⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠄⠀⠀⠀⠀⢠⡀⣤⢰⡆⣸⠀⣿⠀⠷⠀⠈⡀⣌⢿⠈⡇⠇⠁⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠻⣷⡄⠘⠼⢸⠁⡇⢰⠀⡄⠀⠀⠀⡴⠀⠀⠰⠃⠀⠀⠀⠀⠀⠀⠟⠓⠺⠃⢙⠀⢁⡀⣤⢇⠀⢣⢸⡸⡆⠟⢀⣼⡿⠁⡴⠀⣄⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⢀⣠⣿⣿⣄⠀⡄⣤⡀⠈⡄⢀⡀⠀⠀⠃⠸⠰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠘⠂⠛⠸⠄⠘⠋⠁⣠⣤⣾⠟⢡⠞⢁⡴⠋⢰⡄⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠶⣫⠵⠋⣩⢿⣷⣝⣁⡇⢀⠇⢸⠀⡆⢠⡀⢰⠀⡀⠀⠀⠀⢠⡀⡄⣦⠠⡄⠒⠒⠀⠀⠀⠀⠀⢀⣠⣤⣶⡿⢟⡿⢁⡴⠋⣠⠞⠁⣠⠞⠁⠀⠀⠀"
	@/bin/echo "⠀⠀⠐⣋⣡⠖⠋⠁⣠⠼⠛⠿⢿⣶⣶⣬⣄⣃⣈⣀⣈⣀⠀⠀⠀⠀⠀⢀⣈⣙⣀⣀⣀⣤⣤⣶⣶⣾⠿⠿⢛⡿⠁⡴⠋⣠⠎⢀⡾⠃⢀⣴⠃⠀⠴⠀⠀⠀"
	@/bin/echo "⠀⠀⠰⠋⠀⢠⠴⠋⠁⠀⣀⡴⠋⠁⣨⠟⠉⣻⠿⠛⣻⠟⠛⣿⠿⠟⢻⠟⠛⢛⡿⠛⣻⠟⠉⠀⣰⠃⢀⡼⠋⠀⠘⠁⠼⠃⠠⠏⠀⠀⠘⠁⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣀⠀⠚⠁⠀⠐⠃⠀⠐⠁⠀⠀⠁⠀⠀⠀⠀⠀⠁⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"

rick:
	@/bin/echo "https://www.youtube.com/watch?v=xvFZjo5PgG0"

parrot:
	curl parrot.live

surprise:
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⢀⠀⠔⡀⠀⢀⠞⢰⠂⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⠀⠀⢸⠘⢰⡃⠔⠩⠤⠦⠤⢀⡀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⢀⠄⢒⠒⠺⠆⠈⠀⠀⢐⣂⠤⠄⡀⠯⠕⣒⣒⡀⠀"
	@/bin/echo "⠀⠀⢐⡡⠔⠁⠆⠀⠀⠀⠀⠀⢀⠠⠙⢆⠀⠈⢁⠋⠥⣀⣀"
	@/bin/echo "⠈⠉⠀⣰⠀⠀⠀⠀⡀⠀⢰⣆⢠⠠⢡⡀⢂⣗⣖⢝⡎⠉⠀"
	@/bin/echo "⢠⡴⠛⡇⠀⠐⠀⡄⣡⢇⠸⢸⢸⡇⠂⡝⠌⢷⢫⢮⡜⡀⠀"
	@/bin/echo "⠀⠀⢰⣜⠘⡀⢡⠰⠳⣎⢂⣟⡎⠘⣬⡕⣈⣼⠢⠹⡟⠇⠀"
	@/bin/echo "⠀⠠⢋⢿⢳⢼⣄⣆⣦⣱⣿⣿⣿⣷⠬⣿⣿⣿⣿⠑⠵⠀⠀"
	@/bin/echo "⠀⠀⡜⢩⣯⢝⡀⠁⠀⠙⠛⠛⠃⠀⠈⠛⠛⡿⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⠀⣿⠢⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⢀⣀⡇⠀⠑⠀⠀⠀⠀⠐⢄⠄⢀⡼⠃⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⢸⣿⣷⣤⣀⠈⠲⡤⣀⣀⠀⡰⠋⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣶⣤⣙⣷⣅⡀⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⠀⢀⣾⣿⣿⣿⣿⣻⢿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀"
	@/bin/echo "⠀⡠⠟⠁⠙⠟⠛⠛⢿⣿⣾⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀"
