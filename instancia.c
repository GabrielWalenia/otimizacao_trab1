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
    inst->ni = (int *) malloc(sizeof(int)*(inst->h+inst->l));
    inst->tij = (int **) malloc(sizeof(int*)*(inst->h+inst->l));
    inst->wij = (int **) malloc(sizeof(int*)*(inst->h+inst->l));
    inst->cij = (int **) malloc(sizeof(int*)*(inst->h+inst->l));
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

    for(int i = 0; i < inst->h+inst->l; i++){
        scanf("%d", &inst->ni[i]);
        
        inst->tij[i] = (int *) malloc(sizeof(int)*inst->ni[i]);
        inst->wij[i] = (int *) malloc(sizeof(int)*inst->ni[i]);
        inst->cij[i] = (int *) malloc(sizeof(int)*inst->ni[i]);

        for(int j = 0; j<inst->ni[i]; j++){
            scanf("%d %d %d", &inst->tij[i][j], &inst->wij[i][j], &inst->cij[i][j]);
        }
    }
    for(int i = 0; i<inst->h+inst->l; i++){
        printf("%d\n", inst->ni[i]);
        for(int j = 0; j<inst->ni[i]; j++){
            printf("%d %d %d\n", inst->tij[i][j], inst->wij[i][j], inst->cij[i][j]);
        }
    }

    
    return inst;
}

void liberaInstancia(Instancia *inst) {
    for(int i=0; i<inst->ni[i];i++){
        free(inst->tij[i]);
        free(inst->wij[i]);
        free(inst->cij[i]);
    }
    free(inst->M);
    free(inst->F);
    free(inst->C);
    free(inst->D);
    free(inst);
}
