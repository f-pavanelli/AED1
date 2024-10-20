#include "listaCircular.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    Aluno dados;
    struct elemento* prox
} Elemento;

Lista* criarLista() {
    Lista* li = malloc(sizeof(Lista));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

void liberaLista(Lista* li) {
    if (li != NULL && *li != NULL) {
        Elemento *aux, *no = *li;
        while (*li != no->prox) {
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanhoLista(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    int cont = 0;
    Elemento* no = *li;
    do {
        cont++;
        no = no->prox;
    } while (no != *li);
    return cont;
}

int inserirInicio(Lista* li, Aluno aluno) {
    if (li == NULL) return 0;

    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = aluno;
    if (*li == NULL) {
        *li = no;
        no->prox = no;
        return 1;
    }

    Elemento* aux = *li;
    while (aux->prox != *li) {
        aux = aux->prox;
    }
    aux->prox = no;
    no->prox = *li;
    *li = no;

    return 1;
}

int inserirFinal(Lista* li, Aluno aluno) {
    if (li == NULL) return 0;

    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = aluno;
    if (*li == NULL) {
        *li = no;
        no->prox = no;
        return 1;
    }

    Elemento* aux = *li;
    while (aux->prox != *li) {
        aux = aux->prox;
    }
    aux->prox = no;
    no->prox = *li;
    return 1;
}

int inserirOrdenado(Lista* li, Aluno aluno) {
    if (li == NULL) return 0;

    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = aluno;
    if (*li == NULL) {
        *li = no;
        no->prox = no;
        return 1;
    }
    if ((*li)->dados.matricula > aluno.matricula) {  // insere no inicio
        Elemento* atual = *li;
        while (atual->prox != *li) {
            atual = atual->prox;
            no->prox = *li;
            atual->prox = no;
            *li = no;
        }
        return 1;
    }
    Elemento *ant = *li, *atual = (*li)->prox;
    while (atual != *li && atual->dados.matricula < aluno.matricula) {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = no;
    no->prox = atual;
    return 1;
}

int removerInicio(Lista* li) {
    if (li == NULL) return 0;
    if (*li == NULL) return 0;
    if (*li == (*li)->prox) {  // lista com elemento unico
        free(*li);
        *li = NULL;
        return 1;
    }
    Elemento* atual = *li;
    while (atual->prox != *li) {
        atual = atual->prox;
    }
    Elemento* no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
}

int removerFinal(Lista* li) {
    if (li == NULL) return 0;
    if (*li == NULL) return 0;

    if (*li == (*li)->prox) {  // lista com elemento unico
        free(*li);
        *li = NULL;
        return 1;
    }

    Elemento *ant, *no = *li;
    while (no->prox != *li) {
        ant = no;
        no = no->prox;
    }

    ant->prox = no->prox;
    free(no);
    return 1;
}

int removerElemento(Lista* li, int matricula) {
    if (li == NULL) return 0;
    if (*li == NULL) return 0;
    Elemento* no = *li;
    if (no->dados.matricula == matricula) {  // remover do inicio
        if (no == no->prox) {                // lista ficara vazia
            free(no);
            *li == NULL;
            return 1;
        }

        Elemento* ult = *li;
        while (ult->prox != *li) {
            ult = ult->prox;
        }

        ult->prox = (*li)->prox;
        *li = (*li)->prox;
        free(no);
        return 1;
    }

    Elemento* ant = no;
    no = no->prox;
    while (no != *li && no->dados.matricula != matricula) {
        ant = no;
        no = no->prox;
    }

    if (no == *li) return 0;  // valor nao encontrado
    ant->prox = no->prox;
    free(no);
    return 1;
}

int consultarPosicao(Lista* li, int posicao, Aluno* aluno) {
    if (li == NULL || *li == NULL || posicao <= 0) return 0;
    Elemento* no = *li;
    int i = 1;
    while (no->prox != *li && posicao < i) {
        no = no->prox;
        i++;
    }
    if (i != posicao) return 0;
    *aluno = no->dados;
    return 1;
}

int consultarValor(Lista* li, int matricula, Aluno* aluno) {
    if (li == NULL || *li == NULL) return 0;
    Elemento* no = *li;
    while (no->prox != *li && no->dados.matricula != matricula) {
        no = no->prox;
    }
    if (no->dados.matricula != matricula) return 0;  // valor nao encontrado
    *aluno = no->dados;
    return 1;
}