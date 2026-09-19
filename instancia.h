#ifndef INSTANCIA_H
#define INSTANCIA_H

typedef struct
{
    int origem;
    int destino;
    int capacidade;
    int custo;
} Arco;

typedef struct
{
    int h; // número de hidrelétricas
    int l; // número de centrais elétricas
    int R; // vazão do rio

    int *M; // M[i]: capacidade de produção da hidrelétrica i
    int *F; // F[i]: eficiência energética da hidrelétrica i
    int *C; // C[i]: custo de produção por unidade de vazão

    int *D; // D[j]: demanda da central elétrica j

    int nArcos;

    // vetor com todos os arcos da rede com origem em cada vértice
    // vértices são tanto hidrelétricas quanto centrais
    // sendo que todas podem ser origens mas só centrais podem ser destinos
    // 0 .. h-1 hidrelétricas (hidrelétrica i fica no vértice i)
    // h .. h+l-1 centrais (central j fica no vértice h+j)
    Arco *arcos;
} Instancia;

Instancia *lerInstancia();
FILE *gera_entrada(Instancia *inst);
void liberaInstancia(Instancia *inst);

#endif