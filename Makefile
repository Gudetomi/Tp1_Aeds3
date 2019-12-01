CC = gcc
CFLAGS = -g -Wall
CLIBS = -lm
OBJS = main.o funcoes.o ag.o fb.o pd.o
TARGET = tp
all: $(TARGET)

tp: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tp tp.c $(CLIBS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(CLIBS)
funcoes.o: funcoes.c funcoes.h
	$(CC) $(CFLAGS) -c funcoes.c $(CLIBS)ag.o:algoritmoguloso.c 
	$(CC) $(CFLAGS) -c algoritmoguloso.c $(CLIBS)
pd.o: programacaodinamica.c 
	$(CC) $(CFLAGS) -c programacaodinamica.c $(CLIBS)
fb.o: forcabruta.c
	$(CC) $(CFLAGS) -c forcabruta.c $(CLIBS)
clean:
	rm -rf $(OBJS) tp
