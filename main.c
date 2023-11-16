#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char nome[81];
    int idade;
};
typedef struct Pessoa pessoa;

static int compInt(int num1, int num2)
{
    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    return 0;
}

int buscaPessoa(int n, pessoa* Clientes, char* nome, int idade)
{
    int ini = 0;
    int fim = n-1;
    int meio, comp;

    while (ini <= fim)
    {
        meio = (ini + fim)/2;
        if (strcmp(nome, Clientes->nome) < 0)
            fim = meio - 1;
        else if (strcmp(nome, Clientes->nome) > 0)
            ini = meio + 1;
        else
            return meio;
    }
    return -1;
}

int main(void)
{
    pessoa Clientes[] = {{"ada", 20}, {"ana", 19}};

    printf("%d\n", buscaPessoa(2, Clientes, "ana", 19));

    return 0;
}