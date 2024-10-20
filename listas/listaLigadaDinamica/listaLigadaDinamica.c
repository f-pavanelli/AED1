#include "listaLigadaDinamica.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    Aluno dados;
    struct elemento* prox;
} Elemento;

Lista* criarLista() {
    Lista* li = malloc(sizeof(Lista));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

void liberaLista(Lista* li) {
    if (li != NULL) {
        Elemento* no;
        while ((*li) != NULL) {
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
    if (no == NULL) return 0;
    no->dados = aluno;
    no->prox = (*li);  // resolve o caso de insercao em lista vazia
    *li = no;
    return 1;
}

int inserirFinal(Lista* li, Aluno aluno) {
    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL) return 0;
    no->dados = aluno;
    no->prox = NULL;
    if (*li == NULL) {  // caso a lista esteja vazia
        *li = no;
        return 1;
    }
    Elemento* aux = *li;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = no;
    return 1;
}

int inserirOrdenado(Lista* li, Aluno aluno) {
    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL) return 0;
    no->dados = aluno;

    if (*li == NULL) {  // inserção na lista vazia
        no->prox = *li;
        *li = no;
        return 1;
    }

    Elemento *anterior = NULL, *atual = *li;

    while (atual != NULL && atual->dados.matricula < aluno.matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    // inserção no início
    if (anterior == NULL) {
        no->prox = *li;
        *li = no;
    } else {
        no->prox = anterior->prox;
        anterior->prox = no;
    }
    return 1;
}

int removerInicio(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    Elemento* no = *li;

    *li = no->prox;
    free(no);

    return 1;
}

int removerFinal(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    Elemento *anterior = NULL, *no = *li;

    while (no->prox != NULL) {
        anterior = no;
        no = no->prox;
    }

    if (no == *li) {  // so um elemento na lista
        *li = NULL;
    } else {
        anterior->prox = NULL;
    }

    free(no);
    return 1;
}

int removerValor(Lista* li, int matricula) {
    if (li == NULL) return 0;

    Elemento *anterior = NULL, *no = *li;
    while (no != NULL && no->dados.matricula != matricula) {
        anterior = no;
        no = no->prox;
    }
    if (no == NULL) return 0;  // nao encontrou
    if (no == *li) {           // remover o primeiro
        *li = no->prox;
    } else {
        anterior->prox = no->prox;  // pegamos o proximo do no que queremos apagar e ligamos ao anterior
    }
    free(no);
    return 1;
}

int consultarPosicao(Lista* li, int posicao, Aluno* aluno) {
    if (li == NULL || posicao <= 0) return 0;
    Elemento* no = *li;

    int i = 0;
    while (no != NULL && i < posicao) {
        no = no->prox;
        i++;
    }
    if (no == NULL) {
        printf("Posicao nao encontrada\n");
        return 0;
    }

    *aluno = no->dados;
    return 1;
}

int consultarMatricula(Lista* li, int matricula, Aluno* aluno) {
    if (li == NULL) return 0;
    Elemento* no = *li;

    int i = 0;
    while (no != NULL && no->dados.matricula != matricula) {
        no = no->prox;
    }
    if (no == NULL) {
        printf("Matricula nao encontrada\n");
        return 0;
    }

    *aluno = no->dados;
    return 1;
}