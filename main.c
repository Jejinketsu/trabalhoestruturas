#include <stdlib.h>
#include <stdio.h>
#include "tipos.h"

int main(){

    int qtdOrientadores = 0, id1, id2;
    int qtdOrientandos = 0, opc = 0;
    Orientador *orientadores = (Orientador *) malloc(sizeof(Orientador));
    Orientando *orientandos = (Orientando *) malloc(sizeof(Orientando));
    char nome[50], senha[20], nivel[10];
    do{
        printf("---------Menu----------\n");
        printf("1. Adicionar Orientador.\n2. Adicionar Orientando\n3. Listar Orientadores\n");
        printf("4. Listar Orientandos\n5. Listar Orientandos de um Orientador\n6. Vincular um orientador\n");
        printf("0. Sair\nin: ");
        scanf("%d", &opc);

        switch (opc){
            case 0:
                printf("Encerrando programa.\n");
                break;
            case 1:
                setbuf(stdin, NULL);
                printf("Digite o nome: ");
                scanf("%[^\n]s", nome);
                setbuf(stdin, NULL);
                printf("Digite a senha: ");
                scanf("%[^\n]s", senha);
                Orientador orientador = criarOrientador(nome, senha);
                orientador.id = qtdOrientadores;
                orientadores[qtdOrientadores] = orientador; qtdOrientadores++;
                orientadores = (Orientador *) realloc(orientadores, sizeof(Orientador)*(qtdOrientadores+1));
                break;
            case 2:
                setbuf(stdin, NULL);
                printf("Digite o nome: ");
                scanf("%[^\n]s", nome);
                setbuf(stdin, NULL);
                printf("Digite a senha: ");
                scanf("%[^\n]s", senha);
                setbuf(stdin, NULL);
                printf("Digite o nivel: ");
                scanf("%s", nivel);
                Orientando orientando = criarOrientando(nome, senha, nivel);
                orientando.id = qtdOrientandos;
                orientandos[qtdOrientandos] = orientando; qtdOrientandos++;
                orientandos = (Orientando *) realloc(orientandos, sizeof(Orientando)*(qtdOrientandos+1));
                break;
            case 3:
                listarOrientadores(orientadores, qtdOrientadores);
                break;
            case 4:
                listarOrientandos(orientandos, qtdOrientandos);
                break;
            case 5:
                printf("Digite o id do orientador desejado: ");
                scanf("%d", &id1);
                if(id1 > qtdOrientadores){
                    printf("ID não existe.");
                    break;
                }
                listarOrientandosDoOrientador(orientadores[id1]);
                break;
            case 6:
                printf("Digite o id do orientador e orientando desejados: ");
                scanf("%d %d", &id1, &id2);
                if(id1 > qtdOrientadores || id2 > qtdOrientandos){
                    printf("ID não existe.");
                    break;
                }
                addOrientando(&orientandos[id2], &orientadores[id1]);
                break;
            default:
                break;
        }
    }while(opc != 0);

    return 0;
}