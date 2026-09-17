#include <stdio.h>
#include <stdlib.h>
int main(){

    // h: número de Hidrelétricas
    // l: número de Centrais Elétricas
    // R: Vazão do rio
    int h, l, R;

    //Mi: Capacidade de Produção de cada hidrelétrica
    //Fi: Eficiência energética de cada hidrelétrica
    //Ci: Custo operacional de cada hidrelétrica
    int *Mi, *Fi, *Ci;

    // Di: Demanda da central elétrica
    int *Di;

    // ni: número de vizinhos
    int *ni;



    // tij: iezimo vizinho
    // wij: capacidade do iezimo vizinho
    // cij: custo do iezimo vizinho
    int **tij, **wij, **cij;
    
    scanf("%d %d %d", &h, &l, &R);
    // printf("%d %d %d\n", h, l, R);
    // int *aux1 = Mi;
    // int *aux2 = Fi;
    // int *aux3 = Ci;
    // for(int i = 0; i<h; i++){
    //     scanf("%d %d %d", Mi, Fi, Ci);
    //     Mi++;
    //     Fi++;
    //     Ci++;
    // }
    // Mi = aux1;
    // Fi = aux2;
    // Ci = aux3;
    Mi = (int *) malloc(sizeof(int)*h);
    Fi = (int *) malloc(sizeof(int)*h);
    Ci = (int *) malloc(sizeof(int)*h);
    Di = (int *) malloc(sizeof(int)*l);
    ni = (int *) malloc(sizeof(int)*(h+l));
    tij = (int **) malloc(sizeof(int*)*(h+l));
    wij = (int **) malloc(sizeof(int*)*(h+l));
    cij = (int **) malloc(sizeof(int*)*(h+l));

    for(int i = 0; i<h; i++){
        scanf("%d %d %d", &Mi[i], &Fi[i], &Ci[i]);
    }

    // for(int i = 0; i<h; i++){
    //     printf("%d %d %d\n", Mi[i], Fi[i], Ci[i]);
    // }

    for(int i = 0; i<l; i++){
        scanf("%d", &Di[i]);
    }

    // for(int i = 0; i<l; i++){
    //     printf("%d\n", Di[i]);
    // }
    for(int i = 0; i < h+l; i++){
        scanf("%d", &ni[i]);
        
        tij[i] = (int *) malloc(sizeof(int)*ni[i]);
        wij[i] = (int *) malloc(sizeof(int)*ni[i]);
        cij[i] = (int *) malloc(sizeof(int)*ni[i]);

        for(int j = 0; j<ni[i]; j++){
            scanf("%d %d %d", &tij[i][j], &wij[i][j], &cij[i][j]);
        }
    }
    // for(int i = 0; i<h+l; i++){
    //     printf("%d\n", ni[i]);
    //     for(int j = 0; j<ni[i]; j++){
    //         printf("%d %d %d\n", tij[i][j], wij[i][j], cij[i][j]);
    //     }
    // }

    for(int i=0; i<ni[i];i++){
        free(tij[i]);
        free(wij[i]);
        free(cij[i]);
    }
    free(tij);
    free(Mi);
    free(Fi);
    free(Ci);
    free(Di);
    free(ni);

    // printf("Chegou até aqui\n");
    return 0;
}
