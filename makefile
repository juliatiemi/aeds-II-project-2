CC = gcc
CFLAGS = -g -Wall
OBJ = main.o TAD.o PILHA.o
DEPS = TAD.h PILHA.h
EXEC = ./exec labirinto.txt caminho_espada.txt alg
FLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes

all: exec

exec: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clear:
	rm -f exec *.o

teste:
	$(EXEC)

val:
	valgrind $(FLAGS) $(EXEC)
