IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -g -Wall -lm

ODIR=obj
LDIR =../lib

_DEPS = statistics_reporting.h statistics_errors.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = reporting_main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

reporting_main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
