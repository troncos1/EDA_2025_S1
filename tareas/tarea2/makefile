CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BIN = tarea2
SRCS = main.c modules/processor.c modules/sorter.c modules/validator.c
OBJS = $(SRCS:.c=.o)
HEADERS = modules/processor.h modules/sorter.h modules/validator.h

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c

modules/processor.o: modules/processor.c modules/processor.h modules/validator.h
	$(CC) $(CFLAGS) -c modules/processor.c -o modules/processor.o

modules/validator.o: modules/validator.c modules/validator.h modules/processor.h
	$(CC) $(CFLAGS) -c modules/validator.c -o modules/validator.o

modules/sorter.o: modules/sorter.c modules/sorter.h modules/processor.h
	$(CC) $(CFLAGS) -c modules/sorter.c -o modules/sorter.o

clean:
	rm -f $(BIN) $(OBJS)

.PHONY: all clean