#include <stdlib.h>
#include <stdio.h>
#include "tipos.h"

int main(){

    int qtdOrientadores = 0, id1, id2;
    int qtdOrientandos = 0, opc = 0;
    long matricula;
    Orientador *orientadores = (Orientador *) malloc(sizeof(Orientador));
    Orientando *orientandos = (Orientando *) malloc(sizeof(Orientando));
    char nome[50], senha[20], nivel[10];
    do{
        printf("---------Menu----------\n");
        printf("1. Adicionar Orientador.\n2. Adicionar Orientando.\n3. Listar Orientadores.\n");
        printf("4. Listar Orientandos.\n5. Listar Orientandos de um Orientador.\n6. Vincular um orientador.\n");
        printf("7. Desvincular um orientando\n8. Atualizar Orientador.\n9. Atualizar Orientando.\n10. Excluir Orientador.\n");
        printf("11. Excluir Orientando.\n12. Pesquisar Orientador.\n13. Pesquisar Orientando.\n");
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
                printf("Digite a matricula: ");
                scanf("%ld", &matricula);
                orientadores = criarOrientador(orientadores, nome, senha, matricula, &qtdOrientadores);
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
                printf("Digite a matricula: ");
                scanf("%ld", &matricula);
                orientandos = criarOrientando(orientandos, nome, senha, nivel, matricula, &qtdOrientandos);
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

            case 7:
                printf("Digite o id do orientador e orientando desejados: ");
                scanf("%d %d", &id1, &id2);
                if(id1 > qtdOrientadores || id2 > qtdOrientandos){
                    printf("ID não existe.");
                    break;
                }
                removeOrientando(&orientandos[id2], &orientadores[id1]);
                break;
            case 8:
                if(qtdOrientadores == 0){
                    printf("Não existem orientadores.\n");
                    break;
                }
                setbuf(stdin, NULL);
                printf("Digite o id do orientador: ");
                scanf("%d", &id1);
                setbuf(stdin, NULL);
                printf("Digite o nome: ");
                scanf("%[^\n]s", nome);
                setbuf(stdin, NULL);
                printf("Digite a senha: ");
                scanf("%[^\n]s", senha);
                printf("Digite a matricula: ");
                scanf("%ld", &matricula);
                setbuf(stdin, NULL);
                atualizarOrientador(&orientadores[id1], nome, senha, matricula);
                break;

            case 9:
                if(qtdOrientandos == 0){
                    printf("Não existem orientandos.\n");
                    break;
                }
                setbuf(stdin, NULL);
                printf("Digite o id do orientando: ");
                scanf("%d", &id1);
                setbuf(stdin, NULL);
                printf("Digite o nome: ");
                scanf("%[^\n]s", nome);
                setbuf(stdin, NULL);
                printf("Digite a senha: ");
                scanf("%[^\n]s", senha);
                setbuf(stdin, NULL);
                printf("Digite o nivel: ");
                scanf("%s", nivel);
                printf("Digite a matricula: ");
                scanf("%ld", &matricula);
                atualizarOrientando(&orientandos[id1], nome, senha, nivel, matricula);
                break;

            case 10:
                if(qtdOrientadores == 0){
                    printf("Não existem orientadores.\n");
                    break;
                }
                setbuf(stdin, NULL);
                printf("Digite o id do orientador: ");
                scanf("%d", &id1);
                orientadores = excluirOrientador(orientadores, id1, &qtdOrientadores);
                break;

            case 11:
                if(qtdOrientandos == 0){
                    printf("Não existem orientandos.\n");
                    break;
                }
                setbuf(stdin, NULL);
                printf("Digite o id do orientando: ");
                scanf("%d", &id1);
                orientandos = excluirOrientando(orientandos, id1, &qtdOrientandos);
                break;

            case 12:
                if(qtdOrientadores == 0){
                    printf("Não existem orientadores.\n");
                    break;
                }
                setbuf(stdin, NULL);
                printf("Digite a matricula do Orientador: ");
                scanf("%ld", &matricula);
                pesquisarOrientador(orientadores, matricula, qtdOrientadores);
                break;

            case 13:
                if(qtdOrientandos == 0){
                    printf("Não existem orientandos.\n");
                    break;
                }
                setbuf(stdin, NULL);
                printf("Digite a matricula do Orientando: ");
                scanf("%ld", &matricula);
                pesquisarOrientando(orientandos, matricula, qtdOrientandos);
                break;

            default:
                break;
        }
    }while(opc != 0);

    return 0;
}