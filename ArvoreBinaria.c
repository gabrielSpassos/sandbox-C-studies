#include <stdlib.h>
#include <stdio.h>

typedef struct   nodo{
  int numero;
  struct nodo *esquerda;
  struct nodo *direita;
}nodo;

int reset (int valor);
void criarArvore (nodo **pRaiz);
void preencher (nodo **pRaiz, int numero);
void mostraArvore(nodo * ptArv);
void preFixadoEsq(nodo * raiz);
int somaFolha(nodo * raiz, int somatorio);
int calculaNivel (nodo * raiz,int valor);
int somatorio2 = 0;  
int contador = 0;

void main (void){
  
  char validador1,validador2;
  int i,somatorioNosFolhas,valor;
  int cont = 0;
  int somatorio = 0;
  char sair=0,opcao;
  nodo *raiz = NULL;
  do{
    system("cls");
    printf("\t\t***Atividade 3 - Trabalho GA***\n\n\n");
    printf("\t\tMenu\n\n\n\n");
    printf("1 - Inserir valores na arvore\n");
    printf("2 - Mostra Arvore:\n");
    printf("3 - Mostrar soma dos nos folhas\n");
    printf("4 - Calcular o nivel de um no\n");
    printf("9 - Sair\n");
    printf("\nDigite sua escolha:  ");
    scanf("%d",&opcao);

    switch(opcao){

      case 1:
            printf("Digite o valor a ser inserido:  ");
            scanf("%d",&valor);
            preencher(&raiz,valor);        
            printf("Valor %d inserido na arvore binaria",valor);
            getch();
        break;

      case 2:
            mostraArvore(raiz);
            printf("\n");
            system("pause");
            system("cls");
            break;

      case 3:
            somatorioNosFolhas = somaFolha(raiz,somatorio);
            printf("Soma dos nos folhas eh: %d",somatorioNosFolhas);
            somatorio2 = reset(somatorio2);
            printf("\n");
            system("pause");
            system("cls");
        break;
        
      case 4:
      		contador = reset(contador);
            printf("Digite o valor a encontra o nivel: ");
            scanf("%d",&valor);
            cont = calculaNivel(raiz,valor);
            printf("Nivel do no %d \202: %d",valor,cont);
            printf("\n");
            system("pause");
            system("cls");
            break;
                
      case 9:
        sair = 1;
        break;

      default:
        printf("Opcao Invalida!! Tente novamente\n\n");
        system("pause");
        break;

    }

  }while(sair==0);

}

void preencher(nodo **pRaiz, int numero){

    if(*pRaiz == NULL){
        *pRaiz = (nodo *) malloc(sizeof(nodo));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    }else{
        if(numero < (*pRaiz)->numero){
          preencher(&(*pRaiz)->esquerda, numero);
    }else if(numero > (*pRaiz)->numero){
      preencher(&(*pRaiz)->direita, numero);
    }
    }

}

void mostraArvore(nodo * ptArv)
{
 printf("<");
 if(ptArv != NULL)
 {
  printf("%d",ptArv->numero);  //mostra raiz
  mostraArvore(ptArv->esquerda);  //mostra sae
  mostraArvore(ptArv->direita);  //mostra sad
 }
 printf(">");
}

int somaFolha(nodo * raiz,int somatorio){
    
  if(raiz!= NULL){
  if(raiz->esquerda == NULL && raiz->direita == NULL){
    somatorio = (somatorio) + raiz->numero;
        somatorio2 = somatorio2 + somatorio; 
  }
  somaFolha(raiz->esquerda,somatorio);
  somaFolha(raiz->direita,somatorio);
  }
  
  return somatorio2;
}

int calculaNivel (nodo * raiz,int valor){
    
    if(raiz!=NULL){
      	if(raiz->numero == valor){
        	return contador; 
    	}if(valor < raiz->numero){
        	contador++;
            calculaNivel(raiz->esquerda,valor);
        }else{
    		contador++;  
            calculaNivel(raiz->direita,valor);          
    	}
    }
        
}

int reset (int valor){
  valor = 0;
  return valor;
}

