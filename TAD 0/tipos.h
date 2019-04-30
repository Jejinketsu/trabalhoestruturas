#include "../TAD 2/imgProcessing.h"

typedef struct orientando Orientando;
typedef struct orientador Orientador;

struct orientando{
    long matricula;
    int id;
    char nome[50], senha[20];
    char nivel[10];
    Imagem imagem, imagemFiltrada;
    Orientador *orientador, *coOrientador;
};

struct orientador{
    long matricula;
    int pos, grad, id;
    char nome[50], senha[20];
    Orientando orientandos[10];
};

Orientando * criarOrientando(Orientando *orientandos, char *nome, char *senha, char *nivel, long matricula, int *qtd);
Orientador * criarOrientador(Orientador *orientadores, char *nome, char *senha, long matricula, int *qtd);
void atualizarOrientando(Orientando *orientando, char *nome, char *senha, char *nivel, long matricula);
void atualizarOrientador(Orientador *orientador, char *nome, char *senha, long matricula);
void addOrientando(Orientando *orientando, Orientador *orientador);
void removeOrientando(Orientando *orientando, Orientador *orientador);
void mostrarOrientando(Orientando orientando);
void mostrarOrientador(Orientador orientador);
void listarOrientandos(Orientando *orientandos, int qtd);
void listarOrientadores(Orientador *orientadores, int qtd);
void listarOrientandosDoOrientador(Orientador orientador);
Orientador * excluirOrientador(Orientador *orientador, int id, int *qtd);
Orientando * excluirOrientando(Orientando *orientandos, int id, int *qtd);
int pesquisarOrientador(Orientador *orientadores, long matricula, int qtd);
int pesquisarOrientando(Orientando *orientandos, long matricula, int qtd);