#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main (void){
	
	char string[10] = "Test";
	char i;
	for(i=1;i<=15;i++){
		switch(i){
			case 1:
				system("color 1");
				break;
			case 2:
				system("color 2");
				break;	
			case 3:
				system("color 3");
				break;
			case 4:
				system("color 4");
				break;
			case 5:
				system("color 5");
				break;
			case 6:
				system("color 6");
				break;
			case 7:
				system("color 7");
				break;
			case 8:
				system("color 8");
				break;
			case 9:
				system("color 9");
				break;
			case 10:
				system("color A");
				break;
			case 11:
				system("color B");
				break;
			case 12:
				system("color C");
				break;
			case 13:
				system("color D");
				break;
			case 14:
				system("color E");
				break;
			case 15:
				system("color F");
				break;												
		}
		printf("Change color test: %s\n",string);
		system("pause");
		system("cls");
	}
	
}

/*
system ("color [ fc ]") f = corresponde à cor do plano de fundo c= à cor de primeiro plano.

0 = Preto	-	8 = Cinza

1 = Azul	-	9 = Azul claro

2 = Verde	-	A = Verde claro

3 = Verde-água	-	B = Verde-água claro

4 = Vermelho	-	C = Vermelho claro

5 = Roxo	-	D = Lilás

6 = Amarelo	-	E = Amarelo claro

7 = Branco	-	F = Branco brilhante
*/
