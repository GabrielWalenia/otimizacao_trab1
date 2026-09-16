#include <stdio.h>

int main(){
    // h: número de Hidrelétricas
    // l: número de centrais de energia
    // R: Valzão do rio
    int h, l, R;
    
    // Mi: Capacidades de produção
    // Fi: Eficiências energeticas
    // Ci: Custos de produção
    int *Mi, *Fi, *Ci;

    // Di: Demandas energeticas
    int *Di;
    // ni: Números de vizinhos de saída
    int *ni;

    // tij: indice da central que vai a conexao
    // wij: capacidade de conexao
    // cij: custo
    int **tij, **wij, **cij; 
    scanf("%d %d %d", &h, &l, &R);


    printf("%d %d %d\n", h, l, R);
    return 0;
}
