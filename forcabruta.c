#include "funcoes.h"

void executa_fb(int nave, Stardeath *star_death2){
    Stardeath *star_death3 = star_death2;
    for(int i = 0; i < nave; i++){
        int *aux;
        mirror_matriz(i,star_death3);
        aux = (int*) calloc ( star_death3[i].k_saltos+1 , sizeof(int));
        combinationUtil(star_death3[i].matriz_d,aux, 1, star_death3[i].n_planetas+1, 0, 0, star_death3[i].k_saltos+1,0,&star_death3[i].final_plan);
        free(aux);
	}
}
