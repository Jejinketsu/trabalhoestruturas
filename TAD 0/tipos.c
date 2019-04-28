#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipos.h" 

Orientando * criarOrientando(Orientando *orientandos, char *nome, char *senha, char *nivel, long matricula, int *qtd){
    Orientando orientando;
    strcpy(orientando.nome, nome);
    strcpy(orientando.senha, senha);
    orientando.matricula = matricula;
    orientando.id = *qtd;
    
    for(int i = 0; nivel[i] != '\0'; i++){
        if(nivel[i] < 97) nivel[i]+32;
    }
    strcpy(orientando.nivel, nivel);

    orientando.orientador = NULL;
    orientando.coOrientador = NULL;

    orientandos[*qtd] = orientando; (*qtd)++;
    orientandos = (Orientando *) realloc(orientandos, sizeof(Orientando)*((*qtd)+1));

    return orientandos;
}

Orientador * criarOrientador(Orientador *orientadores, char *nome, char *senha, long matricula, int *qtd){
    Orientador orientador;
    strcpy(orientador.nome, nome);
    strcpy(orientador.senha, senha);
    orientador.matricula = matricula;
    orientador.id = *qtd;
    orientador.pos = 0; orientador.grad = 0;

    orientadores[*qtd] = orientador; (*qtd)++;
    orientadores = (Orientador *) realloc(orientadores, sizeof(Orientador)*((*qtd)+1));

    return orientadores;
}

void atualizarOrientando(Orientando *orientando, char *nome, char *senha, char *nivel, long matricula){
    strcpy(orientando->nome, nome);
    strcpy(orientando->senha, senha);
    orientando->matricula = matricula;

    for(int i = 0; nivel[i] != '\0'; i++){
        if(nivel[i] < 97) nivel[i]+32;
    }
    strcpy(orientando->nivel, nivel);
    printf("Atualizado com sucesso!\n");
}

void atualizarOrientador(Orientador *orientador, char *nome, char *senha, long matricula){
    strcpy(orientador->nome, nome);
    strcpy(orientador->senha, senha);
    orientador->matricula = matricula;
    printf("Atualizado com sucesso!\n");
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

void removeOrientando(Orientando *orientando, Orientador *orientador){
    int qtd = orientador->grad + orientador->pos;
    int index = pesquisarOrientando(orientador->orientandos, orientando->matricula, qtd);
    for(int i = index; i < qtd-1; i++){
        orientador->orientandos[i] = orientador->orientandos[i+1];
    }
    if(strcmp(orientando->nivel, "graducao")) orientador->grad--;
    else if(strcmp(orientando->nivel, "mestrado") || strcmp(orientando->nivel, "doutorado")) orientador->pos--;
}

void mostrarOrientando(Orientando orientando){
    printf("ID: %d\tNome: %15s\tNivel: %10s\t matricula: %ld", orientando.id, orientando.nome, orientando.nivel, orientando.matricula);
    if(orientando.orientador != NULL) printf("\tOrientador: %15s", orientando.orientador->nome);
    if(orientando.coOrientador != NULL) printf("\tCo-Orientador: %15s", orientando.coOrientador->nome);
    printf("\n");
}

void mostrarOrientador(Orientador orientador){
    printf("ID: %d\tNome: %15s\tMatricula: %ld\n", orientador.id, orientador.nome, orientador.matricula);
}

void listarOrientandos(Orientando *orientandos, int qtd){
    for(int i = 0; i < qtd; i++){
        mostrarOrientando(orientandos[i]);
    }
}

void listarOrientadores(Orientador *orientadores, int qtd){
    for(int i = 0; i < qtd; i++){
        mostrarOrientador(orientadores[i]);
    }
}

void listarOrientandosDoOrientador(Orientador orientador){
    printf("Orientador: %s\nOrientandos: \n", orientador.nome);
    for(int i = 0; i < orientador.grad+orientador.pos; i++){
        mostrarOrientando(orientador.orientandos[i]);
    }
}

Orientador * excluirOrientador(Orientador *orientadores, int id, int *qtd){
    for(int i = id; i < (*qtd)-1; i++){
        orientadores[i] = orientadores[i+1];
        orientadores[i].id--;
    }
    orientadores = (Orientador *) realloc(orientadores, sizeof(Orientador)*(*qtd));
    printf("Exluido com sucesso!\n"); (*qtd)--;
    return orientadores;
}

Orientando * excluirOrientando(Orientando *orientandos, int id, int *qtd){
    if(orientandos[id].orientador != NULL) removeOrientando(&orientandos[id], orientandos[id].orientador);
    if(orientandos[id].coOrientador != NULL) removeOrientando(&orientandos[id], orientandos[id].coOrientador);
    for(int i = id; i < (*qtd)-1; i++){
        orientandos[i] = orientandos[i+1];
        orientandos[i].id--;
    }
    orientandos = (Orientando *) realloc(orientandos, sizeof(Orientando)*(*qtd));
    printf("Exluido com sucesso!\n"); (*qtd)--;
    return orientandos;
}

int pesquisarOrientador(Orientador *orientadores, long matricula, int qtd){
    for(int i = 0; i < qtd; i++){
        if(orientadores[i].matricula == matricula) {
            mostrarOrientador(orientadores[i]);
            return i;
        }
    }
    printf("Nao encontrado.\n");
    return -1;
}

int pesquisarOrientando(Orientando *orientandos, long matricula, int qtd){
    for(int i = 0; i < qtd; i++){
        if(orientandos[i].matricula == matricula) {
            mostrarOrientando(orientandos[i]);
            return i;
        }
    }
    printf("Nao encontrado.\n");
    return -1;
}