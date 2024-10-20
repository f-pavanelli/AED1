#define MAX 100

typedef struct aluno {
    int matricula;
    char nome[100];
    float n1, n2, n3;
} Aluno;

typedef struct lista Lista;

// Funções de criação e liberação
Lista* criaLista();
void liberaLista(Lista* li);

// Funções de consulta de informações
int tamanhoLista(Lista* li);
int listaCheia(Lista* li);
int listaVazia(Lista* li);

// Funções de inserção
int inserirFinal(Lista* li, Aluno aluno);
int inserirInicio(Lista* li, Aluno aluno);
int inserirDadoOrdenado(Lista* li, Aluno aluno);

// Funções de remoção
int removerFinal(Lista* li);
int removerInicio(Lista* li);
int removerMatricula(Lista* li, int matricula);

// Funções de consulta de dados
int retornaAlunoPorPosicao(Lista* li, int posicao, Aluno* aluno);
int retornaAlunoPorMatricula(Lista* li, int matricula, Aluno* aluno);

// Função de exibição
void exibirLista(Lista* li);
