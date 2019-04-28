#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipos.h" 

Orientando criarOrientando(char *nome, char *senha, char *nivel, long matricula){
    Orientando orientando;
    strcpy(orientando.nome, nome);
    strcpy(orientando.senha, senha);
    orientando.matricula = matricula;
    
    for(int i = 0; nivel[i] != '\0'; i++){
        if(nivel[i] < 97) nivel[i]+32;
    }
    strcpy(orientando.nivel, nivel);

    orientando.orientador = NULL;
    orientando.coOrientador = NULL;

    return orientando;
}

Orientador criarOrientador(char *nome, char *senha, long matricula){
    Orientador orientador;
    strcpy(orientador.nome, nome);
    strcpy(orientador.senha, senha);
    orientador.matricula = matricula;
    orientador.pos = 0; orientador.grad = 0;
    return orientador;
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

void excluirOrientador(Orientador *orientadores, int id, int qtd){
    for(int i = id; i < qtd-1; i++){
        orientadores[i] = orientadores[i+1];
        orientadores[i].id--;
    }
    printf("Exluido com sucesso!\n");
}

void excluirOrientando(Orientando *orientandos, int id, int qtd){
    for(int i = id; i < qtd-1; i++){
        orientandos[i] = orientandos[i+1];
        orientandos[i].id--;
    }
    printf("Exluido com sucesso!\n");
}

int pesquisarOrientador(Orientador *orientadores, long matricula, int qtd){
    for(int i = 0; i < qtd; i++){
        if(orientadores[i].matricula == matricula) {
            mostrarOrientador(orientadores[i]);
            return 0;
        }
    }
    printf("Nao encontrado.\n");
    return -1;
}

int pesquisarOrientando(Orientando *orientandos, long matricula, int qtd){
    for(int i = 0; i < qtd; i++){
        if(orientandos[i].matricula == matricula) {
            mostrarOrientando(orientandos[i]);
            return 0;
        }
    }
    printf("Nao encontrado.\n");
    return -1;
}