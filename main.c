#include "funcoes.h"

int main(int argc,char *argv[]){

    /*trata arquivo de entrada, após tratado, verificar qual tipo de solução desejada:
    PD = Programação Dinamica, AG = Algoritmo Guloso, FB = Força Bruta, e sem seguida chamar
    a respectiva função passando como parametro os argumentos de entrada e o vetor das distancias*/
    Stardeath *star_death3;
    int nave;

    star_death3 = imperial_plan(&nave);
    if(strcmp(argv[1], "AG") == 0 || strcmp(argv[1], "ag") == 0){
        //chamar função de algoritmo guloso
        executa_ag(nave,star_death3);

    }
    

    

}