#include <stdio.h>
#include "instancia.h"

int main()
{
    Instancia *inst;

    inst = lerInstancia();

    liberaInstancia(inst);

    return 0;
}
