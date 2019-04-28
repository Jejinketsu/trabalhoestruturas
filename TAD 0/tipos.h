typedef struct orientando Orientando;
typedef struct orientador Orientador;

struct orientando{
    int id;
    char nome[50], senha[20];
    char nivel[10];
    Orientador *orientador, *coOrientador;
};

struct orientador{
    int pos, grad, id;
    char nome[50], senha[20];
    Orientando orientandos[10];
};

Orientando criarOrientando(char *nome, char *senha, char *nivel);
Orientador criarOrientador(char *nome, char *senha);
void addOrientando(Orientando *orientando, Orientador *orientador);
void listarOrientandos(Orientando *orientandos, int qtd);
void listarOrientadores(Orientador *orientadores, int qtd);
void listarOrientandosDoOrientador(Orientador orientador);