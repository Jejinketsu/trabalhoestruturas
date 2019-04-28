typedef struct orientando Orientando;
typedef struct orientador Orientador;

struct orientando{
    long matricula;
    int id;
    char nome[50], senha[20];
    char nivel[10];
    Orientador *orientador, *coOrientador;
};

struct orientador{
    long matricula;
    int pos, grad, id;
    char nome[50], senha[20];
    Orientando orientandos[10];
};

Orientando criarOrientando(char *nome, char *senha, char *nivel, long matricula);
Orientador criarOrientador(char *nome, char *senha, long matricula);
void atualizarOrientando(Orientando *orientando, char *nome, char *senha, char *nivel, long matricula);
void atualizarOrientador(Orientador *orientador, char *nome, char *senha, long matricula);
void addOrientando(Orientando *orientando, Orientador *orientador);
void mostrarOrientando(Orientando orientando);
void mostrarOrientador(Orientador orientador);
void listarOrientandos(Orientando *orientandos, int qtd);
void listarOrientadores(Orientador *orientadores, int qtd);
void listarOrientandosDoOrientador(Orientador orientador);
void excluirOrientador(Orientador *orientador, int id, int qtd);
void excluirOrientando(Orientando *orientandos, int id, int qtd);
int pesquisarOrientador(Orientador *orientadores, long matricula, int qtd);
int pesquisarOrientando(Orientando *orientandos, long matricula, int qtd);