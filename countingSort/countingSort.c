#include<stdio.h>
#include<stdlib.h>

int calcRange(int *input,int tam){
    int max = input[0];
    int min = input[0];

    for(int i=0;i<tam;i++){
      if(input[i]<min){
          min = input[i];
      }
    }
    for(int i=0;i<tam;i++){
      if(input[i]>max){
          max = input[i];
      }
    }
    return ((max-min)+2);
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
    printf("i:%d\n",i);
    if(input[i]<min){
        min = input[i];
        printf("\nminimo:%d\n", min);

    }
    printf("i:%d\n",i);
  }
  printf("passei");
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

void countSort(int *input,int tam,int negSum){
    int range = calcRange(input,tam);
    int arrayCount[range] = {0};
    int output[tam] = {0};

    printf("\nrange: %d\n", calcRange(input,tam));
    for(int i = 0;i<tam;i++){
      arrayCount[input[i]]++;
    }//display(arrayCount,range);
    for(int i = 1;i<range;i++){
      arrayCount[i] = arrayCount[i] + arrayCount[i-1];
    }//display(arrayCount,range);
    for(int i =0;i<tam;i++){
      output[(arrayCount[input[i]])-1] = input[i];
      arrayCount[input[i]]--;
    }
    if(negSum>0){
      for(int i=0;i<tam;i++){
        output[i] = output[i] - negSum;
      }
    }else{}
    display(output,tam);
}



int main(int argc, char * argv[]){
    int tamanho;
    scanf("%d", &tamanho);
    int *vetor = (int*)calloc(tamanho,sizeof(int));
    for(int i = 0; i < tamanho; i++){
      scanf("%d",&vetor[i]);
  	}
    int negativo = negTest(vetor,tamanho);
    printf("terminei negativo");
    countSort(vetor,tamanho,negativo);

    free(vetor);
    printf("\n");
}
