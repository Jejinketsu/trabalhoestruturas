#include <stdlib.h>
#include "../TAD 1/imagem.h"

typedef struct {
    int x, y;
} Ponto;

void sort(int *vetor, int n);
int maiorValor(Imagem imagem);
int menorValor(Imagem imagem);
float distEuclidiana(Imagem imagem, Ponto ponto1, Ponto ponto2);
float distManhattan(Imagem imagem, Ponto ponto1, Ponto ponto2);
void filtroDeMedia(Imagem *imagem);
void filtroDeMediana(Imagem *imagem);