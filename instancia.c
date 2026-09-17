#include <stdio.h>
#include <stdlib.h>
#include "instancia.h"

Instancia *lerInstancia() {
    int i;

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

    // Imprimindo pra testar
    printf("Instância lida:\n");
    printf("h: %d, l: %d, R: %d\n", inst->h, inst->l, inst->R);
    for (i = 0; i < inst->h; i++)
        printf("Hidrelétrica %d: M=%d, F=%d, C=%d\n", i, inst->M[i], inst->F[i], inst->C[i]);
    for (i = 0; i < inst->l; i++)
        printf("Central %d: D=%d\n", i, inst->D[i]);

    return inst;
}

void liberaInstancia(Instancia *inst) {
    free(inst->M);
    free(inst->F);
    free(inst->C);
    free(inst->D);
    free(inst);
}
