#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct star_death{
    int **matriz_d, k_saltos, n_planetas, final_plan;
}Stardeath;

//Executa Programação Dinamica
void executa_pd(int nave,Stardeath *star_death3);

//Executa Algoritmo Guloso
void executa_ag(int nave,Stardeath *star_death3);

//Executa Força Bruta
void executa_fb(int nave,Stardeath *star_death3);

//Interpretador das Entradas
Stardeath *imperial_plan(int *nave);

//Libera matrizes
void libera_matriz(Stardeath *star_death3);

//Gera Saida
void gera_saida();