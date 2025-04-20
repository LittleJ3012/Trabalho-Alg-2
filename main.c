#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"

int main(void) {
    int *vetor;
    int *vetorCopia;
    int tam_vetor;
    int opcao;
    int ordem;
    int semente;
    int porcentagem;
    
    //Esse vetor vai armazenar para cada Algoritmo de Ordenação:
    //0 = quantidade de trocas realizadas,
    //1 = quantidade de comparacoes realizadas,
    //2 = quantidade de chamadas de função
    //3 = tempo de execução
    long long int vet_info[4] = {0, 0, 0, 0};

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam_vetor);

    printf("MENU PARA CRIAR O VETOR DE TESTES\n");
    printf("1 - Aleatorio\n");
    printf("2 - Quase Ordenado\n");
    printf("3 - Ordenado\n");

    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    if(opcao == 1) {
        printf("Digite a semente: ");
        scanf("%d", &semente);
        vetor = geraAleatorios(tam_vetor, semente);
    } else if(opcao == 2) {
        printf("Digite a porcentagem de elementos quase ordenados: ");
        scanf("%d", &porcentagem);
        vetor = geraQuaseOrdenados(tam_vetor, porcentagem);
    } else if(opcao == 3) {
        printf("Digite a ordem de ordenação (0 - crescente, 1 - decrescente): ");
        scanf("%d", &ordem);
        vetor = geraOrdenados(tam_vetor, ordem);
    }

    //printf("\nVetor criado: \n");
    //imprimeVet(vetor, tam_vetor);
    
    if(tam_vetor < 500000){
        vetorCopia = copiaVet(vetor, tam_vetor);
        printf("ORDENACAO POR BOLHA:\n");
        mede_tempo_execucao_quadratico(bolha, vetorCopia, tam_vetor, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("BOLHA realizou %lld trocas.\n", vet_info[0]);
        printf("BOLHA realizou %lld comparacoes.\n", vet_info[1]);
        printf("BOLHA realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do BOLHA: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Bolha", vet_info, tam_vetor);

        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR BOLHA INTELIGENTE:\n");
        mede_tempo_execucao_quadratico(bolhaInteligente, vetorCopia, tam_vetor, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("BOLHA INTELIGENTE realizou %lld trocas.\n", vet_info[0]);
        printf("BOLHA INTELIGENTE realizou %lld comparacoes.\n", vet_info[1]);
        printf("BOLHA INTELIGENTE realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do BOLHA INTELIGENTE: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Bolha Inteligente", vet_info, tam_vetor);

        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR SELECAO:\n");
        mede_tempo_execucao_quadratico(selecao, vetorCopia, tam_vetor, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("SELECAO realizou %lld trocas.\n", vet_info[0]);
        printf("SELECAO realizou %lld comparacoes.\n", vet_info[1]);
        printf("SELECAO realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do SELEÇÃO: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Selecao", vet_info, tam_vetor);

        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR INSERCAO:\n");
        mede_tempo_execucao_quadratico(insercao, vetorCopia, tam_vetor, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("INSERCAO realizou %lld movimentacoes.\n", vet_info[0]);
        printf("INSERCAO realizou %lld comparacoes.\n", vet_info[1]);
        printf("INSERCAO realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do INSERCAO: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Insercao", vet_info, tam_vetor);

        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR MERGE SORT:\n");
        mede_tempo_execucao_recursivo(mergeSort, vetorCopia, 0, tam_vetor - 1, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("MERGE SORT realizou %lld trocas.\n", vet_info[0]);
        printf("MERGE SORT realizou %lld comparacoes.\n", vet_info[1]);
        printf("MERGE SORT realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do MERGE SORT: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Merge Sort", vet_info, tam_vetor);

        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR QUICK SORT:\n");
        mede_tempo_execucao_recursivo(quickSort, vetorCopia, 0, tam_vetor - 1, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("QUICK SORT realizou %lld trocas.\n", vet_info[0]);
        printf("QUICK SORT realizou %lld comparacoes.\n", vet_info[1]);
        printf("QUICK SORT realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do QUICK SORT: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Quick Sort", vet_info, tam_vetor);
    
        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR BLOCK SORT:\n");
        mede_tempo_execucao_recursivo(blockSort, vetorCopia, 0, tam_vetor - 1, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("BLOCK SORT realizou %lld trocas.\n", vet_info[0]);
        printf("BLOCK SORT realizou %lld comparacoes.\n", vet_info[1]);
        printf("BLOCK SORT realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do BLOCK SORT: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Block Sort", vet_info, tam_vetor);
        
    }else{
        vetorCopia = copiaVet(vetor, tam_vetor);
        printf("ORDENACAO POR MERGE SORT:\n");
        mede_tempo_execucao_recursivo(mergeSort, vetorCopia, 0, tam_vetor - 1, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("MERGE SORT realizou %lld trocas.\n", vet_info[0]);
        printf("MERGE SORT realizou %lld comparacoes.\n", vet_info[1]);
        printf("MERGE SORT realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do MERGE SORT: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Merge Sort", vet_info, tam_vetor);

        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR QUICK SORT:\n");
        mede_tempo_execucao_recursivo(quickSort, vetorCopia, 0, tam_vetor - 1, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("QUICK SORT realizou %lld trocas.\n", vet_info[0]);
        printf("QUICK SORT realizou %lld comparacoes.\n", vet_info[1]);
        printf("QUICK SORT realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do QUICK SORT: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Quick Sort", vet_info, tam_vetor);
    
        vetorCopia = copiaVet(vetor, tam_vetor);
        reseta_vet_info(vet_info);
        printf("ORDENACAO POR BLOCK SORT:\n");
        mede_tempo_execucao_recursivo(blockSort, vetorCopia, 0, tam_vetor - 1, vet_info);
        //imprimeVet(vetorCopia, tam_vetor);
        printf("BLOCK SORT realizou %lld trocas.\n", vet_info[0]);
        printf("BLOCK SORT realizou %lld comparacoes.\n", vet_info[1]);
        printf("BLOCK SORT realizou %lld chamadas de funcao.\n", vet_info[2]);
        printf("Tempo de execucao do BLOCK SORT: %lld microssegundos\n\n", vet_info[3]);
        salvar_resultado("Block Sort", vet_info, tam_vetor);
    }

    return 0;
}
