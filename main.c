#include "funcoes.h"

int main(int argc,char *argv[]){

	struct rusage resources;
	struct timeval u_inicio, u_fim, s_inicio, s_fim;

    /*trata arquivo de entrada, após tratado, verificar qual tipo de solução desejada:
    PD = Programação Dinamica, AG = Algoritmo Guloso, FB = Força Bruta, e sem seguida chamar
    a respectiva função passando como parametro os argumentos de entrada e o vetor das distancias*/
    Stardeath *star_death3;
    int nave;
		char *arquivo;

		arquivo = (char*) malloc(50 * sizeof(char));

		printf("Nome do arquivo: ");
		scanf("%s", arquivo);

	// Inicia a contagem do tempo de execução.
    gettimeofday(&u_inicio, NULL);
    getrusage(RUSAGE_SELF, &resources);
    s_inicio = resources.ru_utime;
		clock_t inicio = clock();

    star_death3 = imperial_plan(&nave, arquivo);
    if(strcmp(argv[1], "AG") == 0 || strcmp(argv[1], "ag") == 0){
        //chamar função de algoritmo guloso.
        executa_ag(nave,star_death3);

    }else if(strcmp(argv[1], "FB") == 0 || strcmp(argv[1], "fb") == 0){
        //chamar função de força bruta
        executa_fb(nave,star_death3);
    }else if(strcmp(argv[1], "PD") == 0 || strcmp(argv[1], "pd") == 0){
        executa_pd(nave,star_death3);
				printf("Sorry , tente AG ou FB");
				exit(EXIT_SUCCESS);
		}
    gera_saida(nave, star_death3);

	// Finaliza a contagem do tempo de execução.
  gettimeofday(&u_fim, NULL);
	getrusage(RUSAGE_SELF, &resources);
	s_fim = resources.ru_utime;
	clock_t fim = clock();

	// Calcula o tempo de execução.
    printf("\nSystem Runtime: %f seconds\n", (double)(s_fim.tv_sec - s_inicio.tv_sec) / 1000000);
    printf("User Runtime: %f seconds\n", (double)(s_fim.tv_usec - s_inicio.tv_usec) / 1000000);
	printf("Time: %f seconds\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
}
