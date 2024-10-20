#include <stdio.h>
#include <stdlib.h>

#include "ListaSequencial.h"

int main() {
    Lista* li = criaLista();

    Aluno aluno1 = {1001, "Alice", 8.0, 9.0, 7.5};
    Aluno aluno2 = {1002, "Bob", 7.0, 8.5, 9.0};
    Aluno aluno3 = {1000, "Carlos", 9.0, 9.5, 10.0};

    inserirDadoOrdenado(li, aluno1);
    inserirDadoOrdenado(li, aluno2);
    inserirDadoOrdenado(li, aluno3);
    printf("Exibicao completa ____________\n");
    exibirLista(li);

    Aluno manipularAluno;
    printf("Busca por posicao ____________\n");
    retornaAlunoPorPosicao(li, 3, &manipularAluno);
    printf("Matricula: %d, Nome: %s, Notas: %.2f, %.2f, %.2f\n",
           manipularAluno.matricula,
           manipularAluno.nome,
           manipularAluno.n1, manipularAluno.n2, manipularAluno.n3);

    printf("Busca por matricula ____________\n");
    retornaAlunoPorMatricula(li, 1001, &manipularAluno);
    printf("Matricula: %d, Nome: %s, Notas: %.2f, %.2f, %.2f\n",
           manipularAluno.matricula,
           manipularAluno.nome,
           manipularAluno.n1, manipularAluno.n2, manipularAluno.n3);
    liberaLista(li);
    return 0;
}
