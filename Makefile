CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/main.c src/interfaces.c src/sockets.c
OBJ = $(SRC:.c=.o)
TARGET = bin/dnsman

all: bin $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)