#ifndef PROJETO_H
#define PROJETO_H

// FUNÇÕES PARA GERAR O VETOR
int *geraAleatorios(int tam, int semente);
int *geraQuaseOrdenados(int tam, int porcentagem);
int *geraOrdenados(int tam, int ordem);

// ALGORITMOS DE ORDENAÇÃO
long long int *bolha(int *vet, int tam, long long int *vet_info);
long long int *bolhaInteligente(int *vet, int tam, long long int *vet_info);
long long int *selecao(int *vet, int tam, long long int *vet_info);
int encontraMenor(int *vet, int tam, int inicio, long long int *vet_info);
long long int *insercao(int *vet, int tam, long long int *vet_info);
long long int *mergeSort(int *vet, int inicio, int fim, long long int *vet_info);
void merge(int *vet, int inicio, int meio, int fim, long long int *vet_info);
long long int *quickSort(int *vet, int inicio, int fim, long long int *vet_info);
int particiona(int *vet, int inicio, int fim, long long int *vet_info);


//FUNÇÕES DO BLOCKSORT:
void trocar(int* a, int* b, long long int *vet_info);
void insertionSort(int vet[], int inicio, int fim, long long int *vet_info);
void mergeComBuffer(int vet[], int inicio, int meio, int fim, int *buffer, int tamanhoBuffer, long long int *vet_info);
long long int *blockSort(int *vet, int inicio, int fim, long long int *vet_info);

// UTILITÁRIAS
void imprimeVet(int *vet, int tam);
void reseta_vet_info(long long int *vet_info);
int *copiaVet(int *vetor, int tam_vetor);

// FUNÇÕES DE TEMPO
void mede_tempo_execucao_quadratico(long long int *(*algoritmo)(int*, int, long long int*), int *vetor, int tam, long long int *vet_info);
void mede_tempo_execucao_recursivo(long long int *(*algoritmo)(int*, int, int, long long int*), int *vetor, int inicio, int fim, long long int *vet_info);

// SALVAR RESULTADOS
void salvar_resultado(const char *algoritmo_nome, long long int *vet_info, int tam_vetor);

#endif // PROJETO_H
