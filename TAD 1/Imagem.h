#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int **matriz;
	int altura, largura;
}Imagem;

Imagem aloca(int altura, int largura);

void preenche(Imagem imagem);

void salvarImagem(Imagem imagem, char *caminho);

void lerImagem(Imagem imagem, char *caminho);

void mostrarImagem(Imagem imagem);

void LBP(Imagem imagem);