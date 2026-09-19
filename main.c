#include <stdio.h>
#include "instancia.h"

int main()
{
    Instancia *inst;

    inst = lerInstancia();
    FILE *arq = gera_entrada(inst);
    liberaInstancia(inst);

    return 0;
}
