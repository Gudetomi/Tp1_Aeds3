all:
	gcc funcoes.c programacaodinamica.c algoritmoguloso.c forcabruta.c main.c -o tp -g

clean:
	-rm tp
