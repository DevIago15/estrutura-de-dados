#include <stdio.h>
#include <stdint.h>

#define N 15 // constante --> boas práticas upper case (N)

typedef struct Pilha {
    int topo;
    char elementos[N];
} Pilha;

void iniciarPilha(Pilha* P) {
    P->topo = -1;
}

void push(Pilha* P, char c) {
    if (P->topo == N - 1) {
        printf("Pilha Cheia!");
    } else {
        P->topo++;
        P->elementos[P->topo] = c;
    }
}

void pop(Pilha* P) {
    if (P->topo == -1) {
        printf("Pilha Vazia");
    } else {
        P->topo--;
    }
}

char mostrarTopo(Pilha P) {
    if (P.topo == -1) {
        printf("Pilha Vazia");
        return '\0';
    } else {
        return P.elementos[P.topo];
    }
}

void mostrarPilha(Pilha P) {
    int i;
    for (i = P.topo; i >= 0; i--) {
        printf("%c", P.elementos[i]);
    }
}

int main() {
    Pilha P;
    int op;
    char c;

    printf("Operacoes com Pilha\n");
    do {
        printf("1 - Iniciar Pilha\n");
        printf("2 - Empilhar\n");
        printf("3 - Desempilhar\n");
        printf("4 - Mostrar Elementos do Topo\n");
        printf("5 - Mostrar Pilha\n");
        printf("6 - Sair\n");
        printf("\nSua Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                iniciarPilha(&P);
                break;
            case 2:
                printf("Digite o Caracter a ser Inserido na Pilha: ");
                scanf(" %c", &c); // espaço antes do %c para consumir o '\n' que ficou no buffer
                push(&P, c);
                break;
            case 3:
                pop(&P);
                break;
            case 4:
                c = mostrarTopo(P);
                printf("Elemento no Topo: %c\n", c);
                break;
            case 5:
                printf("Pilha: ");
                mostrarPilha(P);
                printf("\n");
                break;
            case 6:
                printf("Saindo do Programa...\n");
                break;
            default:
                printf("Opcao Invalida!\n");
                break;
        }
    } while (op != 6);

    return 0;
}
