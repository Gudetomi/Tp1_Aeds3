#include "funcoes.h"

int main(int argc,char *argv[]){

    /*trata arquivo de entrada, após tratado, verificar qual tipo de solução desejada:
    PD = Programação Dinamica, AG = Algoritmo Guloso, FB = Força Bruta, e sem seguida chamar
    a respectiva função passando como parametro os argumentos de entrada e o vetor das distancias*/
    Stardeath *star_death3;
    int nave;
    star_death3 = imperial_plan(&nave);

    if(argv[1] == 'PD' || argv[1] == 'pd'){
        //chamar função de programação dinamica
        executa_pd();
        
    }
    else if(argv[1] == 'AG' || argv[1] == 'ag'){
        //chamar função de algoritmo guloso
        executa_ag();

    }
    else if(argv[1] == 'FB' || argv[1] == 'fb'){
        //chamar função de força bruta
        executa_fb();

    }

    

}