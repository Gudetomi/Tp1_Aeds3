#include "funcoes.h"

void executa_fb(int nave, Stardeath *star_death2){
	Stardeath *star_death3 = star_death2;
	int *aux;
	aux=(int*)malloc(sizeof(int));
	for(int k = 0; k < nave;k++){
		mirror_matriz(k,star_death3);
		(int*) realloc (aux, star_death3[k].k_saltos+1* sizeof(int));
		combinationUtil(star_death3[k].matriz_d, aux, 1, star_death3[k].n_planetas+1, 0, 0, star_death3[k].k_saltos+1,0,&star_death3[k].final_plan);
	}
}
