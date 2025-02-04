# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 03:49:03 by ynyamets          #+#    #+#              #
#    Updated: 2025/02/04 04:16:03 by ynyamets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c
SRC_SERVER_BONUS = server_bonus.c utils_bonus.c
SRC_CLIENT_BONUS = client_bonus.c utils_bonus.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

# Règle principale : compiler le serveur et le client
all: server client

# Règle de compilation du serveur
server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

# Règle de compilation du client
client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour la partie bonus du serveur
server_bonus: $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour la partie bonus du client
client_bonus: $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

# Suppression des fichiers objets générés
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

# Suppression des fichiers objets et des exécutables
fclean: clean
	rm -f server client server_bonus client_bonus

# Règle pour nettoyer et recompiler tout
re: fclean all

# Règle pour compiler la partie bonus
bonus: $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o server_bonus $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -o client_bonus $(OBJ_CLIENT_BONUS)

