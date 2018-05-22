CC=gcc
CFLAGS=-I ../include/
APP=calculadora
ODIR=../obj
IDIR=../include
_DEPS=calculadora.h
_OBJ=calculadora.o suma.o resta.o multiplicacion.o division.o datos.o

DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))


calculadora: $(OBJ)
	$(CC) -o $(APP) $(OBJ)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f calc $(ODIR)/*.o

install:
	/bin/cp $(APP) /usr/local/bin

uninstall:
	/bin/rm /usr/local/bin/$(APP)
