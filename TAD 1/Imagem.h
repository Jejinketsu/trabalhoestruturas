#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int **matriz;
	int altura, largura;
}Imagem;

Imagem aloca(int altura, int largura);

void preenche(Imagem imagem);

void salvarImagem(Imagem imagem, char *caminho);

Imagem lerImagem(char *caminho);

void mostrarImagem(Imagem imagem);