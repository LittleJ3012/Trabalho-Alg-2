#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include "projeto.h"

#define MAX 1000 

// FUNÇÕES PARA GERAR OS VETORES

int *geraAleatorios(int tam, int semente) {
    int *vet = (int *) malloc(tam * sizeof(int));
    if (!vet) return NULL;

    srand(semente);
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % MAX;
    }
    return vet;
}

int *geraQuaseOrdenados(int tam, int porcentagem) {
    int *vet = (int *) malloc(tam * sizeof(int));
    if (!vet) return NULL;

    for (int i = 0; i < tam; i++) {
        vet[i] = i;
    }

    int num_trocas = tam * porcentagem / 100;
    for (int i = 0; i < num_trocas; i++) {
        int pos1 = rand() % tam;
        int pos2 = rand() % tam;
        int aux = vet[pos1];
        vet[pos1] = vet[pos2];
        vet[pos2] = aux;
    }

    return vet;
}

int *geraOrdenados(int tam, int ordem) {
    int *vet = (int *) malloc(tam * sizeof(int));
    if (!vet) return NULL;

    for (int i = 0; i < tam; i++) {
        vet[i] = i;
    }

    if (ordem != 0) {
        for (int i = 0; i < tam / 2; i++) {
            int aux = vet[i];
            vet[i] = vet[tam - 1 - i];
            vet[tam - 1 - i] = aux;
        }
    }

    return vet;
}

// ALGORITMOS DE ORDENAÇÃO

long long int *bolha(int *vet, int tam, long long int *vet_info) {
    int aux;
    for (int i = 0; i < tam; i++) {
        for (int j = 1; j < tam; j++) {
            if (vet[j] < vet[j - 1]) {
                aux = vet[j - 1];
                vet[j - 1] = vet[j];
                vet[j] = aux;
                vet_info[0]++;
            }
            vet_info[1]++;
        }
    }
    return vet_info;
}

long long int *bolhaInteligente(int *vet, int tam, long long int *vet_info) {
    int aux, troca;
    for (int i = 0; i < tam; i++) {
        troca = 0;
        for (int j = 1; j < tam - i; j++) {
            if (vet[j] < vet[j - 1]) {
                aux = vet[j - 1];
                vet[j - 1] = vet[j];
                vet[j] = aux;
                vet_info[0]++;
                troca = 1;
            }
            vet_info[1]++;
        }
        if (!troca) break;
    }
    return vet_info;
}

long long int *selecao(int *vet, int tam, long long int *vet_info) {
    int marcador = 0, menor, aux;
    while (marcador < tam - 1) {
        menor = encontraMenor(vet, tam, marcador + 1, vet_info);
        if (vet[menor] < vet[marcador]) {
            aux = vet[marcador];
            vet[marcador] = vet[menor];
            vet[menor] = aux;
            vet_info[0]++;
        }
        vet_info[1]++;
        marcador++;
    }
    return vet_info;
}

int encontraMenor(int *vet, int tam, int inicio, long long int *vet_info) {
    int menor = vet[inicio], indice_menor = inicio;
    for (int i = inicio + 1; i < tam; i++) {
        if (vet[i] < menor) {
            menor = vet[i];
            indice_menor = i;
        }
        vet_info[1]++;
    }
    return indice_menor;
}

long long int *insercao(int *vet, int tam, long long int *vet_info) {
    int marcador, aux, pos;
    for (marcador = 1; marcador < tam; marcador++) {
        aux = vet[marcador];
        pos = marcador - 1;

        while (pos >= 0 && aux < vet[pos]) {
            vet[pos + 1] = vet[pos];
            pos--;
            vet_info[0]++;
            vet_info[1]++;
        }
        vet_info[1]++;
        vet[pos + 1] = aux;
        vet_info[0] = vet_info[0] + 1;
    }
    return vet_info;
}

long long int *mergeSort(int *vet, int inicio, int fim, long long int *vet_info) {
    vet_info[2]++;
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio, vet_info);
        mergeSort(vet, meio + 1, fim, vet_info);
        merge(vet, inicio, meio, fim, vet_info);
    }
    return vet_info;
}

void merge(int *vet, int inicio, int meio, int fim, long long int *vet_info) {
    int i, m1 = 0, m2 = 0;
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;
    int tam3 = fim - inicio + 1;

    int *vet1 = malloc(tam1 * sizeof(int));
    int *vet2 = malloc(tam2 * sizeof(int));
    int *vet_aux = malloc(tam3 * sizeof(int));

    for (i = 0; i < tam1; i++) vet1[i] = vet[inicio + i];
    for (i = 0; i < tam2; i++) vet2[i] = vet[meio + 1 + i];

    i = 0;
    while (m1 < tam1 && m2 < tam2) {
        if (vet1[m1] < vet2[m2]) {
            vet_aux[i++] = vet1[m1++];
        } else {
            vet_aux[i++] = vet2[m2++];
        }
        vet_info[1]++;
    }

    while (m1 < tam1) vet_aux[i++] = vet1[m1++];
    while (m2 < tam2) vet_aux[i++] = vet2[m2++];

    for (i = 0; i < tam3; i++) {
        vet[inicio + i] = vet_aux[i];
    }

    free(vet1);
    free(vet2);
    free(vet_aux);
}

