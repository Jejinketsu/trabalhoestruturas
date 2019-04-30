#include <stdlib.h>
#include "../TAD 1/imagem.h"

typedef struct {
    int x, y;
} Ponto;

void sort(int *vetor, int n);
int binForInt(int *vetor, int qtd);
int maiorValor(Imagem imagem);
int menorValor(Imagem imagem);
float distEuclidiana(Imagem imagem, Ponto ponto1, Ponto ponto2);
float distManhattan(Imagem imagem, Ponto ponto1, Ponto ponto2);
Imagem LBP(Imagem imagem);
Imagem matrizDeConcorrencia(Imagem imagem, int dist, int angulo);
Imagem filtroDeMedia(Imagem imagem);
Imagem filtroDeMediana(Imagem imagem);