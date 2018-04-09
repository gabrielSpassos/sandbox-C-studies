#include <stdio.h>
#include <stdlib.h>

#define DIM 100000
#define VAL 84328

int buscaLinear (int vet[DIM]);
int buscaBinaria(int vet [DIM]);

void main (void){

	int vet [DIM],i;
	
	for (i=0;i<DIM;i++){
		vet[i]=i;	 
	}
	
	buscaLinear(vet);
	
	buscaBinaria(vet);
			
}

int buscaLinear(int vet [DIM]){
	int i;

	for(i=0;i<DIM;i++){
		if(vet[i] == VAL){
			printf("\nEncontrado valor %d em %d interacoes!",VAL,i);
			return 1;
		}	
	}
}

int buscaBinaria(int vet[DIM]){
	
	int meio, ini = 0, fim = DIM - 1, cont=0;
	
	while(ini<=fim){
		cont++;
		meio = (ini + fim)/2;
		
		if(vet[meio] == VAL){
			printf("\n\nEncontrado valor %d em %d interacoes!",VAL,cont);
			return 1;
		}else if(vet[meio]> VAL){
			fim = meio - 1;
		}else{
			ini= meio + 1;
		}	
	}	
}

