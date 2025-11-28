#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_FILA 5

// Estrutura que representa uma peça do Tetris
typedef struct {
    char nome;  // Tipo da peça: 'I', 'O', 'T', 'L'
    int id;     // Identificador único da peça
} Peca;

// Estrutura da fila circular
typedef struct {
    Peca pecas[MAX_FILA];  // Array de peças
    int frente;             // Índice do elemento da frente
    int tras;               // Índice do elemento de trás
    int tamanho;            // Quantidade atual de elementos
} FilaPecas;

// Variável global para controlar o ID das peças
int proximoId = 0;

// Função para gerar uma peça aleatória
Peca gerarPeca() {
    Peca novaPeca;
    char tipos[] = {'I', 'O', 'T', 'L'};
    
    // Seleciona um tipo aleatório
    novaPeca.nome = tipos[rand() % 4];
    novaPeca.id = proximoId++;
    
    return novaPeca;
}

// Função para inicializar a fila
void inicializarFila(FilaPecas *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

// Função para verificar se a fila está vazia
int filaVazia(FilaPecas *fila) {
    return fila->tamanho == 0;
}

// Função para verificar se a fila está cheia
int filaCheia(FilaPecas *fila) {
    return fila->tamanho == MAX_FILA;
}

// Função para inserir uma peça na fila (enqueue)
int enqueue(FilaPecas *fila, Peca peca) {
    if (filaCheia(fila)) {
        printf("\n[ERRO] Fila cheia! Não é possível inserir nova peça.\n");
        return 0;
    }
    
    // Calcula a nova posição traseira (circular)
    fila->tras = (fila->tras + 1) % MAX_FILA;
    fila->pecas[fila->tras] = peca;
    fila->tamanho++;
    
    printf("\n[SUCESSO] Peça [%c %d] inserida na fila!\n", peca.nome, peca.id);
    return 1;
}

// Função para remover uma peça da fila (dequeue)
int dequeue(FilaPecas *fila, Peca *peca) {
    if (filaVazia(fila)) {
        printf("\n[ERRO] Fila vazia! Não há peças para jogar.\n");
        return 0;
    }
    
    // Remove a peça da frente
    *peca = fila->pecas[fila->frente];
    fila->frente = (fila->frente + 1) % MAX_FILA;
    fila->tamanho--;
    
    printf("\n[SUCESSO] Peça [%c %d] foi jogada!\n", peca->nome, peca->id);
    return 1;
}

// Função para exibir o estado atual da fila
void exibirFila(FilaPecas *fila) {
    printf("\n--------------------------------\n");
    printf("      Fila de peças\n");
    printf("--------------------------------\n");
    
    if (filaVazia(fila)) {
        printf("[VAZIA]\n");
    } else {
        int i;
        int indice = fila->frente;
        
        for (i = 0; i < fila->tamanho; i++) {
            printf("[%c %d] ", fila->pecas[indice].nome, fila->pecas[indice].id);
            indice = (indice + 1) % MAX_FILA;
        }
        printf("\n");
    }
    
    printf("--------------------------------\n");
    printf("Espaços ocupados: %d/%d\n", fila->tamanho, MAX_FILA);
    printf("--------------------------------\n");
}

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n--- Tetris Stack - Controle de peças ---\n");
    printf("1 - Jogar peça (dequeue)\n");
    printf("2 - Inserir nova peça (enqueue)\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

// Função para popular a fila inicial com peças
void popularFilaInicial(FilaPecas *fila) {
    int i;
    printf("\n[INFO] Inicializando fila com %d peças...\n", MAX_FILA);
    
    for (i = 0; i < MAX_FILA; i++) {
        Peca peca = gerarPeca();
        enqueue(fila, peca);
    }
}

int main() {
    // Configura codificação UTF-8 para Windows
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    FilaPecas fila;
    int opcao;
    Peca pecaRemovida;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Inicializa a fila
    inicializarFila(&fila);
    
    // Popula a fila com peças iniciais
    popularFilaInicial(&fila);
    
    // Loop principal do programa
    do {
        exibirFila(&fila);
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: // Jogar peça (dequeue)
                dequeue(&fila, &pecaRemovida);
                break;
                
            case 2: // Inserir nova peça (enqueue)
                if (!filaCheia(&fila)) {
                    Peca novaPeca = gerarPeca();
                    enqueue(&fila, novaPeca);
                } else {
                    printf("\n[ERRO] Fila cheia! Remova peças antes de inserir.\n");
                }
                break;
                
            case 0: // Sair
                printf("\n[INFO] Encerrando programa...\n");
                printf("Obrigado por jogar Tetris Stack!\n");
                break;
                
            default:
                printf("\n[ERRO] Opção inválida! Tente novamente.\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}