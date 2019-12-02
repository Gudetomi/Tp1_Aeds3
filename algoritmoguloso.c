#include "funcoes.h"

void executa_ag(int nave, Stardeath* star_death2){
    int *media,maior=0,m=0,t=0,*buffer, count;
    Stardeath *star_death3 = star_death2;
    buffer = (int*)calloc(1,sizeof(int));
    media = (int*)calloc(1,sizeof(int));
    for(int j = 0; j < nave ; j++){
      count=0;
      t=star_death3[j].n_planetas+1;
      buffer = (int*)realloc(buffer,(t)*sizeof(int));
      //preenchimento do buffer
      *media=inserrebuffer(t,j,star_death3,buffer);
      //traca caminho guloso
      while(count < star_death3[j].n_planetas - star_death3[j].k_saltos){
        guloso(media,m,buffer,&t,star_death3,j);
        count++;
      }
      //encontra maior em buffer;
      for(int i = 0; i < t; i++){
        if( maior < buffer[i] ){
          maior=buffer[i];
        }
      }
      star_death3[j].final_plan =maior;
      free(buffer);
    }

}
