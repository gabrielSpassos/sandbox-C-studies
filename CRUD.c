#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM 5

typedef struct{

	char nome[30];
	char placa [10];
	char cor [30];
	int ano;

}NodoCarros;

void mostraLista(NodoCarros * lista, int n);
int insere (NodoCarros * lista, NodoCarros dado,int n);
int consulta (NodoCarros * lista, char placa[30],int n);
int remover (NodoCarros * lista, char placa[30],int n);


void main (void){

 int x =0, opcao, retorno;
 int n=0;
 NodoCarros dado;
 NodoCarros * lCarros;

 lCarros = malloc(LIM * sizeof (NodoCarros));

 do{
    system("cls");
    printf("\t\t\tLista de Carros\n\n\n");
    printf("\t\t\tEntre com a opcao:\n");
    printf("\t\t\t1 - Mostrar toda lista\n");
    printf("\t\t\t2 - Inserir um carro na lista\n");
    printf("\t\t\t3 - Consultar lista de carros\n");
    printf("\t\t\t4 - Remover carro da lista\n");
    printf("\t\t\t5 - Sair\n");
    printf("\nDigite sua opcao:  ");
    scanf("%d",&opcao);
    fflush(stdin);
    switch(opcao){
        case 1:
            mostraLista(lCarros,n);
            system("pause");
            break;

        case 2:
            printf("Digite o nome do carro:  \n");
            gets(dado.nome);
            printf("Digite a placa do carro:  \n");
            gets(dado.placa);
            printf("Digite a cor do carro: \n");
            gets(dado.cor);
            printf("Digite o ano do carro:  \n");
            scanf("%d",&dado.ano);
            fflush(stdin);
            n=insere(lCarros,dado,n);
            break;

        case 3:
            printf("Digite a placa do carro que deseja consultar:  ");
            gets(dado.placa);
            retorno = consulta(lCarros,dado.placa,n);
            if (retorno >= 0){
                   printf("\n%s de placa %s e ano %d da cor %s esta na posicao %d\n",lCarros[retorno].nome,lCarros[retorno].placa,
                          lCarros[retorno].ano,lCarros[retorno].cor,retorno);
            }else{
                printf("Carro nao existe na lista!\n");
            }
            system("pause");
            break;

        case 4:
            printf("Digite a placa do carro que deseja remover:  ");
            gets(dado.placa);
            n=remover(lCarros,dado.placa,n);
            break;

         case 5: 
		 	printf("\nVoce solicitou a opcao - sair!\n");
            exit(0);
            break;

        default: 
			printf("\t\nATENCAO - Opcao invalida, tente novamente!\n\n");
			system("pause");
    }
 }while(x == 0);
 free(lCarros);

}

void mostraLista(NodoCarros * lista, int n){
    int i;

    if(n==0){
        printf("Nao existe nenhum carro na lista.\n");
    }else{
        for(i=0;i<n;i++){
            printf("Nome: %s, Placa: %s, Cor: %s, Ano: %d\n\n",lista[i].nome,lista[i].placa,lista[i].cor,lista[i].ano);
        }
    }
}

int insere (NodoCarros * lista, NodoCarros dado,int n){
    if(n<LIM){
        strcpy(lista[n].nome,dado.nome);
        strcpy(lista[n].placa,dado.placa);
        strcpy(lista[n].cor,dado.cor);
        lista[n].ano = dado.ano;
        n++;
    }

    return n;

}

int consulta (NodoCarros * lista, char placa[30],int n){
    int x;
    int i;
    for(i=0;i<n;i++){
        x=strcmp(lista[i].placa,placa);
        if(x==0){
            return i;
        }
    }

    return -1;
}

int remover (NodoCarros * lista, char placa[30],int n){
    int posicao,i;

    posicao=consulta(lista,placa,n);
    if(posicao>=0){
        for(i=posicao;i<n-1;i++){
          strcpy(lista[i].nome,lista[i+1].nome);
          strcpy(lista[i].placa,lista[i+1].placa);
          strcpy(lista[i].cor,lista[i+1].cor);
          lista[i].ano = lista[i+1].ano;
      }
      n--;
      printf("%s removido da posicao %d",lista[posicao].nome,posicao);
      system("pause");

    }else{
        printf("Carro nao encontrado!\n");
        system("pause");
    }

    return n;

}




