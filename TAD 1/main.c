#include "TAD-1.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
	Imagem imagem;
	int altura, largura, i, j;
	printf("Digite a altura e a largura:\n");
	scanf("%d%d", &altura, &largura);
	imagem = aloca(altura, largura);
	
	preenche(imagem);
	salvarImagem(imagem, "teste.txt");
	
	lerImagem(imagem,"teste.txt");

	mostrarImagem(imagem);
	
}
