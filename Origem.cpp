/*
* Atividade Prática - Exercício 3
* Aluno: Marcos Fabricio Sizanosky RU-3395570
* Professor: Winston Sen Lun Fung
* Data criação: 30/04/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Variável global usada em funções para iterar como índice de uma matriz.
int lin, col;

// Função para limpar o buffer do teclado após um "scanf_s".
void limpa_buffer_teclado();
// Função para preencher uma matriz 4x4.
void preenche_matriz(int* matriz);
// Função para imprimir os dados de uma matriz 4x4.
void imprime_matriz(int* matriz);
// Função calcula a soma dos elementos das matrizes A e B.
void calc_soma(int* mat_A, int* mat_B, int* mat_C);

int main() {
    printf("Hello World!\n\n");

    // Função para habilitar a utilização de caracteres da língua portuguesa.
    setlocale(LC_ALL, "Portuguese");

    // Declaração de matrizes e ponteiros.
    int matriz_A[4][4] = { 0 }, * p_mat_A; // Matriz 4x4 de números inteiros.
    int matriz_B[4][4] = { 0 }, * p_mat_B; // Matriz 4x4 de números inteiros.
    int matriz_C[4][4] = { 0 }, * p_mat_C; // Matriz resultado da soma das matrizes A e B.

    // Ponteiros para as matrizes A,B,C.
    p_mat_A = &matriz_A[0][0];
    p_mat_B = &matriz_B[0][0];
    p_mat_C = &matriz_C[0][0];

    // Cabeçalho do programa e informações ao usuário.
    printf("+=+=+=+=+=+= SOMA DE DUAS MATRIZES 4x4 =+=+=+=+=+=+\n\n");
    printf("- Preencha as matrizes A e B (use somente números inteiros).\n");
    printf("- Visualize na tela a soma de todos os dados inseridos.\n\n");

    printf("++++ Preencha a matriz A ++++\n");
    preenche_matriz(p_mat_A); // Chamada de função.

    printf("\n++++ Preencha a matriz B ++++\n");
    preenche_matriz(p_mat_B); // Chamada de função.

    printf("\n++++ Soma das matrizes A+B ++++\n");
    calc_soma(p_mat_A, p_mat_B, p_mat_C); // Chamada de função.

    printf("\n==== Dados Matriz A ====\n");
    imprime_matriz(p_mat_A); // Chamada de função.
    printf("\n==== Dados Matriz B ====\n");
    imprime_matriz(p_mat_B); // Chamada de função.
    printf("\n==== Dados Matriz C ====\n");
    imprime_matriz(p_mat_C); // Chamada de função.

    return 0;
}

// Funções.

void limpa_buffer_teclado() {
    /* Está função é utilizada para limpar o buffer do teclado após
     * um "scanf_s".*/

    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void preenche_matriz(int* matriz) {
    /* Recebe uma matriz 4x4 como argumento, solicita as entradas do usuário.
     * Loop "for" percorre linha e coluna da matriz e scanf_s adiciona o
     * dado ao índice iterado.
     * if (verifica se o valor é negativo) "true" encerra o programa.
     * else segue para o próximo índice da iteração.
     * */

    int pos = 0;
    for (lin = 0; lin < 4; lin++)
        for (col = 0; col < 4; col++) {
            printf("Dígito para (%iª linha / %iª coluna): ", lin + 1, col + 1);
            scanf_s("%d", &matriz[pos]);
            limpa_buffer_teclado();
            pos++;

            if (*(matriz + lin * 4 + col) <= -1) {
                printf("\n*ERRO! Números negativos não são permitidos!\n");
                printf("Encerrando o programa...\n");
                exit(1);
            }
            else {
                continue;
            }
        }
}

void imprime_matriz(int* matriz) {
    /* Recebe o ponteiro de uma matriz como argumento e imprime na tela
     * os dados da matriz formatados como uma tabela (4 linhas x 4 colunas).
     */

    for (lin = 0; lin < 4; lin++)
        for (col = 0; col < 4; col++) {
            printf("%5d", *(matriz + lin * 4 + col));
            if (col == 3) { // Quebra de linha.
                printf("\n");
            }
        }
}

void calc_soma(int* mat_A, int* mat_B, int* mat_C) {
    /* Esta função utiliza ponteiro para fazer a soma de duas matrizes
     * (*mat_A + *mat_B) e o resultado da soma é armazenado em uma terceira
     * matriz (*mat_C).
     */

    for (lin = 0; lin < 4; lin++)
        for (col = 0; col < 4; col++) {
            *mat_C++ = (*mat_A++) + (*mat_B++);
        }
}