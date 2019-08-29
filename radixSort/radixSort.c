#include<stdio.h>
#include<stdlib.h>

int calcMax(int *input,int tam){
    int max = input[0];

    for(int i=0;i<tam;i++){
      if(input[i]>max){
          max = input[i];
          //printf("\nmaxR:%d\n", max);
      }
    }
    return max;
}

void display(int *input, int tam){
  for(int i=0;i<tam;i++){
    printf("\ndisplay[%d]: %d ", i,input[i]);
  }
  printf("\n");
}

int negTest(int *input,int tam){
  int neg;
  int min = input[0];
  for(int i=0;i<tam;i++){
    if(input[i]<min){
        min = input[i];
        printf("\nminimo:%d\n", min);
    }
  }
  neg = (min*(-1));
  if(min<0){
    for(int i=0;i<tam;i++){
          input[i] = input[i] + (min*(-1));
    }
    return neg;
  }else{
    return 0;
  }
}

void countSort(int *input,int tam,int countR){
    int arrayCount[10] = {0};
    int output[tam] = {0};

    for(int i = 0;i<tam;i++){
      arrayCount[(input[i]/countR)%10]++;
    }
    for(int i = 1;i<10;i++){
      arrayCount[i] = arrayCount[i] + arrayCount[i-1];
    }
    for(int i = tam-1;i>=0;i--){
      output[(arrayCount[(input[i]/countR)%10])-1] = input[i];
      arrayCount[(input[i]/countR)%10]--;
    }

    for (int i = 0; i < tam; i++){
        input[i] = output[i];
    }
}

void radixSort(int *input,int tam,int negSum){

    int max = input[0];
    for(int i=0;i<tam;i++){
      if(input[i]>max){
          max = input[i];
      }
    }
    //percorre cada casa decimal
    for(int casaD = 1; (max/casaD) > 0; casaD=casaD*10){
      //countsort aplicado a cada casa
      countSort(input,tam,casaD);
    }

    if(negSum>0){
      for(int i=0;i<tam;i++){
          input[i] = input[i] - negSum;
      }
    }else{}

    display(input,tam);
}


int main(int argc, char * argv[]){
    int tamanho;
    scanf("%d", &tamanho);
    int *vetor = (int*)calloc(tamanho,sizeof(int));
    for(int i = 0; i < tamanho; i++){
      scanf("%d",&vetor[i]);
  	}
    int negativo = negTest(vetor,tamanho);
    //display(vetor,tamanho);
    radixSort(vetor,tamanho,negativo);


    free(vetor);
    printf("\n");
}
