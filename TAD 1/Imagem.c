#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "imagem.h"

Imagem aloca(int altura, int largura){
	Imagem imagem;
	int i;
	imagem.matriz = (int**) malloc(sizeof(int*)*altura);
	for(i = 0; i < altura; i++){
		imagem.matriz[i] = (int*) malloc(sizeof(int)*largura);
	}
	imagem.altura = altura;
	imagem.largura = largura;
	return imagem;
}

void preenche(Imagem imagem){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < imagem.altura; i++){
		for(j = 0; j < imagem.largura; j++){
			imagem.matriz[i][j] = rand() % 256;
		}
	}
}

void salvarImagem(Imagem imagem, char *caminho){
	FILE *arquivo;
	int i, j;
	arquivo = fopen(caminho, "w");
	
	if(arquivo == NULL){
		fprintf(stderr,"Erro na abertura de arquivo!\n");
        exit(1);  
	}else{
		for(i = 0; i < imagem.altura; i++){
			for(j = 0; j < imagem.largura; j++){
				fprintf(arquivo, "%d ", imagem.matriz[i][j]);
			}
			fprintf(arquivo, "\n");
		}
		printf("Imagem salva com sucesso!\n");
	}
	fclose(arquivo);
}

Imagem lerImagem(char *caminho){
	Imagem imagem; FILE *arquivo;
	int i = 0, j = 0, aux;
	arquivo = fopen(caminho, "r");

	if(arquivo == NULL){
		fprintf(stderr,"Erro na abertura de arquivo!\n");
        exit(1);  
	}else{
		while(!feof(arquivo)){
			char c = fgetc(arquivo);
			if(c == ' ') i++;
			else if (c == '\n') j++;
		}

		i = i/j; fseek(arquivo, 0, SEEK_SET);
		imagem = aloca(j, i);

		for(int i = 0; i < imagem.altura; i++){
			for(int j = 0; j < imagem.largura; j++){
				fscanf(arquivo, "%d ", &aux);
				imagem.matriz[i][j] = aux;
			}
		}

		printf("Imagem lida com sucesso!\n");
	}
	fclose(arquivo);

	return imagem;
}

void mostrarImagem(Imagem imagem){
	printf("\n");
	for(int i = 0; i < imagem.altura; i++){
		for(int j = 0; j < imagem.largura; j++){
			printf("%d ", imagem.matriz[i][j]);
		}
		printf("\n");
	}
}