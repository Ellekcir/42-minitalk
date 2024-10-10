# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Client/Server programs 
# One acts like a **client** (the one sending messages), and the other acts like a **server** (the one receiving and printing messages).
SERVER = server
CLIENT = client

# Source files for both the server and client
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Object files generated from the source files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# The libft library
LIBFT = libft.a
LIBFT_DIR = libft

# The build everything
all: $(SERVER) $(CLIENT)

# Compiling the server program
$(SERVER): $(LIBFT) $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)
	@echo "Server created"

# Compiling the client program
$(CLIENT): $(LIBFT) $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)
	@echo "Client created"

# Building libft (if it doesn't exist)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.h .
	@mv $(LIBFT_DIR)/libft.a .

# Convert .c files into .o object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Removes object files, library, and headers
clean:
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ) libft.h $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Everything is clean"

# Full clean rule - also removes the executables
fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Project is entirely cleaned up."

# Completely rebuilding the project
re: fclean all
	@echo "Cleaning & Rebuilding..."

# Phony targets always get declared so they don’t conflict with actual files
.PHONY: all clean fclean re
