#include <stdlib.h>
#include <math.h>
#include "imgProcessing.h"

void sort(int *vetor, int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n;j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        int aux = vetor[i]; 
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

int maiorValor(Imagem imagem){
    int maior = 0;
    for(int i = 0; i < imagem.altura; i++){
        for(int j = 0; j < imagem.largura; j++){
            if(imagem.matriz[i][j] > maior) maior = imagem.matriz[i][j];
        }
    }
    return maior;
}

int menorValor(Imagem imagem){
    int menor = 255;
    for(int i = 0; i < imagem.altura; i++){
        for(int j = 0; j < imagem.largura; j++){
            if(imagem.matriz[i][j] < menor) menor = imagem.matriz[i][j];
        }
    }
    return menor;
}

float distEuclidiana(Imagem imagem, Ponto ponto1, Ponto ponto2){
    return sqrt(pow((ponto1.x - ponto2.x), 2) + pow((ponto1.y - ponto2.y), 2));
}

float distManhattan(Imagem imagem, Ponto ponto1, Ponto ponto2){
    return (abs(ponto1.x - ponto2.x) + abs(ponto1.y - ponto2.y));
}

Imagem LBP(Imagem imagem){
    Imagem imagemNova = aloca(imagem.altura, imagem.largura);
    int binario[8];
    int kernel = 3m cont;
    for(int ka = 0; ka < imagem.altura; ka++){
        for(int kl = 0; kl < imagem.largura; kl++){
            cont = 0;
            int vc = imagem.matriz[(ka+1)%imagem.altura][(kl+1)%imagem.largura]
            for(int i = ka; i < ka+kernel; i++){
                for(int j = kl; j < kl+kernel; j++){
                    if(cont == 4) continue;
                    if(imagem.matriz[i%imagem.altura][j%imagem.largura] >= vc)binario[cont] = 1; cont++;
                    else binario[cont] = 0;
                }
            }
            
        }
    }
    return imagemNova;
}

Imagem filtroDeMedia(Imagem imagem){
    Imagem imagemNova = aloca(imagem.altura, imagem.largura);
    int soma, kernel = 3, media = 0;
    for(int ka = 0; ka < imagem.altura; ka++){
        for(int kl = 0; kl < imagem.largura; kl++){
            soma = 0;
            for(int i = ka; i < ka+kernel; i++){
                for(int j = kl; j < kl+kernel; j++){
                    soma += imagem.matriz[i%imagem.altura][j%imagem.largura];
                }
            }
            media = (int) (soma/9);
            imagemNova.matriz[(ka+1)%imagem.altura][(kl+1)%imagem.largura] = media;
        }
    }
    return imagemNova;
}

Imagem filtroDeMediana(Imagem imagem){
    Imagem imagemNova = aloca(imagem.altura, imagem.largura);
    int kernel = 3, media = 0, vetorK[9], cont;
    int elementosK = kernel*kernel;
    for(int ka = 0; ka < imagem.altura; ka++){
        for(int kl = 0; kl < imagem.largura; kl++){
            cont = 0;
            for(int i = ka; i < ka+kernel; i++){
                for(int j = kl; j < kl+kernel; j++){
                    vetorK[cont] = imagem.matriz[i%imagem.altura][j%imagem.largura]; cont++;
                }
            }
            sort(vetorK, elementosK);
            if(elementosK%2 == 0) media = (vetorK[elementosK/2] + vetorK[(elementosK/2)+1])/2;
            else media = vetorK[elementosK/2];
            imagemNova.matriz[(ka+1)%imagem.altura][(kl+1)%imagem.largura] = media;
        }
    }
    return imagemNova;
}