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
            nave[0] = n_configuracoes;
	    tropper = (Stardeath*)malloc((*nave)*sizeof(Stardeath));
            linha++;
        }else if(linha >=1){
            for(i = 0; i < *nave; i++){
                fgets(buffer,256,fp);
                sscanf(buffer," %d %d", &n,&k);
                tropper[i].n_planetas = n; //Numero de planetas
                tropper[i].k_saltos = k; // Numero de saltos
                tropper[i].final_plan = INT_MAX;
                tropper[i].matriz_d = (int**)calloc((n+2),sizeof(int*)); //Linhas da matriz
                for(k = 0; k < n + 2 ; k++){
                    tropper[i].matriz_d[k] = (int*)calloc((n+2),sizeof(int));//Colunas da matriz
                }
                //Apos receber as informações é necessario guardar os valores das distancias na matriz
                for(j = 0; j < n+1 ; j++){
                    fgets(buffer,256,fp);
                    sscanf(buffer,"%d",&d);
                    tropper[i].matriz_d[j][j+1] = d;
                }
                for(k = 0; k < n +1; k++){
                    for(int l = k +2; l < n+2; l++){
                        tropper[i].matriz_d[k][l] = tropper[i].matriz_d[k][l-1]+tropper[i].matriz_d[l-1][l];
                    }
                }
            }
        }
    }
    fclose(fp);

    return tropper;
}

void mirror_matriz(int g, Stardeath *star_death2){
		for(int i = 0; i < star_death2[g].n_planetas+2;i++){
						for(int j = 0; j < star_death2[g].n_planetas+2;j++){
							star_death2[g].matriz_d[j][i] = star_death2[g].matriz_d[i][j];
			}
		}
}


void compara(int*aux,int r,int *maior,int *s){
	for(int g=0;g<r;g++){
		if(*maior < aux[g]){
          	//recebe o maior valor da combinação

						*maior = aux[g];

       }
	}
       if(*maior<*s){
               /*caso o maior valor obtido seja menor
                que o já analisado*/
                *s= *maior;
           }
}

void combinationUtil(int **arr, int *aux, int inic, int fim, int index,int c, int r,int k,int *s){
		int fl,i, j, maior=0;

    if (k == r || inic==fim){
      /* se k é igual a quantidade de saltos
      ou inicio é igual a sair do ultimo planeta*/
        if(k<r){
				 //k é menor que a quantidade de saltos
				 aux[r-1] = arr[inic][index];
				 compara(aux,r,&maior,s);
			 }else{
			 //se k é igual a quantidade de saltos
			 	aux[r-1] = arr[index+1][inic];
			 	if(index+1==fim){
					//não existe mais nenhuma possibilidades de saltos.
					compara(aux,r,&maior,s);
				}
			}
			return;
		}

    for (i = inic; i < fim && fim-i+1 >= r-index; i++){

        if(k < r-1){
            //k é menor que quantidade de planetas a se pousar
            aux[k] = arr[index][i];
            combinationUtil(arr, aux, i+1, fim, i, i, r, k+1, s);

        }else if(k == r-1){
            //k é igual a quantidade de planetas a pousar
						c=index;
            aux[k-1] = arr[index][i];
            combinationUtil( arr, aux, c, fim, i, c, r, k+1, s);
        }else if(k > r-1){
            //k é igual a quantidade de saltos
            aux[k-1] = arr[index][i];
            combinationUtil( arr, aux, i, fim, index, c, r, k, s);

        }
    }
}

int inserrebuffer(int t, int j, Stardeath* star_death3, int* buffer){
        int soma=0;
        for(int i = 0; i < t ;i++){
            soma = soma + star_death3[j].matriz_d[i][i+1];
        //insere distancias no buffer
        buffer[i] = star_death3[j].matriz_d[i][i+1] ;
        }
        return soma/t;
      }

void guloso(int* menor,int m, int* buffer,int *t, Stardeath* star_death3, int k ){

  int M1,m1=INT_MAX,M2,m2=INT_MAX,soma=0,i=0;
  //procura menor
  for(int i = 0; i < *t ;i++){

    if(*menor>=buffer[i]){
      //*menor = buffer[i];
      m = i;
      break;
    }
  }
  //garante condicoes de analise
  if(m>0){
    m1=m-1;
    M1=buffer[m1];
  }else{
    M1=INT_MAX;
  }
  if(m<*t ){
    m2=m+1;
    M2=buffer[m2];
  }else{
    M2=INT_MAX;
  }
  
  //subustitue e realoca
    int A;
    A=buffer[m];
  if(M1<M2){
    
    buffer[m1]= M1 + A;
    
  }else{
    buffer[m2]= M2 + A;
  }

  for(i=m;i< (*t)-1;i++)
    buffer[i]=buffer[i+1];
  buffer = (int*)realloc(buffer,i*sizeof(int));

  *t=i;

}
