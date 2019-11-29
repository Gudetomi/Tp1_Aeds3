#include "funcoes.h"

void executa_ag(int nave, Stardeath* star_death2){
    int soma = 0,media = 0;
    Stardeath star_death3 = *star_death2;
    //calcula a media das distancias
    for(int i = 0; i < star_death3.n_planetas + 1; i++){
        for(int j = 1; j < star_death3.n_planetas + 1; j++){
                soma += star_death3.vetor_d[i][j];
        }
    }
    //realiza um salto cada vez que a distancia for menor que a media e guarda este valor

}