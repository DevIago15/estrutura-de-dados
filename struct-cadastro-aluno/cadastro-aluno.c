#include <stdio.h>
#include <locale.h>
#define n 2


struct Alunos{
	char nome[30];
	float P1;
	float P2;
	float T;
	float media;
	char sit;
};

// --> Cadastrar Aluno <-- \\

	void cadastroAluno(struct Alunos a[n]){
	int i;
	for(i=0; i < n; i++){
		printf("Digite o Nome do Aluno: ");
		scanf("%s", a[i].nome);
		printf("Digite a Nota P1 do Aluno: ");
		scanf("%f", &a[i].P1);
		printf("Digite a Nota P2 do Aluno: ");
		scanf("%f", &a[i].P2);
		printf("Digite a Nota T do Aluno: ");
		scanf("%f", &a[i].T);
		printf("\n");
		a[i].media = (a[i].P1 * 2 + a[i].P2 * 3 + a[i].T)/6;
		if(a[i].media >= 6)
			a[i].sit='A';
		else a[i].sit='R';
	}
}
		


// --> Pesquisa de Aluno <-- \\

	float pesquisaMedia(struct Alunos a[n], char nA[30]){
	int i;
	for(i = 0; i < n; i++){
		if(strcmp(a[i].nome, nA) == 0)
        { 
		   return (a[i].media);
		}
	}		
	
 	 return -1;
}	


 // --> Aprovados e Reprovados <-- \\
 
 	 void listaApRep(struct Alunos a[n]){
		  int i;
		  printf("Lista de Aprovados\n");
		  for(i = 0; i < n; i++){
			  if(a[i].sit == 'A')
			  	printf("%s\n", a[i].nome);
		  }
	  	  printf("\nLista de Reprovados\n");
	  	  for(i = 0; i < n; i++){
				if(a[i].sit == 'R')
					printf("%s\n", a[i].nome);
			}
	  }



main(){
	
	// --> CRUD <-- \\
	
	struct Alunos a[n];
	int op;
	char nomea[30];
	float mediaa;
	setlocale(LC_ALL,"Portuguese");
	printf("Seja Bem Vindo ao Cadastro de Alunos UNIRP!");
	
	printf("\n Selecione uma opção:");
	do{
		printf("\n 1 - Cadastrar Aluno");
		printf("\n 2 - Pesquisar Média do Aluno");
		printf("\n 3 - Visualizar");
		printf("\n 4 - Sair\n");
		printf("Sua Opção: ");
		scanf("%d", &op);
		switch(op){
			case 1: cadastroAluno(a);
				break;
			case 2: printf("Digite o Nome do Aluno: ");
			scanf("%s",nomea);
			mediaa = pesquisaMedia(a, nomea);
			if (mediaa == -1)
				printf("\n Aluno %s não cadastrado", nomea);
			else
				 printf("A Media do Aluno %s foi %2.f\n", nomea, mediaa);
				break;
			case 3: listaApRep(a);
				break;
			case 4: printf("Saindo do Programa...");
				break;
			default:
				printf("Opção Inválida");
				break;
		
		
		}
	} while(op != 4); // while de saida caso op = 4 \\
		return 0;			
}	
