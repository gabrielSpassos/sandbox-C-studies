typedef struct no* ArvAVL;

#include <stdio.h>
#include <stdlib.h>


struct no{
	int valor;
	int altura;
	struct no *esquerda;
	struct no *direita;
};

int calculaAltura (struct no* no);
int calculaBalanceamento (struct no* no);
int calculaMaior(int x,int y);
void rotacaoLL (ArvAVL *raiz); 
void rotacaoRR (ArvAVL *raiz); 
void rotacaoLR (ArvAVL *raiz); 
void rotacaoRL (ArvAVL *raiz); 
int insere (ArvAVL *raiz, int valor);
int consulta (ArvAVL *raiz, int valor);
int remover (ArvAVL *raiz, int valor);
struct no* procuraMenor (struct no* atual);
void preOrdem(ArvAVL *raiz);
void emOrdem(ArvAVL *raiz);
void posOrdem(ArvAVL *raiz);

void main (void){
	
	int valorInserido,valorBusca,valorRemovido,x;
	ArvAVL* raiz;
	char sair=0,sair2=0, opcao,opcao2;
		
	do{
		system("cls");
		printf("\n\n\n\t\tArvore AVL\n\n\n\n\n");
		printf("\t\tMenu\n\n\n\n");
		printf("1 - Inserir valor na arvore\n");
		printf("2 - Remover valor na arvore \n");
		printf("3 - Consultar um valor\n");
		printf("4 - Mostrar arvore\n");
		printf("5 - Sair\n");
		printf("\nDigite sua escolha:  ");
		scanf("%d",&opcao);
		
		switch(opcao){
			
			case 1:
				printf("Digite o valor a ser inserido:  ");
				scanf("%d",&valorInserido);
				x = insere(raiz,valorInserido);
				system("pause");
				break;
			
			case 2:
				printf("Digite o valor a ser removido:  ");
				scanf("%d",&valorRemovido);
				x = remover(raiz,valorRemovido);
				system("pause");
				break;	
				
			case 3:
				printf("Digite o valor a ser consultado:  ");
				scanf("%d",&valorBusca);
				x = consulta(raiz,valorBusca);
				system("pause");
				break;
			
			case 4:
				do{
					system("cls");
					printf("\t\tMenu de Visualizacoes!!\n\n");
					printf("1 - Pre-Ordem\n");
					printf("2 - Em ordem\n");
					printf("3 - Pos-Ordem\n");
					printf("4 - Sair\n");
					printf("\nDigite sua escolha:  ");
					scanf("%d",&opcao2);
					
					switch(opcao2){
						
						case 1:
							preOrdem(raiz);
							system("\npause");
							break;
						case 2:
							emOrdem(raiz);
							system("\npause");
							break;
						case 3:
							posOrdem(raiz);
							system("\npause");
						 	break;
						case 4:
							sair2 = 1;
							break;
						default:
							printf("Opcao Invalida!! Tente novamente\n\n");
							system("\npause");
							break;				 		
					}
				}while(sair2==0);
				break;
				
			case 5:
				sair = 1;
				break;
			
			default:
				printf("Opcao Invalida!! Tente novamente\n\n");
				system("\npause");
				break;				
		}
			
	}while(sair==0);

}
	

int calculaAltura (struct no* no){
	
	if(no == NULL){
		return -1;
	}else{
		return no->altura;
	}
}

int calculaBalanceamento (struct no* no){
	
	return labs(calculaAltura(no->esquerda) - calculaAltura(no->direita));
}

int calculaMaior(int x,int y){
	if (x>y){
		return x;
	}else{
		return y;
	}
}

//rotação simples a direita
void rotacaoLL (ArvAVL *raiz){
	struct no *no;
	
	no = (*raiz)->esquerda;
	(*raiz)->esquerda = no->direita;
	no->direita = *raiz;
	
	(*raiz)->altura = calculaMaior(calculaAltura((*raiz)->esquerda),calculaAltura((*raiz)->direita))+1;
	no->altura = calculaMaior(calculaAltura(no->esquerda),(*raiz)->altura) + 1;
	
	*raiz = no;
}

//rotação simples a esquerda
void rotacaoRR (ArvAVL *raiz){
	
	struct no *no;
	
	no = (*raiz)->direita;
	(*raiz)->direita=no->esquerda;
	no->esquerda=(*raiz);
	
	(*raiz)->altura = calculaMaior(calculaAltura((*raiz)->esquerda),calculaAltura((*raiz)->direita)) +1;
	
	no -> altura = calculaMaior(calculaAltura(no->direita),(*raiz)->altura) +1;
	(*raiz) = no;
}

void rotacaoLR (ArvAVL *raiz){
	rotacaoRR(&(*raiz)->esquerda);
	rotacaoLL(raiz);
}
	
