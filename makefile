# MAKE DE TP1
OBJS =  main.c strutil.c pruebas_alumno_tp1.c testing.c
EXEC = pruebas
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror
VALGRIND = valgrind --leak-check=full --track-origins=yes --show-reachable=yes

all: main
	
main: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) *.c
	./$(EXEC)
	#$(VALGRIND) ./$(EXEC)

clean:
	rm -f $(EXEC)

.PHONY: clean main