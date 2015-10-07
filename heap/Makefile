CC=gcc
CFLAGS=-I.
DEPS= 
OBJ = heap.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

heap: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean 

clean:
	rm *.o  
