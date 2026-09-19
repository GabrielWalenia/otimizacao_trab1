#include <stdio.h>
#include <stdlib.h>
#include "instancia.h"

Instancia *lerInstancia()
{
    int i, j;

    // número de vizinhos de saída
    int n;

    // t: índice da central para onde vai a conexão
    // w: capacidade da conexão
    // c: custo da conexão
    int t, w, c;

    Instancia *inst;
    inst = malloc(sizeof(Instancia));

    scanf("%d %d %d", &inst->h, &inst->l, &inst->R);

    // Para cada hidrelétrica, ler capacidade, eficiência e custo de produção
    inst->M = malloc(inst->h * sizeof(int));
    inst->F = malloc(inst->h * sizeof(int));
    inst->C = malloc(inst->h * sizeof(int));
    for (i = 0; i < inst->h; i++)
        scanf("%d %d %d", &inst->M[i], &inst->F[i], &inst->C[i]);

    // Para cada central elétrica, ler demanda
    inst->D = malloc(inst->l * sizeof(int));
    for (i = 0; i < inst->l; i++)
        scanf("%d", &inst->D[i]);

    // Descrição da rede seguindo esse trecho do pdf do enunciado do trabalho:
    /*
    Temos h + l blocos um para cada vértice da rede (h hidroelétricas e l centrais).
    Cada bloco começa com um número de vizinhos de saída (n_i) seguido de n_i triplas
    representando o índice da central para onde vai a conexão (t_ij), a capacidade
    da conexão (w_ij) e o custo (c_ij)
    */
    inst->nArcos = 0;
    inst->arcos = NULL;
    for (i = 0; i < inst->h + inst->l; i++)
    {
        scanf("%d", &n);
        inst->arcos = realloc(inst->arcos, (inst->nArcos + n) * sizeof(Arco));

        for (j = 0; j < n; j++)
        {
            scanf("%d %d %d", &t, &w, &c);

            inst->arcos[inst->nArcos].origem = i;

            // Centrais vão de "h" a "h + l - 1"
            inst->arcos[inst->nArcos].destino = inst->h + t - 1;

            inst->arcos[inst->nArcos].capacidade = w;
            inst->arcos[inst->nArcos].custo = c;
            inst->nArcos++;
        }
    }

    // Imprimindo pra testar
    printf("Instância lida:\n");
    printf("h: %d, l: %d, R: %d\n", inst->h, inst->l, inst->R);
    for (i = 0; i < inst->h; i++)
        printf("Hidrelétrica %d: M=%d, F=%d, C=%d\n", i, inst->M[i], inst->F[i], inst->C[i]);
    for (i = 0; i < inst->l; i++)
        printf("Central %d: D=%d\n", i, inst->D[i]);
    printf("Arcos:\n");
    for (i = 0; i < inst->nArcos; i++)
        printf("Arco %d: origem=%d, destino=%d, capacidade=%d, custo=%d\n",
               i, inst->arcos[i].origem,

               // Centrais vão de "h" a "h + l - 1"
               inst->arcos[i].destino - inst->h + 1,

               inst->arcos[i].capacidade, inst->arcos[i].custo);

    return inst;
}

FILE *gera_entrada(Instancia *inst)
{
    // Primeiro, calcular a demanda total da rede
    // Calcular a capacidade de produção da rede
    // Problema inviavel: Mais demanda do que é capaz de produzir
    // Modelar o problema matematico
    // Colocar em um arquivo de forma que ele seja a entrada de lp solve
    if (!inst)
        return NULL;

    return NULL;
}

void liberaInstancia(Instancia *inst)
{
    free(inst->M);
    free(inst->F);
    free(inst->C);
    free(inst->D);
    free(inst->arcos);
    free(inst);
}