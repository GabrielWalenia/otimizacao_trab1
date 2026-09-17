#ifndef INSTANCIA_H
#define INSTANCIA_H

typedef struct {
    int h; // número de hidrelétricas
    int l; // número de centrais elétricas
    int R; // vazão do rio

    int *M; // M[i]: capacidade de produção da hidrelétrica i
    int *F; // F[i]: eficiência energética da hidrelétrica i
    int *C; // C[i]: custo de produção por unidade de vazão

    int *D; // D[i]: demanda da central elétrica i
} Instancia;

Instancia *lerInstancia();
void liberaInstancia(Instancia *inst);

#endif
