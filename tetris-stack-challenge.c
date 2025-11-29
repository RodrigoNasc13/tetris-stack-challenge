#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_FILA 5
#define MAX_PILHA 3

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

// Estrutura da pilha de reserva
typedef struct {
    Peca pecas[MAX_PILHA];  // Array de peças reservadas
    int topo;                // Índice do topo da pilha (-1 se vazia)
} PilhaReserva;

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

// FUNÇÕES DA FILA 

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
        return 0;
    }
    
    // Calcula a nova posição traseira (circular)
    fila->tras = (fila->tras + 1) % MAX_FILA;
    fila->pecas[fila->tras] = peca;
    fila->tamanho++;
    
    return 1;
}

// Função para remover uma peça da fila (dequeue)
int dequeue(FilaPecas *fila, Peca *peca) {
    if (filaVazia(fila)) {
        return 0;
    }
    
    // Remove a peça da frente
    *peca = fila->pecas[fila->frente];
    fila->frente = (fila->frente + 1) % MAX_FILA;
    fila->tamanho--;
    
    return 1;
}

// FUNÇÕES DA PILHA

// Função para inicializar a pilha
void inicializarPilha(PilhaReserva *pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(PilhaReserva *pilha) {
    return pilha->topo == -1;
}

// Função para verificar se a pilha está cheia
int pilhaCheia(PilhaReserva *pilha) {
    return pilha->topo == MAX_PILHA - 1;
}

// Função para empilhar uma peça (push)
int push(PilhaReserva *pilha, Peca peca) {
    if (pilhaCheia(pilha)) {
        return 0;
    }
    
    pilha->topo++;
    pilha->pecas[pilha->topo] = peca;
    
    return 1;
}

// Função para desempilhar uma peça (pop)
int pop(PilhaReserva *pilha, Peca *peca) {
    if (pilhaVazia(pilha)) {
        return 0;
    }
    
    *peca = pilha->pecas[pilha->topo];
    pilha->topo--;
    
    return 1;
}

// FUNÇÕES DE EXIBIÇÃO

// Função para exibir o estado atual da fila
void exibirFila(FilaPecas *fila) {
    printf("Fila de peças: ");
    
    if (filaVazia(fila)) {
        printf("[VAZIA]");
    } else {
        int i;
        int indice = fila->frente;
        
        for (i = 0; i < fila->tamanho; i++) {
            printf("[%c %d] ", fila->pecas[indice].nome, fila->pecas[indice].id);
            indice = (indice + 1) % MAX_FILA;
        }
    }
    printf("\n");
}

// Função para exibir o estado atual da pilha
void exibirPilha(PilhaReserva *pilha) {
    printf("Pilha de reserva (Topo -> Base): ");
    
    if (pilhaVazia(pilha)) {
        printf("[VAZIA]");
    } else {
        int i;
        // Exibe do topo para a base
        for (i = pilha->topo; i >= 0; i--) {
            printf("[%c %d] ", pilha->pecas[i].nome, pilha->pecas[i].id);
        }
    }
    printf("\n");
}

// Função para exibir o estado completo do jogo
void exibirEstado(FilaPecas *fila, PilhaReserva *pilha) {
    printf("\n---------------------------------------------\n");
    printf("              ESTADO ATUAL\n");
    printf("---------------------------------------------\n");
    exibirFila(fila);
    exibirPilha(pilha);
    printf("---------------------------------------------\n");
    printf("Fila: %d/%d | Pilha: %d/%d\n", fila->tamanho, MAX_FILA, pilha->topo + 1, MAX_PILHA);
    printf("---------------------------------------------\n");
}

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n========== Tetris Stack - Controle de peças ==========\n");
    printf("1 - Jogar peça da frente da fila\n");
    printf("2 - Enviar peça da fila para a pilha de reserva\n");
    printf("3 - Usar peça da pilha de reserva\n");
    printf("4 - Trocar peça da frente da fila com o topo da pilha\n");
    printf("5 - Trocar os 3 primeiros da fila com as 3 peças da pilha\n");
    printf("0 - Sair\n");
    printf("-----------------------------------------------------\n");
    printf("Escolha uma opção: ");
}

