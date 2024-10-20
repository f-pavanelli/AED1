#include "listaDuplamenteLigada.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    Aluno dados;
    struct elemento* prox;
    struct elemento* ant;
} Elemento;

Lista* criarLista() {
    Lista* li = malloc(sizeof(Lista));
    if (li != NULL) *li = NULL;
    return li;
}

void liberarLista(Lista* li) {
    if (li != NULL) {
        Elemento* no;
        while (*li != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanhoLista(Lista* li) {
    if (li == NULL) return 0;
    int cont = 0;
    Elemento* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int inserirInicio(Lista* li, Aluno aluno) {
    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL || li == NULL) return 0;
    no->dados = aluno;
    no->prox = *li;
    no->ant = NULL;
    if (*li != NULL) {
        (*li)->ant = no;
    }
    *li = no;
    return 1;
}

int inserirFinal(Lista* li, Aluno aluno) {
    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL || li == NULL) return 0;
    no->dados = aluno;
    no->prox = NULL;

    if (*li == NULL) {  // se lista vazia
        no->ant == NULL;
        *li = no;  // inserido no inicio
    } else {
        Elemento* aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        no->ant = aux;
        aux->prox = no;
    }
    return 1;
}

int inserirOrdenado(Lista* li, Aluno aluno) {
    if (li == NULL) return 0;

    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = aluno;
    no->prox = NULL;
    no->ant = NULL;

    if (*li == NULL) {  // inserção na lista vazia
        *li = no;
        return 1;
    }

    Elemento *auxAnte, *atual = *li;
    while (atual != NULL && atual->dados.matricula < aluno.matricula) {
        auxAnte = atual;
        atual = atual->prox;
    }
    // inserção no inicio
    if (atual == *li) {
        no->prox = *li;
        (*li)->ant = no;
        *li = no;
    } else {
        no->prox = auxAnte->prox;  // no->prox = atual;
        no->ant = auxAnte;
        auxAnte->prox = no;
        if (atual != NULL) {
            atual->ant = no;
        }
    }

    return 1;
}

int removerInicio(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    Elemento* no = *li;  // no sera excluido

    *li = no->prox;
    if (no->prox != NULL) {
        no->prox->ant = NULL;  // como o primeiro elemento "no" sera excluido, eliminamos sua ligacao como elemento anterior de outro
    }
    free(no);
    return 1;
}

int removerFinal(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    Elemento* no = *li;

    while (no->prox != NULL) {
        no = no->prox;
    }

    if (no->ant == NULL) {  // remover o unico elemento da lista
        *li = no->prox;     // mesma coisa que *li = NULL
    } else {
        no->ant->prox = NULL;  // não tem ninguem depois do novo ultimo no
    }
    free(no);
    return 1;
}

int removeValor(Lista* li, int matricula) {
    if (li == NULL) return 0;
    Elemento* no = *li;

    while (no != NULL && no->dados.matricula != matricula) {
        no = no->prox;
    }
    if (no == NULL) return 0;  // não encontrou
    if (no == *li) {           // remover primeiro elemento
        *li = no->prox;
    } else {
        no->ant->prox = no->prox;
    }

    if (no->prox != NULL) {  // para quando retiramos um elemento que nao e o ultimo ou primeiro
        no->prox->ant = no->ant;
    }

    free(no);
    return 1;
}

int consultarPosicao(Lista* li, int posicao, Aluno* aluno) {
    if (li == NULL || posicao <= 0) return 0;
    Elemento* no = *li;

    int i = 1;
    while (no != NULL && i < posicao) {
        no = no->prox;
        i++;
    }
    if (no == NULL) {
        return 0;
    }

    *aluno = no->dados;
    return 1;
}

int consultarMatricula(Lista* li, int matricula, Aluno* aluno) {
    if (li == NULL) return 0;
    Elemento* no = *li;

    while (no != NULL && no->dados.matricula != matricula) {
        no = no->prox;
    }

    if (no == NULL) return 0;  // não achei;
    *aluno = no->dados;
    return 1;
}