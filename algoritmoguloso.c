#include "funcoes.h"

void executa_ag(int nave, Stardeath* star_death2){
    int soma = 0,menor,*buffer;
    float media = 0;
    Stardeath star_death3 = *star_death2;
    //calcula a media das distancias
    for(int j = 0; j < star_death3.n_planetas+1 ; j++){
        soma += star_death3.matriz_d[j][j+1];           
    }
    media = (soma/star_death3.n_planetas);
    //realiza um salto cada vez que a distancia for menor que a media e guarda este valor
    for(int i = 0; i < star_death3.n_planetas+2;i++){
        for(int j = 1; j < star_death3.n_planetas+2;j++){
            menor = star_death3.matriz_d[i][j];
            if(menor < media){
                buffer = 
            }
        }
        printf("\n");
    }



}