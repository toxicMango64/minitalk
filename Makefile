# ***************************** SOURCES & STRINGS **************************** #

SERVER	=	server
CLIENT	=	client
BSERVER	=	server_bonus
BCLIENT	=	client_bonus

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

ARCHIVE	=	./libft/libft.a

EXE		=	server \
			client \
			server.dSYM \
			client.dSYM \
			server_bonus \
			client_bonus \
			server_bonus.dSYM \
			client_bonus.dSYM

# ********************************** MESSAGES ********************************* #

cleaning	=	echo "Clean: Removed all the \".o\" files"

fcleaning	=	echo "Full Clean..."

ready		=	echo "minitalk is ready"

bigtalk		=	echo "maxitalk is ready"

# ********************************** RULES ************************************ #

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(ARCHIVE)
	$(CC) $(CFLAGS) $(OBJ) $(ARCHIVE) -o $(NAME)

all:
	$(CC) $(CFLAGS) $(ARCHIVE) server.c -o $(SERVER)
	$(CC) $(CFLAGS) $(ARCHIVE) client.c -o $(CLIENT)
	@echo " _____                                                       _____ ";
	@echo "( ___ )                                                     ( ___ )";
	@echo " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
	@echo " |   |                                                       |   | ";
	@echo " |   |       __ __  _  __  _  _  _____  __   _    _  __      |   | ";
	@echo " |   |      |  V  || ||  \| || ||_   _|/  \ | |  | |/ /      |   | ";
	@echo " |   |      | \_/ || || | ' || |  | | | /\ || |_ |   <       |   | ";
	@echo " |   |      |_| |_||_||_|\__||_|  |_| |_||_||___||_|\_\      |   | ";
	@echo " |   |                                                       |   | ";
	@echo " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
	@echo "(_____)                                                     (_____)";
	@$(ready)

minitalk:
	@$(CC) $(CFLAGS) $(ARCHIVE) server.c -o $(SERVER)
	@$(CC) $(CFLAGS) $(ARCHIVE) client.c -o $(CLIENT)
	@echo " _____                                                       _____ ";
	@echo "( ___ )                                                     ( ___ )";
	@echo " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
	@echo " |   |                                                       |   | ";
	@echo " |   |       __ __  _  __  _  _  _____  __   _    _  __      |   | ";
	@echo " |   |      |  V  || ||  \| || ||_   _|/  \ | |  | |/ /      |   | ";
	@echo " |   |      | \_/ || || | ' || |  | | | /\ || |_ |   <       |   | ";
	@echo " |   |      |_| |_||_||_|\__||_|  |_| |_||_||___||_|\_\      |   | ";
	@echo " |   |                                                       |   | ";
	@echo " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
	@echo "(_____)                                                     (_____)";
	@$(ready)

maxitalk:
	@$(CC) $(CFLAGS) $(ARCHIVE) server_bonus.c -o $(BSERVER)
	@$(CC) $(CFLAGS) $(ARCHIVE) client_bonus.c -o $(BCLIENT)
	@echo " _____                                                       _____ ";
	@echo "( ___ )                                                     ( ___ )";
	@echo " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
	@echo " |   |                                                       |   | ";
	@echo " |   |       __ __  _  __  _  _  _____  __   _    _  __      |   | ";
	@echo " |   |      |  V  || ||  \| || ||_   _|/  \ | |  | |/ /      |   | ";
	@echo " |   |      | \_/ || || | ' || |  | | | /\ || |_ |   <       |   | ";
	@echo " |   |      |_| |_||_||_|\__||_|  |_| |_||_||___||_|\_\      |   | ";
	@echo " |   |                                                       |   | ";
	@echo " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
	@echo "(_____)                                                     (_____)";
	@$(bigtalk)

clean:
	@$(cleaning)

fclean: clean
	@rm -fr $(SERVER) $(CLIENT)
	@$(RM) -fr $(EXE)
	@$(fcleaning)

re: fclean all

.PHONY: all clean fclean re maxitalk minitalk
