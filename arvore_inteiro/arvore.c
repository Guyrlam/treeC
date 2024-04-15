#include <stdlib.h>
#include <stdio.h>

// Referencias
// https://stackoverflow.com/questions/62232295/print-simple-binary-search-tree-in-c
// https://www.geeksforgeeks.org/deletion-in-binary-search-tree/

// Tipos

typedef struct No
{
    struct No *direita;
    struct No *esquerda;
    int valor;
} No;

typedef struct
{
    No *raiz;
} Arvore;

// Auxiliares

No *criar_no(int x)
{
    No *no = malloc(sizeof(No));
    no->direita = NULL;
    no->esquerda = NULL;
    no->valor = x;
    return no;
}

void inserir(No *no, int x)
{
    if (no->valor < x)
    {
        if (no->direita == NULL)
        {
            no->direita = criar_no(x);
        }
        else
        {
            inserir(no->direita, x);
        }
    }
    else if (no->valor > x)
    {
        if (no->esquerda == NULL)
        {
            no->esquerda = criar_no(x);
        }
        else
        {
            inserir(no->esquerda, x);
        }
    }
}

int buscar_no(No *no, int x)
{
    if (no->valor == x)
    {
        return 1;
    }
    else if (no->valor < x)
    {
        if (no->direita == NULL)
            return 0;
        else
            return buscar_no(no->direita, x);
    }
    else
    {
        if (no->esquerda == NULL)
            return 0;
        else
            return buscar_no(no->esquerda, x);
    }
}

No *remover_no(No *no, int x)
{
    if (no == NULL)
        return no;
    if (no->valor > x)
    {
        no->esquerda = remover_no(no->esquerda, x);
        return no;
    }
    else if (no->valor < x)
    {
        no->direita = remover_no(no->direita, x);
        return no;
    }
    if (no->esquerda == NULL)
    {
        No *temp = no->direita;
        free(no);
        return temp;
    }
    else if (no->direita == NULL)
    {
        No *temp = no->esquerda;
        free(no);
        return temp;
    }
    else
    {

        No *succParent = no;

        No *succ = no->direita;
        while (succ->esquerda != NULL)
        {
            succParent = succ;
            succ = succ->esquerda;
        }

        if (succParent != no)
            succParent->esquerda = succ->direita;
        else
            succParent->direita = succ->direita;

        no->valor = succ->valor;

        free(succ);
        return no;
    }
}

void imprimir_hierarquia(No *no, int nivel)
{
    if (no != NULL)
    {
        for (int i = 0; i <= nivel; i++)
        {
            printf(i == nivel ? "-> " : "       ");
        }
        printf(nivel == 0 ? "nivel: raiz" : "nivel: %d", nivel);
        printf(" valor: %d\n", no->valor);
        imprimir_hierarquia(no->esquerda, nivel + 1);
        imprimir_hierarquia(no->direita, nivel + 1);
    }
}

// Métodos

Arvore *arvore_cria()
{
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

void arvore_inserir(Arvore *arvore, int x)
{
    if (arvore == NULL)
        return;

    No *no = arvore->raiz;
    if (no == NULL)
    {
        arvore->raiz = criar_no(x);
    }
    else
    {
        inserir(no, x);
    }
}

int arvore_busca(Arvore *arvore, int x)
{
    if (arvore == NULL)
        return 0;
    if (arvore->raiz == NULL)
        return 0;
    return buscar_no(arvore->raiz, x);
}

void arvore_apagar(Arvore *arvore, int x)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        return;
    }

    remover_no(arvore->raiz, x);
};

void arvore_imprimir(Arvore *arvore)
{
    if (arvore == NULL)
    {
        printf("Arvore inesistente.\n");
    }
    else if (arvore->raiz == NULL)
    {
        printf("Arvore vazia.\n");
    }
    else
    {
        printf("inicio:\n");
        imprimir_hierarquia(arvore->raiz, 0);
        printf("fim \n");
    }
}