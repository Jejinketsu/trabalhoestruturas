#include <stdlib.h>
#include <stdio.h>
#include "imgProcessing.h"

int main(){

    Imagem imagem = lerImagem("teste.txt");
    mostrarImagem(imagem);

    imagem = LBP(imagem);

    mostrarImagem(imagem);
    salvarImagem(imagem, "filtro.txt");

    return 0;
}