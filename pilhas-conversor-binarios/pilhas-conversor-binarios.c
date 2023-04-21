#include <stdio.h>
#include <math.h>
#define N 30

// --> Declaração da Pilha <-- \\

struct Pilha{
    int topo;
    int elementos[N];    
};

typedef struct Pilha PILHA;

// --> ------------------- <--- \\


// --> Metodo p/ Iniciar Pilha <--- \\

void iniciaPilha(PILHA *P, int numDec){
    int resto;
    P->topo=-1;
    
    do{
        resto = numDec % 2;
        PUSH(P, resto);
        numDec = numDec / 2;
    } while(numDec != 0);    
}

// --> ------------------- <--- \\

// --> Metodo p/ Empilhar <--- \\

void PUSH(PILHA *P, int resto){
    if(P->topo == N - 1){
        printf("Pilha Cheia!");
    } else 
        P->topo++;
        P->elementos[P->topo] = resto;
}

// --> ------------------- <--- \\

void POP(PILHA *P) {
    if(P->topo == -1){
        printf("Pilha Vazia!");
    } else 
        P->topo--;
}

// --> Metodo que Roda o Programa <--- \\

int main(){
    PILHA P;
    int numDec, resto, i, soma = 0;
    
    printf("Digite um Numero Inteiro em Base Decimal: ");
    scanf("%d", &numDec);
    
    iniciaPilha(&P, numDec);
    
    printf("Numero Correspondente: ");
    for(i = P.topo; i >= 0; i--){
        printf("%d", P.elementos[i]);
        soma = soma + P.elementos[i]*pow(2, i);
        POP(&P);
    }
    printf("\nValor em Decimal: %d", soma);
    
    return 0;
}

// --> ------------------- <--- \\
