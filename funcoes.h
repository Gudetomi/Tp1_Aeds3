#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct star_death{
    int *vetor_d, k_saltos, n_planetas, final_plan;
}Stardeath;

//Executa Programação Dinamica
void executa_pd();

//Executa Algoritmo Guloso
void executa_gl();

//Executa Força Bruta
void executa_fb();

//Interpretador das Entradas
Stardeath *imperial_plan(int *nave);