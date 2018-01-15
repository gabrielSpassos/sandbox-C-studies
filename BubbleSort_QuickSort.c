#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Exercício: Proponha um programa em C, que armazena os dados de um número de atletas informado pelo usuário,
sendo que para cada um deles, devem ser lidos: nome, idade e peso. Implemente os dois algoritmos pesquisados,
permitindo que sejam listados os atletas em ordem crescente de idade ou peso.*/




struct Atl {
  char nome[50];
  int idade;
  float peso;
};

typedef struct Atl atleta; 

atleta quicksort(atleta *vetor, int len, int opcao);
atleta qsIdade(atleta *vetor, int left, int right);
atleta qsPeso(atleta *vetor, int left, int right);

void Quick(atleta *vetor,int inicioVetor, int fimVetor);

void main() {
	setlocale(LC_ALL, "Portuguese");
  	int opcao, numAtl, i, z, w, y, sair=0, auxIdade;
  	char auxNome[50];
  	float auxPeso;
	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
	printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
   	printf("\nDigite o número de atletas que serão armazenados:  ");
   	scanf("%d",&numAtl);
   	fflush(stdin);
    atleta vetAtleta[numAtl];
	system("cls");
    for (i=0; i<numAtl; ++i)
    {
    	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
		printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
    	printf("\nDigite o nome do atleta %d: ", i+1);
    	scanf("%s",&vetAtleta[i].nome);
    	fflush(stdin);

      	printf("\nDigite a idade do atleta %d: ", i+1);
      	scanf("%d",&vetAtleta[i].idade);
      	fflush(stdin);

      printf("\nDigite o peso [kg] do atleta %d: ", i+1);
      scanf("%f",&vetAtleta[i].peso);
      fflush(stdin);
      system("cls");
    }
    printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
	printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
    printf("Lista desordenada:  \n");
    for(y=0; y<numAtl; y++){
    	printf("\nInformações do %dº Atleta",y+1);
        printf("\nNome do atleta: %s",vetAtleta[y].nome);
        printf("\nIdade do atleta: %d anos",vetAtleta[y].idade);
        printf("\nPeso do atleta: %.2f kg\n",vetAtleta[y].peso);
    }
    printf("\n\n");
    system("pause");

    do{
    system("cls");
    printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
	printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
    printf("\tMenu\n\n\n\n");
    printf("1 - Bubble sort idade: \n");
    printf("2 - Bubble sort peso: \n");
    printf("3 - Quick sort idade: \n");
    printf("4 - Quick sort peso: \n");
    printf("9 - Sair\n");
    printf("\nDigite sua escolha:  ");
    scanf("%d",&opcao);

    switch(opcao){

      case 1:
      	system("cls");
      	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
		printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
        printf("\nBUBBLE SORT IDADE  \n");
        for(z=0; z<numAtl; z++){
          for(w=0; w<numAtl; w++){
            if(vetAtleta[z].idade < vetAtleta[w].idade){

              	auxIdade = vetAtleta[z].idade;
              	vetAtleta[z].idade = vetAtleta[w].idade;
             	vetAtleta[w].idade = auxIdade;

             	auxPeso = vetAtleta[z].peso;
             	vetAtleta[z].peso = vetAtleta[w].peso;
              	vetAtleta[w].peso = auxPeso;

              	strcpy(auxNome, vetAtleta[z].nome);
              	strcpy(vetAtleta[z].nome, vetAtleta[w].nome);
              	strcpy(vetAtleta[w].nome, auxNome);

            }
          }
        }
		
        for(y=0; y<numAtl; y++){
        	printf("\nInformações do %dº Atleta",y+1);	
          	printf("\nNome do atleta: %s",vetAtleta[y].nome);
          	printf("\nIdade do atleta: %d anos",vetAtleta[y].idade);
          	printf("\nPeso do atleta: %.2f kg\n",vetAtleta[y].peso);
        }
		
        printf("\n\n");
        system("pause");
        system("cls");
        break;

      case 2:
      	system("cls");
      	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
		printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
        printf("\nBUBBLE SORT PESO  \n");

        for(z=0; z<numAtl; z++){
          for(w=0; w<numAtl; w++){
            if(vetAtleta[z].peso < vetAtleta[w].peso){

              	auxPeso = vetAtleta[z].peso;
              	vetAtleta[z].peso = vetAtleta[w].peso;
              	vetAtleta[w].peso = auxPeso;

              	auxIdade = vetAtleta[z].idade;
              	vetAtleta[z].idade = vetAtleta[w].idade;
              	vetAtleta[w].idade = auxIdade;

              	strcpy(auxNome, vetAtleta[z].nome);
              	strcpy(vetAtleta[z].nome, vetAtleta[w].nome);
              	strcpy(vetAtleta[w].nome, auxNome);
			
            }
          }
        }

        for(y=0; y<numAtl; y++){
        	printf("\nInformações do %dº Atleta",y+1);	
          	printf("\nNome do atleta: %s",vetAtleta[y].nome);
          	printf("\nIdade do atleta: %d anos",vetAtleta[y].idade);
          	printf("\nPeso do atleta: %.2f kg\n",vetAtleta[y].peso);
        }
      
        printf("\n\n");
        system("pause");
        system("cls");
        break;

      case 3:
      	system("cls");
      	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
		printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
        printf("\nQUICK SORT IDADE  \n");
		quicksort(vetAtleta,numAtl,1);
		for(y=0; y<numAtl; y++){
        	printf("\nInformações do %dº Atleta",y+1);	
          	printf("\nNome do atleta: %s",vetAtleta[y].nome);
          	printf("\nIdade do atleta: %d anos",vetAtleta[y].idade);
          	printf("\nPeso do atleta: %.2f kg\n",vetAtleta[y].peso);
        }
        printf("\n\n");
        system("pause");
        system("cls");
        break;

      case 4:
      	system("cls");
      	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n");
		printf("\t\t***Gabriel Passos e Thomas Soares***\n\n");
        printf("\nQUICK SORT PESO  \n");
		quicksort(vetAtleta,numAtl,2);
		for(y=0; y<numAtl; y++){
        	printf("\nInformações do %dº Atleta",y+1);	
          	printf("\nNome do atleta: %s",vetAtleta[y].nome);
          	printf("\nIdade do atleta: %d anos",vetAtleta[y].idade);
          	printf("\nPeso do atleta: %.2f kg\n",vetAtleta[y].peso);
        }
        printf("\n\n");
        system("pause");
        system("cls");
        break;

      case 9:
      	system("cls");
      	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n\n");
        sair = 1;
        break;

      default:
      	system("cls");
      	printf("\t\t***Trabalho Buble Sort e Quick Sort***\n\n");
        printf("Opcao Invalida!! Tente novamente\n\n");
        system("pause");
        break;

    }

  }while(sair==0);
}

