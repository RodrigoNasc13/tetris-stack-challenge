<div align="center">

![Tetris Stack Banner](https://img.shields.io/badge/🎮_TETRIS_STACK-Gerenciador_de_Peças-blueviolet?style=for-the-badge)

# 🎮 Tetris Stack - Gerenciador de Peças

### *Domine filas e pilhas no clássico jogo de blocos!*

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![Status](https://img.shields.io/badge/Status-✅_Concluído-success?style=for-the-badge)](https://github.com)

**Trabalho Acadêmico - Faculdade Estácio**

---

</div>

## 📖 Sobre o Projeto

Implementação completa de um **sistema de gerenciamento de peças do Tetris** em linguagem C, desenvolvido para a disciplina de **Estruturas de Dados** da **Faculdade Estácio**. O projeto aplica conceitos fundamentais de estruturas de dados lineares através de três níveis progressivos de dificuldade.

<div align="center">

### 🎯 Conceitos Aplicados

| 📦 Estruturas | 🔄 Operações | 🎮 Mecânicas |
|:-------------:|:------------:|:------------:|
| Fila Circular | FIFO | Enqueue/Dequeue |
| Pilha Linear | LIFO | Push/Pop |
| Structs | Troca | Modularização |

</div>

---

## 🚀 Funcionalidades Principais

<table>
<tr>
<td width="50%" valign="top">

### 🎯 Sistema de Fila
```
📥 Inserção automática (enqueue)
📤 Remoção da frente (dequeue)
🔄 Estrutura circular
📊 Visualização em tempo real
```

</td>
<td width="50%" valign="top">

### 📚 Sistema de Pilha
```
⬆️ Empilhar peças (push)
⬇️ Desempilhar peças (pop)
🔀 Trocas estratégicas
✅ Validações inteligentes
```

</td>
</tr>
</table>

### 🎲 Tipos de Peças

<div align="center">

| 🧩 Peça | 📝 Tipo | 🎨 Forma |
|---------|---------|----------|
| **I** | Linha | ████ |
| **O** | Quadrado | ██<br>██ |
| **T** | T-shape | █<br>███ |
| **L** | L-shape | █<br>█<br>██ |

</div>

---

## 🎯 Níveis de Desenvolvimento

<div align="center">

```
┌──────────────────────────────────────────────────────────────────┐
│                                                                  │
│  📘 NOVATO  ─────▶  📙 AVENTUREIRO  ─────▶  📕 MESTRE          │
│                                                                  │
│  Fila Básica      Fila + Pilha         Trocas Estratégicas     │
│  • FIFO           • LIFO               • Troca Unitária         │
│  • Enqueue        • Push/Pop           • Troca Múltipla         │
│  • Dequeue        • Reserva            • Integração Completa    │
│                                                                  │
└──────────────────────────────────────────────────────────────────┘
```

</div>

<details>
<summary><b>📘 Nível Novato - Fundamentos da Fila</b></summary>

**Objetivo:** Implementar fila circular de peças futuras

**Implementações:**
- Fila circular com capacidade fixa (5 peças)
- Operações básicas: enqueue e dequeue
- Geração automática de peças
- Visualização da fila

**Funcionalidades:**
- ✅ Jogar peça (remove da frente)
- ✅ Inserir nova peça (adiciona ao final)
- ✅ Visualizar estado da fila

**Entregável:** Sistema FIFO funcional

</details>

<details>
<summary><b>📙 Nível Aventureiro - Pilha de Reserva</b></summary>

**Objetivo:** Adicionar pilha de peças reservadas

**Implementações:**
- Pilha linear com capacidade limitada (3 peças)
- Operações push e pop
- Movimentação entre fila e pilha
- Geração automática após remoções

**Funcionalidades:**
- ✅ Jogar peça da fila
- ✅ Reservar peça (fila → pilha)
- ✅ Usar peça reservada (remove da pilha)
- ✅ Visualizar fila e pilha simultaneamente

**Entregável:** Sistema integrado fila + pilha

</details>

<details>
<summary><b>📕 Nível Mestre - Operações Estratégicas</b></summary>

**Objetivo:** Implementar trocas entre estruturas

**Implementações:**
- Troca unitária (frente da fila ↔ topo da pilha)
- Troca múltipla (3 peças da fila ↔ 3 da pilha)
- Validações avançadas
- Preservação da ordem nas estruturas

**Funcionalidades:**
- ✅ Todas as operações anteriores
- ✅ Trocar peça atual
- ✅ Trocar 3 primeiras da fila com 3 da pilha
- ✅ Validação de quantidades mínimas

**Entregável:** Gerenciador completo de peças

</details>

---

## 💻 Como Executar

### 📋 Pré-requisitos
- Compilador GCC (MinGW para Windows)
- Sistema operacional Windows

### ⚙️ Compilação
```bash
gcc tetris-stack-challenge.c -o tetris-stack
```

### ▶️ Execução
```bash
.\tetris-stack
```

---

## 🎮 Como Usar

### 📊 Exemplo de Execução

```
========== INICIALIZANDO TETRIS STACK ==========
[INFO] Gerando 5 peças iniciais para a fila...

  1. Peça [T 0] adicionada.
  2. Peça [O 1] adicionada.
  3. Peça [L 2] adicionada.
  4. Peça [I 3] adicionada.
  5. Peça [I 4] adicionada.

[INFO] Fila inicializada com sucesso!
-----------------------------------------------

---------------------------------------------
              ESTADO ATUAL
---------------------------------------------
Fila de peças: [T 0] [O 1] [L 2] [I 3] [I 4] 
Pilha de reserva (Topo -> Base): [VAZIA]
---------------------------------------------
Fila: 5/5 | Pilha: 0/3
---------------------------------------------

========== Tetris Stack - Controle de peças ==========
1 - Jogar peça da frente da fila
2 - Enviar peça da fila para a pilha de reserva
3 - Usar peça da pilha de reserva
4 - Trocar peça da frente da fila com o topo da pilha
5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
0 - Sair
-----------------------------------------------------
Escolha uma opção: 2

[SUCESSO] Peça [T 0] foi enviada para a pilha de reserva!
[INFO] Nova peça [L 5] adicionada à fila.
```

---

## 🏗️ Arquitetura do Código

<div align="center">

### 📦 Estruturas de Dados

</div>

```c
// Representação de uma peça do Tetris
typedef struct {
    char nome;      // Tipo da peça: 'I', 'O', 'T', 'L'
    int id;         // Identificador único da peça
} Peca;

// Estrutura da fila circular (FIFO)
typedef struct {
    Peca pecas[MAX_FILA];  // Array de peças (5)
    int frente;             // Índice da frente
    int tras;               // Índice de trás
    int tamanho;            // Quantidade atual
} FilaPecas;

// Estrutura da pilha de reserva (LIFO)
typedef struct {
    Peca pecas[MAX_PILHA];  // Array de peças (3)
    int topo;                // Índice do topo (-1 se vazia)
} PilhaReserva;
```

<div align="center">

### 🔧 Funções Principais

</div>

<table>
<tr>
<th>Função</th>
<th>Responsabilidade</th>
<th>Estrutura</th>
</tr>
<tr>
<td><code>enqueue()</code></td>
<td>Insere peça na fila</td>
<td>Fila</td>
</tr>
<tr>
<td><code>dequeue()</code></td>
<td>Remove peça da fila</td>
<td>Fila</td>
</tr>
<tr>
<td><code>push()</code></td>
<td>Empilha peça na reserva</td>
<td>Pilha</td>
</tr>
<tr>
<td><code>pop()</code></td>
<td>Desempilha peça da reserva</td>
<td>Pilha</td>
</tr>
<tr>
<td><code>jogarPeca()</code></td>
<td>Remove e gera nova peça</td>
<td>Fila</td>
</tr>
<tr>
<td><code>reservarPeca()</code></td>
<td>Move fila → pilha</td>
<td>Fila + Pilha</td>
</tr>
<tr>
<td><code>trocarPecaAtual()</code></td>
<td>Troca frente ↔ topo</td>
<td>Fila + Pilha</td>
</tr>
<tr>
<td><code>trocaMultipla()</code></td>
<td>Troca 3 ↔ 3</td>
<td>Fila + Pilha</td>
</tr>
<tr>
<td><code>gerarPeca()</code></td>
<td>Cria peça aleatória</td>
<td>Utilidade</td>
</tr>
</table>

---

## ✅ Requisitos Atendidos

<div align="center">

| Categoria | Implementação | Status |
|:---------:|:-------------:|:------:|
| **Fila Circular** | Estrutura com reaproveitamento | ✅ |
| **Pilha Linear** | Estrutura LIFO | ✅ |
| **Structs** | Peca, FilaPecas, PilhaReserva | ✅ |
| **Modularização** | 15+ funções especializadas | ✅ |
| **Aleatoriedade** | Geração de peças | ✅ |
| **Validações** | Todas as operações | ✅ |
| **Interface** | Mensagens claras | ✅ |
| **Documentação** | Código comentado | ✅ |

### 🎯 Validações Implementadas

```
✓ Fila não pode ficar vazia
✓ Pilha limitada a 3 peças
✓ Troca múltipla requer 3 peças em cada estrutura
✓ Geração automática após remoções
✓ IDs únicos e sequenciais
✓ Preservação da ordem circular/LIFO
```

</div>

---

## 🛠️ Stack Tecnológica

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-MinGW-red?style=for-the-badge)
![VS Code](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

### 📚 Bibliotecas Utilizadas

`stdio.h` • `stdlib.h` • `time.h` • `windows.h`

</div>

---

## 🎨 Diferenciais do Projeto

<div align="center">

| 🌟 Feature | 📝 Descrição |
|-----------|-------------|
| **Fila Circular Eficiente** | Reaproveitamento de espaço com índices modulares |
| **Geração Automática** | Mantém fila sempre cheia após operações |
| **Sistema de IDs** | Rastreamento único de cada peça |
| **Trocas Estratégicas** | Permite reorganização entre estruturas |
| **Feedback Detalhado** | Mensagens informativas para cada ação |
| **Código Limpo** | Organizado em seções comentadas |

</div>

---

## 📊 Operações Suportadas

<div align="center">

### 🎮 Menu Completo (Nível Mestre)

| Código | Operação | Estrutura Afetada |
|:------:|----------|-------------------|
| **1** | Jogar peça | 📤 Fila (dequeue + enqueue) |
| **2** | Reservar peça | 📤 Fila → 📥 Pilha |
| **3** | Usar peça reservada | 📤 Pilha (pop) |
| **4** | Trocar peça atual | 🔄 Fila ↔ Pilha (1×1) |
| **5** | Trocar múltiplas | 🔀 Fila ↔ Pilha (3×3) |
| **0** | Sair | 🚪 Encerra programa |

</div>

---

## 🎓 Informações Acadêmicas

**Instituição:** Faculdade Estácio  
**Disciplina:** Estruturas de Dados  
**Tema:** Filas Circulares e Pilhas  
**Linguagem:** C (C99)  
**Paradigma:** Programação Estruturada  

### 📚 Conceitos Trabalhados

- ✅ Fila Circular (FIFO)
- ✅ Pilha Linear (LIFO)
- ✅ Structs e Arrays
- ✅ Ponteiros e Passagem por Referência
- ✅ Modularização
- ✅ Validação de Dados
- ✅ Geração Aleatória

---

<div align="center">

### 📄 Licença

Este projeto foi desenvolvido exclusivamente para fins educacionais.

---

### 💜 Desenvolvido com dedicação

*"Estruturas de dados são a fundação de toda solução elegante."*

⭐ **Se este projeto ajudou nos seus estudos, considere deixar uma estrela!**

</div>