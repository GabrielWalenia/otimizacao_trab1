#include <stdio.h>
#include "instancia.h"

int main()
{
    Instancia *inst;

    inst = lerInstancia();

    // Não pode ser um FILE, tem que ser STDOUT/STDIN
    FILE *arq = gera_entrada(inst);
    liberaInstancia(inst);

    return 0;
}
