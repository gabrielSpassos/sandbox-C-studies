#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>

void tornarLetrasMinusculas (char vetor[]);
int validaAlfabeto (char vetor[]);
int switchAlfabeto (char vetor[]);

void main (void){
	setlocale(LC_ALL, "Portuguese");
	char estado = 0;
	char palavra [10]; //palavra máxima com 10 caracteres 
	int i = 0, sair = 0, j = 0, n = 0,m = 0,z;
	int escAlfabeto = 0;
	//leitura da string
	do{
	
	printf("\nDigite uma palavra: ");
	scanf("%s",&palavra);
	//confirmar que os caracteres serao usados como minusculos 
	tornarLetrasMinusculas(palavra);
	//valida se as letras digitadas pertemcem ao alfabeto: [a,b,c]
	escAlfabeto = validaAlfabeto(palavra);
	
	}while(escAlfabeto == 1);
	
	
	for(z=0;z<strlen(palavra);z++){
		switch(estado){
			case 0:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 4;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 7;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 1;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 1:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 5;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 5;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 2;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 2:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 3;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 3;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 3;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 3:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 2;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 2;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 2;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 4:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 5;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 5;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 8;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 5:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 7;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 7;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 1;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 6:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 7;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 7;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 3;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 7:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 5;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 5;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 6;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 8:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 9;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 10;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 11;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 9:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 15;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 17;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 8;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 10:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 15;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 17;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 8;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 11:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 14;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 12;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 14;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 12:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 11;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 13;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 11;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 13:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 14;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 12;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 14;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 14:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 11;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 13;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 11;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 15:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 9;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 10;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 8;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 16:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 15;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 17;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 14;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;
			case 17:
				switch(palavra[z]){
					case 'a':
						printf("\ndeu A");
						estado = 9;
						printf("\nEstado: %d",estado);
						break;
					case 'b':
						printf("\ndeu B");
						estado = 10;
						printf("\nEstado: %d",estado);
						break;
					case 'c':
						printf("\ndeu C");
						estado = 16;
						printf("\nEstado: %d",estado);
						break;	
				}
				break;	
		}
	}
	
	if(estado==0 || estado==1 || estado==4 || estado==5 || estado==6 || estado==7 || estado==8 || estado==9 || estado==15 || 
	estado==16 || estado==17){
		printf("\nPalavra Aceita!!");
	}else{
		printf("\nPalavra Rejeitada!!");
	}
	
	for (i=0;i<strlen(palavra);i++){
		printf("\nCaracter(es): %c",palavra[i]);
	}
	
}

void tornarLetrasMinusculas (char vetor[]){
	int j;
	for(j=0;j<strlen(vetor);j++){
		vetor[j] = tolower(vetor[j]);
	
	}
}

int validaAlfabeto (char vetor[]){
	int n,m,validador;
	for (n=0;n<strlen(vetor);n++){
		if(vetor[n]!='a'&& vetor[n]!='b' && vetor[n]!='c'){
			validador = 1;	
			printf("\nDigitou letra que não está no alfabeto!\nAlfabeto: [a/b/c]");
			//limpa vetor caso tenha ficado algo do vetor anterior. 
			for(m=0;m<strlen(vetor);m++){
				vetor[m] = NULL;
			}
		}else{
			validador = 0;
		}
			
	}
	
	return validador;
	
}


