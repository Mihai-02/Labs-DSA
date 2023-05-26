CC = gcc
EXEC = ex2
SIZE = 15

build: split_lists.c functii.c
	$(CC) split_lists.c functii.c -Wall -o $(EXEC)

run:
	./$(EXEC) $(SIZE)

clean:
	rm $(EXEC)