// FUNÇÕES DE AÇÕES DO JOGO

// Função para jogar uma peça (remove da fila e adiciona nova)
void jogarPeca(FilaPecas *fila) {
    Peca pecaJogada;
    
    if (dequeue(fila, &pecaJogada)) {
        printf("\n[SUCESSO] Peça [%c %d] foi jogada!\n", pecaJogada.nome, pecaJogada.id);
        
        // Adiciona uma nova peça automaticamente à fila
        Peca novaPeca = gerarPeca();
        enqueue(fila, novaPeca);
        printf("[INFO] Nova peça [%c %d] adicionada à fila.\n", novaPeca.nome, novaPeca.id);
    } else {
        printf("\n[ERRO] Fila vazia! Não há peças para jogar.\n");
    }
}

// Função para reservar uma peça (move da fila para a pilha)
void reservarPeca(FilaPecas *fila, PilhaReserva *pilha) {
    if (pilhaCheia(pilha)) {
        printf("\n[ERRO] Pilha de reserva cheia! Não é possível reservar mais peças.\n");
        return;
    }
    
    if (filaVazia(fila)) {
        printf("\n[ERRO] Fila vazia! Não há peças para reservar.\n");
        return;
    }
    
    Peca pecaReservada;
    
    if (dequeue(fila, &pecaReservada)) {
        if (push(pilha, pecaReservada)) {
            printf("\n[SUCESSO] Peça [%c %d] foi enviada para a pilha de reserva!\n", pecaReservada.nome, pecaReservada.id);
            
            // Adiciona uma nova peça automaticamente à fila
            Peca novaPeca = gerarPeca();
            enqueue(fila, novaPeca);
            printf("[INFO] Nova peça [%c %d] adicionada à fila.\n", novaPeca.nome, novaPeca.id);
        }
    }
}

// Função para usar uma peça reservada (remove da pilha)
void usarPecaReservada(PilhaReserva *pilha) {
    Peca pecaUsada;
    
    if (pop(pilha, &pecaUsada)) {
        printf("\n[SUCESSO] Peça reservada [%c %d] foi usada!\n", pecaUsada.nome, pecaUsada.id);
    } else {
        printf("\n[ERRO] Pilha vazia! Não há peças reservadas para usar.\n");
    }
}

// Função para trocar a peça da frente da fila com o topo da pilha
void trocarPecaAtual(FilaPecas *fila, PilhaReserva *pilha) {
    if (filaVazia(fila)) {
        printf("\n[ERRO] Fila vazia! Não há peça para trocar.\n");
        return;
    }
    
    if (pilhaVazia(pilha)) {
        printf("\n[ERRO] Pilha vazia! Não há peça reservada para trocar.\n");
        return;
    }
    
    // Guarda temporariamente a peça da frente da fila
    Peca pecaFila = fila->pecas[fila->frente];
    
    // Guarda temporariamente a peça do topo da pilha
    Peca pecaPilha = pilha->pecas[pilha->topo];
    
    // Realiza a troca
    fila->pecas[fila->frente] = pecaPilha;
    pilha->pecas[pilha->topo] = pecaFila;
    
    printf("\n[SUCESSO] Troca realizada!\n");
    printf("  -> Peça [%c %d] da fila foi para a pilha.\n", pecaFila.nome, pecaFila.id);
    printf("  -> Peça [%c %d] da pilha foi para a fila.\n", pecaPilha.nome, pecaPilha.id);
}

