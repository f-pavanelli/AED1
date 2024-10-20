#include "ListaSequencial.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int qtd;
    Aluno dados[MAX];
} Lista;

Lista* criaLista() {
    Lista* li = malloc(sizeof(Lista));
    if (li != NULL) {
        li->qtd = 0;
    }
    return li;
}

int tamanhoLista(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    return li->qtd;
}

int listaCheia(Lista* li) {
    if (li == NULL) return -1;
    return (li->qtd == MAX);
}

int listaVazia(Lista* li) {
    if (li == NULL) return -1;
    return (li->qtd == 0);
}

int inserirFinal(Lista* li, Aluno aluno) {
    if (li == NULL) return 0;
    if (listaCheia(li)) return 0;

    li->dados[li->qtd] = aluno;
    li->qtd++;

    return 1;
}

int inserirInicio(Lista* li, Aluno aluno) {
    if (li == NULL) return 0;
    if (listaCheia(li)) return 0;

    for (int i = li->qtd - 1; i >= 0; i--) {
        li->dados[i + 1] = li->dados[i];
    }

    li->dados[0] = aluno;
    li->qtd++;

    return 1;
}

int inserirDadoOrdenado(Lista* li, Aluno aluno) {
    if (li == NULL) return 0;
    if (listaCheia(li)) return 0;

    int i = 0;
    while (i < li->qtd && li->dados[i].matricula < aluno.matricula) {
        i++;
    }

    for (int k = (li->qtd - 1); k >= i; k--) {
        li->dados[k + 1] = li->dados[k];
    }

    li->dados[i] = aluno;
    li->qtd++;

    return 1;
}

int removerFinal(Lista* li) {
    if (li == NULL) return 0;
    if (listaVazia(li)) return 0;
    li->qtd--;

    return 1;
}

int removerInicio(Lista* li) {
    if (listaVazia(li)) return 0;

    for (int i = 0; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }

    li->qtd--;

    return 1;
}

int removerMatricula(Lista* li, int matricula) {
    if (listaVazia(li)) return 0;
    int i = 0;
    while (i < li->qtd && li->dados[i].matricula != matricula) {
        i++;
    }
    if (i == li->qtd) {
        printf("Valor não encontrado na lista");
        return 0;
    }
    for (int k = i; k < li->qtd - 1; k++) {
        li->dados[k] = li->dados[k + 1];
    }
    li->qtd--;
    return 1;
}

void exibirLista(Lista* li) {
    if (li == NULL) {
        printf("Lista não existe!\n");
        return;
    }

    for (int i = 0; i < li->qtd; i++) {
        printf("Matricula: %d, Nome: %s, Notas: %.2f, %.2f, %.2f\n",
               li->dados[i].matricula,
               li->dados[i].nome,
               li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
    }
}

int retornaAlunoPorPosicao(Lista* li, int posicao, Aluno* aluno) {
    if (listaVazia(li) || posicao > li->qtd || posicao <= 0) return 0;
    *aluno = li->dados[posicao - 1];
    return 1;
}

int retornaAlunoPorMatricula(Lista* li, int matricula, Aluno* aluno) {
    if (listaVazia(li)) return 0;
    int i = 0;
    while (i < li->qtd && li->dados[i].matricula != matricula) {
        i++;
    }
    if (i == li->qtd) return 0;
    *aluno = li->dados[i];
    return 1;
}

void liberaLista(Lista* li) {
    free(li);
}