#include <stdio.h>
#include <locale.h>

// Declara��o do Struct
struct funcionario{
	  char nome[50];
	  float sB, sL, inss, ir, sH;
	  int diasT, horasT, numDp;
};


void main(){
	
	
	struct funcionario f[50];
	int i;
    setlocale(LC_ALL,"Portuguese");	
	
	// Entrada de Dados
	for(i = 0; i < 20; i++){
		printf("Escreva seu nome: ");
		scanf("%s", f[i].nome);
		printf("Quantas horas voc� trabalha?: ");
		scanf("%d", &f[i].horasT);
		printf("Quanto voc� recebe?: ");
		scanf("%f", &f[i].sB);
		printf("Quantos dependentes voc� tem? ");
		scanf("%d", &f[i].numDp);
		fflush(stdin);
		
		// Fazendo o adicional de dependentes
		f[i].numDp = f[i].numDp * 198.50;
		// Fazendo quanto ganha por hora
		f[i].sH = f[i].sB + f[i].numDp;
		printf("Voc� recebe por hora com o adicional por dependente: R$ %.2f\n", f[i].sH);
		
		// Fazendo desconto do INSS
		f[i].inss = f[i].sH * 0.10;
		
		if(f[i].sB > 1350){
			f[i].sB = f[i].sH - 300;
			printf("Voc� recebe liquido com desconto do INSS: R$ %.2f\n\n", f[i].sB);
				
		} 	else {
  		  	  f[i].sB = f[i].sH - f[i].inss;
		  	  printf("Voc� recebe liquido com desconto do INSS: R$ %.2f\n\n", f[i].sH);	
 	   		}
 	   		
  		// Fazendo desconto do IR
  		f[i].sB = f[i].sH;
		
		if(f[i].sB < 1350){
  			printf("Voc� est� isento da declara��o do IR: R$ %.2f\n\n", f[i].sB);  		 
		}
			else if(f[i].sB <= 5000){
				f[i].sB = f[i].sH * 0.11;
				printf("Voc� tem 11 por cento de desconto da declara��o do IR: R$ %.2f\n\n", f[i].sB);  		 
			}
				else{
					f[i].sB = f[i].sH * 0.20;
					printf("Voc� tem 20 por cento de desconto da declara��o do IR: R$ %.2f\n\n", f[i].sB);
				}
	}
		
	return 0;
}