atleta quicksort(atleta *vetor, int len, int opcao) {
	switch(opcao){
		case 1:
			qsIdade(vetor, 0, len-1);
			break;
		case 2:
			qsPeso(vetor,0,len-1);
			break;	
	}
}

atleta qsIdade( atleta *vetor, int left, int right) 
{ 

  	int i, j; 
  	int x, auxIdade; 
  	float auxPeso;
  	char auxNome[50];
  	x = (vetor[left].idade + vetor[right].idade)/2;
  	//left = vetor[left].idade;
	//right = vetor[right].idade;
  	i = left; 
  	j = right; 
  	do { 
    	while((vetor[i].idade < x) && (i < right)) i++; 
    	while((x < vetor[j].idade) && (j > left)) j--; 

    if(i <= j) { 
    	auxIdade = vetor[i].idade; 
    	vetor[i].idade = vetor[j].idade; 
      	vetor[j].idade = auxIdade; 
      	
      	auxPeso = vetor[i].peso;
      	vetor[i].peso = vetor[j].peso;
      	vetor[j].peso = auxPeso;
      	
      	strcpy(auxNome, vetor[i].nome);
        strcpy(vetor[i].nome, vetor[j].nome);
        strcpy(vetor[j].nome, auxNome);
      	i++; j--; 
    } 
  } while(i <= j); 
  if(left < j) qsIdade(vetor, left, j); 
  if(i < right) qsIdade(vetor, i, right); 

}

atleta qsPeso(atleta *vetor, int left, int right){
	
	int i, j; 
  	int x, auxIdade; 
  	float auxPeso;
  	char auxNome[50];
  	x = (vetor[left].peso + vetor[right].peso)/2;
  	//left = vetor[left].idade;
	//right = vetor[right].idade;
  	i = left; 
  	j = right; 
  	do { 
    	while((vetor[i].peso < x) && (i < right)) i++; 
    	while((x < vetor[j].peso) && (j > left)) j--; 

    if(i <= j) { 
      	auxPeso = vetor[i].peso;
      	vetor[i].peso = vetor[j].peso;
      	vetor[j].peso = auxPeso;
      	
		auxIdade = vetor[i].idade; 
    	vetor[i].idade = vetor[j].idade; 
      	vetor[j].idade = auxIdade; 
      	
      	strcpy(auxNome, vetor[i].nome);
        strcpy(vetor[i].nome, vetor[j].nome);
        strcpy(vetor[j].nome, auxNome);
      	i++; j--; 
    } 
  } while(i <= j); 
  if(left < j) qsPeso(vetor, left, j); 
  if(i < right) qsPeso(vetor, i, right); 
}



