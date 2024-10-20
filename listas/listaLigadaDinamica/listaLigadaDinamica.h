typedef struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;

typedef struct elemento* Lista;

Lista* criarLista();
void liberaLista(Lista* li);
int tamanhoLista(Lista* li);
int inserirInicio(Lista* li, Aluno aluno);
int inserirFinal(Lista* li, Aluno aluno);
int inserirOrdenado(Lista* li, Aluno aluno);
int removerInicio(Lista* li);
int removerFinal(Lista* li);
int removerValor(Lista* li, int matricula);
int consultarPosicao(Lista* li, int posicao, Aluno* aluno);
int consultarMatricula(Lista* li, int matricula, Aluno* aluno);