long long int *quickSort(int *vet, int inicio, int fim, long long int *vet_info) {
    vet_info[2]++; // conta chamada da função
    if (inicio < fim) {
        int pivo = particiona(vet, inicio, fim, vet_info);
        quickSort(vet, inicio, pivo - 1, vet_info);
        quickSort(vet, pivo + 1, fim, vet_info);
    }
    return vet_info;
}

int particiona(int *vet, int inicio, int fim, long long int *vet_info) {
    // Seleciona um índice aleatório entre inicio e fim
    int pivo_index = inicio + rand() % (fim - inicio + 1);

    // Move o pivô para o início do vetor
    int tmp = vet[inicio];
    vet[inicio] = vet[pivo_index];
    vet[pivo_index] = tmp;
    vet_info[0]++; // conta troca

    int pivo = vet[inicio];
    int pos = inicio;

    for (int i = inicio + 1; i <= fim; i++) {
        vet_info[1]++; // conta comparação
        if (vet[i] < pivo) {
            pos++;
            if (pos != i) {
                tmp = vet[pos];
                vet[pos] = vet[i];
                vet[i] = tmp;
                vet_info[0]++; // conta troca
            }
        }
    }

    // Coloca o pivô na posição final correta
    tmp = vet[pos];
    vet[pos] = vet[inicio];
    vet[inicio] = tmp;
    vet_info[0]++; // conta troca final do pivô

    return pos;
}



//FUNÇÕES DO BLOCKSORT (ALGORITIMO NOVO):

// Troca com contagem
void trocar(int* a, int* b, long long int *vet_info) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    vet_info[0]++; // Conta a troca
}

// Insertion sort com contagem
void insertionSort(int vet[], int inicio, int fim, long long int *vet_info) {
    for (int marcador = inicio + 1; marcador < fim; marcador++) {
        int aux = vet[marcador];
        int posicao = marcador - 1;
        while (posicao >= inicio) {
            vet_info[1]++; // comparação
            if (vet[posicao] > aux) {
                vet[posicao + 1] = vet[posicao];
                vet_info[0]++; // troca (mesmo que seja um shift, conta como modificação)
                posicao--;
            } else break;
        }
        vet[posicao + 1] = aux;
    }
}

// Merge com buffer com contagem
void mergeComBuffer(int vet[], int inicio, int meio, int fim, int *buffer, int tamanhoBuffer, long long int *vet_info) {
    for (int k = 0; k < tamanhoBuffer; k++) {
        buffer[k] = vet[inicio + k];
    }

    int i = 0;
    int j = meio;
    int atual = inicio;

    while (i < tamanhoBuffer && j < fim) {
        vet_info[1]++; // comparação
        if (buffer[i] <= vet[j]) {
            vet[atual++] = buffer[i++];
            vet_info[0]++; // troca
        } else {
            vet[atual++] = vet[j++];
            vet_info[0]++; // troca
        }
    }

    while (i < tamanhoBuffer) {
        vet[atual++] = buffer[i++];
        vet_info[0]++; // troca
    }
}

// BlockSort completo com contadores
long long int *blockSort(int *vet, int inicio, int fim, long long int *vet_info) {

    int tam = fim - inicio + 1;
    int *subvet = vet + inicio;

    int tamanhoBloco = (int)sqrt(tam);
    if (tamanhoBloco == 0) tamanhoBloco = 1;
    int quantidadeBlocos = (tam + tamanhoBloco - 1) / tamanhoBloco;

    // Ordenar blocos individualmente
    for (int i = 0; i < tam; i += tamanhoBloco) {
        int fimB = i + tamanhoBloco;
        if (fimB > tam) fimB = tam;
        insertionSort(subvet, i, fimB, vet_info);
    }

    // Selection sort entre blocos baseado no menor elemento
    for (int i = 0; i < quantidadeBlocos - 1; i++) {
        int BlocoMenor = i;
        int inicioA = i * tamanhoBloco;

        for (int j = i + 1; j < quantidadeBlocos; j++) {
            int inicioB = j * tamanhoBloco;
            if (inicioB >= tam) break;

            vet_info[1]++; // comparação
            if (subvet[inicioB] < subvet[inicioA]) {
                BlocoMenor = j;
            }
        }

        if (BlocoMenor != i) {
            int inicio1 = i * tamanhoBloco;
            int inicio2 = BlocoMenor * tamanhoBloco;
            for (int k = 0; k < tamanhoBloco && inicio2 + k < tam; k++) {
                trocar(&subvet[inicio1 + k], &subvet[inicio2 + k], vet_info);
            }
        }
    }

    // Merge entre blocos com buffer
    int tamanhoAtual = tamanhoBloco;
    while (tamanhoAtual < tam) {
        for (int i = 0; i < tam; i += 2 * tamanhoAtual) {
            int inicioM = i;
            int meio = i + tamanhoAtual;
            int fimM = i + 2 * tamanhoAtual;

            if (meio >= tam) break;
            if (fimM > tam) fimM = tam;

            int tamanhoBuffer = meio - inicioM;
            int *buffer = (int *)malloc(tamanhoBuffer * sizeof(int));
            if (!buffer) return vet_info;

            mergeComBuffer(subvet, inicioM, meio, fimM, buffer, tamanhoBuffer, vet_info);
            free(buffer);
        }
        tamanhoAtual *= 2;
    }

    return vet_info;
}


