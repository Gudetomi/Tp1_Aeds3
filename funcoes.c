#include "funcoes.h"

Stardeath *imperial_plan(int *nave){
FILE *fp;
fp = fopen("entrada.txt","r");
Stardeath *tropper;
int n,n_configuracoes, k, d, linha = 0,i,j;
if(fp == NULL){
    printf("Erro ao abrir o arquivo de entrada\n");
    }
    while(!feof(fp)){
        if(linha == 0){
            fscanf(fp, "%d\n",&n_configuracoes);
            tropper = (Stardeath*)malloc((*nave)*sizeof(Stardeath));
            linha++;
        }else if(linha >=1){
            for(i = 0; i < *nave; i++){
                fscanf(fp," %d %d\n", &n,&k);
                tropper[i].n_planetas = n; //Numero de planetas
                tropper[i].vetor_d[i] = (int**)malloc((n +1)*sizeof(int*)); //Linhas da matriz
                for(int k = 0; k < n ; k++){
                tropper[i].vetor_d[k] = (int*)malloc((n+1)*sizeof(int));//Colunas da matriz
                }
                tropper[i].k_saltos = k; // Numero de saltos
                //Apos receber as informações é necessario guardar os valores das distancias na primeira linha da matriz
                for(j = 0; j < n +1; j++){
                    fscanf(fp,"%d\n",&d);
                    tropper[i].vetor_d[j] = d;
                }
            }
        }
    }
    fclose(fp);
    return tropper;

}
