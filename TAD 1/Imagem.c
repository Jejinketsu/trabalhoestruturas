#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD-1.h"

Imagem aloca(int altura, int largura){
	Imagem imagem;
	int i;
	imagem.matriz = (int**) malloc(sizeof(int*)*altura);
	for(i=0; i<altura; i++){
		imagem.matriz[i] = (int*) malloc(sizeof(int)*largura);
	}
	imagem.altura = altura;
	imagem.largura = largura;
	return im;
}

void preenche(Imagem imagem){
	int i, j;
	srand(time(NULL));
	for(i=0; i<imagem.altura; i++){
		for(j=0; j<imagem.largura; j++){
			imagem.matriz[i][j] = rand() % 256;
		}
	}
}

void salvarImagem(Imagem imagem, char *caminho){
	FILE *aoMolho;
	int i, j;
	aoMolho = fopen(caminho, "w");
	if(aoMolho == NULL){
		fprintf(stderr,"Erro na abertura de arquivo!\n");
        exit(1);  
	}else{
		for(i=0; i<imagem.altura; i++){
			for(j=0; j<imagem.largura; j++){
				fprintf(aoMolho, "%d ", imagem.matriz[i][j]);
			}
			fprintf(aoMolho, "\n");
		}
		printf("Imagem salva com sucesso!\n");
	}
	fclose(aoMolho);
}

void lerImagem(Imagem imagem, char *caminho){
	FILE *aoMolho;
	int i, j, aux;
	aoMolho = fopen(caminho, "rt");
	if(aoMolho == NULL){
		fprintf(stderr,"Erro na abertura de arquivo!\n");
        exit(1);  
	}else{
		i = 0;
		while(!feof(aoMolho)){
			//if()   -
			imagem.matriz[i][j] = fscanf(aoMolho, "%d", &aux);
			printf(" %d", imagem.matriz[i][j]);
		}
		printf("Imagem salva com sucesso!\n");
	}
	fclose(aoMolho);
}

void mostrarImagem(Imagem imagem){
	printf("\n");
	for(int i=0; i<imagem.altura; i++){
		for(int j=0; j<imagem.largura; j++){
			printf("%d ", imagem.matriz[i][j]);
		}
		printf("\n");
	}
}

void LBP(Imagem imagem){
	int binario[8];

	for(int i=0; i<EOF; i++){
		for(int j=0; j<'\0'; j++){
			imagem.matriz[i][j];	
		}
	}
}