
CC = gcc

CFLAGS = -Wall -Werror -Wextra

TARGET = Slist

SRC = main.c \
      file_validation.c \
      hash_function.c \
      insert_last.c \
      create_database.c \
      search.c \
      display_database.c \
      update_database.c \
      save_database.c \
      write_databasefile.c \
      load_database.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c inverted_Search.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all
