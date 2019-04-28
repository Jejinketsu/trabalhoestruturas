#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipos.h" 

Orientando criarOrientando(char *nome, char *senha, char *nivel){
    Orientando orientando;
    strcpy(orientando.nome, nome);
    strcpy(orientando.senha, senha);
    
    for(int i = 0; nivel[i] != '\0'; i++){
        if(nivel[i] < 97) nivel[i]+32;
    }
    strcpy(orientando.nivel, nivel);

    orientando.orientador = NULL;
    orientando.coOrientador = NULL;

    return orientando;
}

Orientador criarOrientador(char *nome, char *senha){
    Orientador orientador;
    strcpy(orientador.nome, nome);
    strcpy(orientador.senha, senha);
    orientador.pos = 0; orientador.grad = 0;
    return orientador;
}

void addOrientando(Orientando *orientando, Orientador *orientador){
    
    int index = orientador->grad+orientador->pos;
    if(index >= 10){
        printf("Possui o numero maximo de orientandos.");
    } else if(strcmp(orientando->nivel, "graducao") && orientador->grad < 4){
        orientador->orientandos[index] = *orientando;
        orientador->grad++;
        orientando->orientador = orientador;
    } else if(orientador->pos < 6 && (strcmp(orientando->nivel, "mestrado") || strcmp(orientando->nivel, "doutorado"))){
        orientador->orientandos[index] = *orientando;
        orientador->pos++;
        orientando->orientador = orientador;
    } else {
        printf("Não foi possível adicionar o orientando");
    }
}

void listarOrientandos(Orientando *orientandos, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("ID: %d\tNome: %s\tNivel: %s", orientandos[i].id, orientandos[i].nome, orientandos[i].nivel);
        if(orientandos[i].orientador != NULL) printf("\tOrientador: %s", orientandos[i].orientador->nome);
        if(orientandos[i].coOrientador != NULL) printf("\tCo-Orientador: %s", orientandos[i].coOrientador->nome);
        printf("\n");
    }
}

void listarOrientadores(Orientador *orientadores, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("ID: %d\tNome: %s\n", orientadores[i].id, orientadores[i].nome);
    }
}

void listarOrientandosDoOrientador(Orientador orientador){
    printf("Orientador: %s\nOrientandos: \n", orientador.nome);
    for(int i = 0; i < orientador.grad+orientador.pos; i++){
        printf("Nome: %s\tNivel: %s\n", orientador.orientandos[i].nome, orientador.orientandos[i].nivel);
    }
}