// UTILITÁRIOS

void imprimeVet(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d\t", vet[i]);
    }
    printf("\n\n");
}

void reseta_vet_info(long long int *vet_info) {
    for (int i = 0; i < 4; i++) vet_info[i] = 0;
}

int *copiaVet(int *vetor, int tam) {
    int *copia = malloc(tam * sizeof(int));
    if (!copia) return NULL;
    for (int i = 0; i < tam; i++) {
        copia[i] = vetor[i];
    }
    return copia;
}

// Mede o tempo de execução de algoritmos quadráticos (sem recursão),
// como bubble sort, selection sort, insertion sort, etc.
// Parâmetros:
// alg: ponteiro para a função de ordenação
// vetor: vetor de inteiros a ser ordenado
// tam: tamanho do vetor
// vet_info: vetor de métricas [trocas, comparações, chamadas, tempo]
void mede_tempo_execucao_quadratico(long long int *(*alg)(int *, int, long long int *), int *vetor, int tam, long long int *vet_info) {
    struct timeval inicio, fim; // Estruturas para armazenar tempo inicial e final

    gettimeofday(&inicio, NULL); // Captura o tempo antes da execução do algoritmo
    alg(vetor, tam, vet_info);   // Chamada do algoritmo de ordenação
    gettimeofday(&fim, NULL);    // Captura o tempo após a execução

    // Calcula o tempo total em microssegundos (µs) e armazena em vet_info[3]
    vet_info[3] = (fim.tv_sec - inicio.tv_sec) * 1000000L + (fim.tv_usec - inicio.tv_usec);
}


// Mede o tempo de execução de algoritmos recursivos (com limites de início e fim),
// como merge sort, quick sort, block sort, etc.
// Parâmetros:
// alg: ponteiro para a função de ordenação recursiva
// vetor: vetor de inteiros a ser ordenado
// ini: índice inicial da faixa a ser ordenada
// fim: índice final da faixa a ser ordenada
// vet_info: vetor de métricas [trocas, comparações, chamadas, tempo]
void mede_tempo_execucao_recursivo(long long int *(*alg)(int *, int, int, long long int *), int *vetor, int ini, int fim, long long int *vet_info) {
    struct timeval inicio_exec, fim_exec; // Estruturas para armazenar tempo inicial e final

    gettimeofday(&inicio_exec, NULL);     // Captura o tempo antes da execução do algoritmo
    alg(vetor, ini, fim, vet_info);       // Chamada do algoritmo de ordenação
    gettimeofday(&fim_exec, NULL);        // Captura o tempo após a execução

    // Calcula o tempo total em microssegundos (µs) e armazena em vet_info[3]
    vet_info[3] = (fim_exec.tv_sec - inicio_exec.tv_sec) * 1000000L + (fim_exec.tv_usec - inicio_exec.tv_usec);
}



void salvar_resultado(const char *nome, long long int *vet_info, int tam) {
    // Formar o nome do arquivo com base no nome do algoritmo
    char nomeArquivo[100];
    snprintf(nomeArquivo, sizeof(nomeArquivo), "%s.txt", nome);

    // Abrir o arquivo correspondente ao algoritmo (modo append)
    FILE *arquivo = fopen(nomeArquivo, "a+");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Checar se o arquivo está vazio para imprimir cabeçalho e nome do algoritmo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    if (tamanho == 0) {
        fprintf(arquivo, "--- %s ---\n", nome);
        fprintf(arquivo, "Tempo\tComparacao\tTroca\tChamadas\n");
    }

    // Adicionar os dados do teste
    fprintf(arquivo, "%lld\t%lld\t%lld\t\t%lld\n", vet_info[3], vet_info[1], vet_info[0], vet_info[2]);

    fclose(arquivo);
}

