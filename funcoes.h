#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct star_death{
    int **matriz_d, k_saltos, n_planetas, final_plan;
}Stardeath;

//Executa Programação Dinamica
void executa_pd(int nave,Stardeath *star_death3);

//Executa Algoritmo Guloso
void executa_ag(int nave,Stardeath *star_death3);

//Executa Força Bruta
void executa_fb(int nave, Stardeath *star_death2);

//Interpretador das Entradas
Stardeath *imperial_plan(int *nave);

//Libera matrizes
void libera_matriz(Stardeath *star_death3);

//Gera Saida
void gera_saida();

//FB - Compara maior a caminho final
void compara(int*aux,int r,int *maior,int *s);

//espelha matriz_d pela diagonal principal
void mirror_matriz(int g, Stardeath *star_death2);

//calcula as possiveis combinacoes de forma recursiva
void combinationUtil(int **arr, int *aux, int inic, int fim, int index,int c, int r,int k,int *s);
