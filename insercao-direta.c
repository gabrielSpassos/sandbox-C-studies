#include <stdio.h>
#include <stdlib.h>

void main (void){
	
	int i,j,contador,auxMaior,tamanhoVetor;
	int vetor[5];
	tamanhoVetor=5;
	contador = 0;
	
	for(i=0;i<tamanhoVetor;i++){
		printf("\nDigite o valor a ser inserido no vetor na posicao %d: ",i);
		scanf("%d",&vetor[i]);	
		printf("\nDigitou o valor %d\n",vetor[i]);
		
		if(i==0){
			vetor[i] = vetor[i];
		}else{
			for(j=0;j<contador;j++){
				if(vetor[j] > vetor[contador]){
					auxMaior = vetor[j];
					vetor[j] = vetor[contador];
					vetor[contador] = auxMaior;
				}
			}
		}
		contador++;
	}	
	
	printf("\nValores ordenados...");
	for(i=0;i<tamanhoVetor;i++){
		printf("\nValor[%d]: %d",i,vetor[i]);
	}
}
