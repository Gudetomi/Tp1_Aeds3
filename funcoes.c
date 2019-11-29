#include "funcoes.h"

Stardeath *imperial_plan(int *nave){
    FILE *fp;
    fp = fopen("entrada.txt","r");
    Stardeath *tropper;
    int n,n_configuracoes, k, d, linha = 0,i,j;
    char buffer[256];
    if(fp == NULL){
        printf("Erro ao abrir o arquivo de entrada\n");
    }
    while(!feof(fp)){
        if(linha == 0){
            fgets(buffer,256,fp);
            sscanf(buffer, "%d",&n_configuracoes);
            tropper = (Stardeath*)malloc((*nave)*sizeof(Stardeath));
            linha++;
        }else if(linha >=1){
            for(i = 0; i < *nave; i++){
                fgets(buffer,256,fp);
                sscanf(buffer," %d %d", &n,&k);
                tropper[i].n_planetas = n; //Numero de planetas
                tropper[i].k_saltos = k; // Numero de saltos
                tropper[i].vetor_d = (int**)malloc((n+2)*sizeof(int*)); //Linhas da matriz
                for(k = 0; k < n + 2 ; k++){
                    tropper[i].vetor_d[k] = (int*)calloc((n+2),sizeof(int));//Colunas da matriz
                }
                for(k = 0; k < n+1; k++){
                    for(int l = 0; l < n+1; l++){
                        tropper[i].vetor_d[k][l] = 0;
                    }
                }
                //Apos receber as informações é necessario guardar os valores das distancias na matriz
                for(j = 0; j < n+1 ; j++){
                    fgets(buffer,256,fp);
                    sscanf(buffer,"%d",&d);
                    tropper[i].vetor_d[j][j+1] = d;           
                }
                for(k = 0; k < n +1; k++){
                    for(int l = k +2; l < n+2; l++){
                        tropper[i].vetor_d[k][l] = tropper[i].vetor_d[k][l-1]+tropper[i].vetor_d[l-1][l];
                    }
                }
            }      
            
        }
    }
    fclose(fp);
    return tropper;
}

/*void permutacoes(int n, int x[], int used[],int k){
    int i;
    if(k == n){
        for(i = 0; i < n; i++)
        printf("%d",x[i]+1);
    }else{
        for(i = 0; i < n; i++){
            if(!used[i])
                used[i] = 1;
                x[k] = i;
                permutacao(n,x,used,k+1);
                used[i] = 0;
            
        }
    }
    
}
*/