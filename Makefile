CC = gcc
CFLAGS = -Wall -g
OBJS = main.o instancia.o

energia: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o energia

main.o: main.c instancia.h
instancia.o: instancia.c instancia.h

clean:
	rm -f $(OBJS)

purge: clean
	rm -f energia
