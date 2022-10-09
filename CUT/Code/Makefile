OBJ=main.o
CO=gcc -o
CC=gcc -c
RM=rm *.o

final:	main.o
	$(CO) final $(OBJ) -g -lpthread

main.o:	SRC/main.c
	$(CC) SRC/main.c

clean: 
	$(RM) final