void rotacaoRL (ArvAVL *raiz){
	rotacaoLL(&(*raiz)->direita);
	rotacaoRR(raiz);
	
}

int insere (ArvAVL *raiz, int valor){
	int resposta;
	
	if(*raiz == NULL){
		struct no *novo;
		novo = (struct no*)malloc(sizeof(struct no));
		if(novo == NULL){
			return 0;
		}
		
		novo->valor = valor;
		novo->altura = 0;
		novo->direita = NULL;
		novo->esquerda = NULL;
		*raiz = novo;
		return 1;
	}
	
	struct no *atual = *raiz;
	if(valor < atual->valor){
		if((resposta=insere(&(atual->esquerda),valor))==1){
			if(calculaBalanceamento(atual)>=2){
				if(valor < (*raiz)->esquerda->valor){
					rotacaoLL(raiz);
				}else{
					rotacaoLR(raiz);
				}
			}
		}
	}else{
		if((resposta=insere(&(atual->direita),valor))==1){
			if(calculaBalanceamento(atual) >= 2){
				if((*raiz)->direita->valor < valor){
					rotacaoRR(raiz);
				}else{
					rotacaoRL(raiz);
				}
			}
		}else{
			printf("Valor duplicado!!\n");
			return 0;
		}
		
	}
	
	atual->altura = calculaMaior(calculaAltura(atual->esquerda),calculaAltura(atual->direita)) + 1;
	return resposta;
}

int consulta (ArvAVL *raiz, int valor){
	
	if(raiz == NULL){
		return 0;
	}
	struct no *atual = *raiz;
	while(atual != NULL){
		if(valor == atual->valor){
			return 1;
			printf("Valor: %d foi encontrado!\n",valor);
		}
		if(valor > atual->valor){
			atual = atual->direita;
		}else{
			atual = atual->esquerda;
		}
		return 0;
		
		
	}
	
}

int remover (ArvAVL *raiz, int valor){
	if (*raiz == NULL){
		printf("Valor %d nao existe",valor);
		return 0;
	}
	int resposta;
	if(valor < (*raiz)->valor){
		if((resposta=remover(&(*raiz)->esquerda,valor))==1){
			if(calculaBalanceamento(*raiz) >= 2){
				if(calculaAltura((*raiz)->direita->esquerda) <= calculaAltura((*raiz)->direita->direita)){
					rotacaoRR(raiz);
				}else{
					rotacaoRL(raiz);
				}
			}
		}
	}
	
	if((*raiz)->valor < valor){
		if((resposta=remover(&(*raiz)->direita,valor))==1){
			if(calculaBalanceamento(*raiz) >=2 ){
				if(calculaAltura((*raiz)->esquerda->direita) <= calculaAltura((*raiz)->esquerda->esquerda)){
					rotacaoLL(raiz);
				}else{
					rotacaoLR(raiz);
				}
			}
		}
	}
	
	if((*raiz)-> valor == valor){
		if(((*raiz)->esquerda == NULL || (*raiz)->direita == NULL)){
			struct no *oldNode = (*raiz);
			if((*raiz)->esquerda != NULL){
				*raiz = (*raiz)->esquerda;
			}else{
				*raiz = (*raiz)->direita;
			}
			free(oldNode);
		}else{
			struct no* temp = procuraMenor((*raiz)->direita);
			(*raiz)->valor = temp->valor;
			remover(&(*raiz)->direita, (*raiz)->valor);
			if(calculaBalanceamento(*raiz) >= 2){
				if(calculaAltura((*raiz)->esquerda->direita) <= calculaAltura((*raiz)->esquerda->esquerda)){
					rotacaoLL(raiz);
				}else{
					rotacaoLR(raiz);
				}
			}
		}
		return 1;
	}
	return resposta;	
}

struct no* procuraMenor (struct no* atual){
	struct no *no1 = atual;
	struct no *no2 = atual->esquerda;
	while(no2 != NULL){
		no1 = no2;
		no2 = no2->esquerda;
	}
	
	return no1;
	
}

void preOrdem(ArvAVL *raiz){
	if (raiz == NULL){
		return;
	}
	if(*raiz!= NULL){
		printf("%d-",(*raiz)->valor);
		preOrdem(&((*raiz)->esquerda));
		preOrdem(&((*raiz)->direita));
	}
}

void emOrdem(ArvAVL *raiz){
	if (raiz == NULL){
		return;
	}
	if(*raiz!= NULL){
		emOrdem(&((*raiz)->esquerda));
		printf("%d-",(*raiz)->valor);
		emOrdem(&((*raiz)->direita));
	}
}	

void posOrdem(ArvAVL *raiz){
	if (raiz == NULL){
		return;
	}
	if(*raiz!= NULL){
		posOrdem(&((*raiz)->esquerda));
		posOrdem(&((*raiz)->direita));
		printf("%d-",(*raiz)->valor);
	}
}	