// Função para trocar as 3 primeiras peças da fila com as 3 da pilha
void trocaMultipla(FilaPecas *fila, PilhaReserva *pilha) {
    // Verifica se a fila tem pelo menos 3 peças
    if (fila->tamanho < 3) {
        printf("\n[ERRO] A fila precisa ter pelo menos 3 peças para realizar a troca múltipla.\n");
        printf("  -> Peças na fila: %d/%d\n", fila->tamanho, MAX_FILA);
        return;
    }
    
    // Verifica se a pilha tem exatamente 3 peças
    if (pilha->topo + 1 != 3) {
        printf("\n[ERRO] A pilha precisa ter exatamente 3 peças para realizar a troca múltipla.\n");
        printf("  -> Peças na pilha: %d/%d\n", pilha->topo + 1, MAX_PILHA);
        return;
    }
    
    printf("\n[INFO] Iniciando troca múltipla...\n");
    
    // Array temporário para armazenar as 3 primeiras peças da fila
    Peca tempFila[3];
    int i;
    int indice = fila->frente;
    
    // Copia as 3 primeiras peças da fila
    for (i = 0; i < 3; i++) {
        tempFila[i] = fila->pecas[indice];
        indice = (indice + 1) % MAX_FILA;
    }
    
    // Array temporário para armazenar as 3 peças da pilha
    Peca tempPilha[3];
    
    // Copia as 3 peças da pilha (do topo para a base)
    for (i = 0; i < 3; i++) {
        tempPilha[i] = pilha->pecas[pilha->topo - i];
    }
    
    // Coloca as peças da pilha nas 3 primeiras posições da fila
    indice = fila->frente;
    for (i = 0; i < 3; i++) {
        fila->pecas[indice] = tempPilha[i];
        indice = (indice + 1) % MAX_FILA;
    }
    
    // Coloca as peças da fila na pilha (invertendo a ordem para manter LIFO)
    for (i = 0; i < 3; i++) {
        pilha->pecas[pilha->topo - i] = tempFila[i];
    }
    
    printf("[SUCESSO] Troca múltipla realizada!\n");
    printf("  -> As 3 primeiras peças da fila foram trocadas com as 3 peças da pilha.\n");
}

// Função para popular a fila inicial com peças
void popularFilaInicial(FilaPecas *fila) {
    int i;
    printf("\n========== INICIALIZANDO TETRIS STACK ==========\n");
    printf("[INFO] Gerando %d peças iniciais para a fila...\n\n", MAX_FILA);
    
    for (i = 0; i < MAX_FILA; i++) {
        Peca peca = gerarPeca();
        enqueue(fila, peca);
        printf("  %d. Peça [%c %d] adicionada.\n", i + 1, peca.nome, peca.id);
    }
    printf("\n[INFO] Fila inicializada com sucesso!\n");
    printf("-----------------------------------------------\n");
}

// FUNÇÃO PRINCIPAL

int main() {
    // Configura codificação UTF-8 para Windows
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    FilaPecas fila;
    PilhaReserva pilha;
    int opcao;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Inicializa as estruturas
    inicializarFila(&fila);
    inicializarPilha(&pilha);
    
    // Popula a fila com peças iniciais
    popularFilaInicial(&fila);
    
    // Loop principal do programa
    do {
        exibirEstado(&fila, &pilha);
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: // Jogar peça (remove da fila)
                jogarPeca(&fila);
                break;
                
            case 2: // Reservar peça (move da fila para pilha)
                reservarPeca(&fila, &pilha);
                break;
                
            case 3: // Usar peça reservada (remove da pilha)
                usarPecaReservada(&pilha);
                break;
                
            case 4: // Trocar peça da frente da fila com topo da pilha
                trocarPecaAtual(&fila, &pilha);
                break;
                
            case 5: // Trocar 3 primeiras da fila com 3 da pilha
                trocaMultipla(&fila, &pilha);
                break;
                
            case 0: // Sair
                printf("\n---------------------------------------\n");
                printf("[INFO] Encerrando Tetris Stack...\n");
                printf("Obrigado por jogar!\n");
                printf("---------------------------------------\n");
                break;
                
            default:
                printf("\n[ERRO] Opção inválida! Tente novamente.\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}