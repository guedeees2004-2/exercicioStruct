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

int buscaPessoaMaisJovem(int n, pessoa* Clientes, char*nome)
{
    int ini = 0;
    int fim = n - 1;
    int meio, comp;
    
    while (ini <= fim)
    {
        meio = (ini + fim)/2;
        if (strcmp(nome, Clientes[meio].nome) < 0)
            fim = meio - 1;
        else if (strcmp(nome, Clientes[meio].nome) > 0)
            ini = meio + 1;
        else
        {
            while (meio > 0 && strcmp(nome, Clientes[meio - 1].nome) == 0)
                meio--;
            return meio;
        }
    }
    return -1;
}

int buscaPessoa(int n, pessoa* Clientes, char* nome, int idade)
{
    int ini = 0;
    int fim = n - 1;
    int meio, comp;

    while (ini <= fim)
    {
        meio = (ini + fim)/2;
        if (strcmp(nome, Clientes[meio].nome) < 0)
            fim = meio - 1;
        else if (strcmp(nome, Clientes[meio].nome) > 0)
            ini = meio + 1;
        else
        {
            if((comp = compInt(idade, Clientes[meio].idade)) < 0)
                fim = meio - 1;
            else if (comp > 0)
                ini = meio + 1;
            else
                return meio;
        }
    }
    return -1;
}

int main(void)
{
    pessoa Clientes[] = {{"ada", 20}, {"ana", 19}, {"ana", 23}, {"ana", 27}, {"ana", 31}, {"bia", 18}, {"eva", 21}, {"lia", 17}, {"rai", 30}, {"zac", 23}, {"zac", 18}};

    printf("Ana de 31 anos esta na posicao: %d\n", buscaPessoa(9, Clientes, "ana", 31));
    printf("A ana mais jovem esta na posicao: %d\n", buscaPessoaMaisJovem(9, Clientes, "ana"));

    return 0;
}