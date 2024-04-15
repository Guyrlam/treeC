#include <stdio.h>
#include "arvore.h"

int main(){
    Arvore* arvore = arvore_cria();
    arvore_inserir(arvore, 10);
    arvore_inserir(arvore, 0);
    arvore_inserir(arvore, 20);
    arvore_inserir(arvore, 5);
    arvore_inserir(arvore, 25);
    arvore_inserir(arvore, 15);
    arvore_inserir(arvore, 7);
    arvore_inserir(arvore, 23);
    arvore_inserir(arvore, 6);
    arvore_inserir(arvore, 16);
    printf("%d\n", arvore_busca(arvore, 0));
    printf("%d\n", arvore_busca(arvore, 10));
    printf("%d\n", arvore_busca(arvore, 77));
    printf("%d\n", arvore_busca(arvore, 25));
    arvore_imprimir(arvore);
    arvore_apagar(arvore, 10);
    arvore_imprimir(arvore);

    return 1;
}