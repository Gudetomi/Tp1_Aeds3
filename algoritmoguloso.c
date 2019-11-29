#include "funcoes.h"

void executa_ag(int nave, Stardeath* star_death2){
    int soma = 0;
    float media = 0;
    Stardeath star_death3 = *star_death2;
        printf("Planetas :%d\n",star_death3.n_planetas);
    for(int i = 0; i < star_death3.n_planetas+2;i++){
        for(int j = 0; j < star_death3.n_planetas+2;j++){
            printf("%d\t",star_death3.vetor_d[i][j]);
        }
        printf("\n");
    }
    //calcula a media das distancias
    for(int j = 0; j < star_death3.n_planetas+1 ; j++){
        soma += star_death3.vetor_d[j][j+1];           
    }
    printf("Soma:%d\n",soma);
    media = (soma/star_death3.n_planetas);
    printf("%f\n",media);
    //realiza um salto cada vez que a distancia for menor que a media e guarda este valor


}