#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipos.h"

void menuImagem(Orientando *orientando);

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
        printf("14. Acessar Orientando.\n");
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
            
            case 14:
                printf("Digite a matricula: ");
                scanf("%ld", &matricula);
                id1 = pesquisarOrientando(orientandos, matricula, qtdOrientandos);
                char senha[20];
                printf("Digite a senha: ");
                scanf("%s", senha);
                if(!strcmp(orientandos[id1].senha, senha)){
                    printf("Logado.\n");
                    menuImagem(&orientandos[id1]);
                }else{
                    printf("Acesso Negado.\n");
                }
                break;

            default:
                break;
        }
    }while(opc != 0);

    return 0;
}

void menuImagem(Orientando *orientando){
    int opc = 0, imgOpc, altura, largura;
    int angulo, distancia;
    Ponto ponto1, ponto2;
    char nome[20];
    do{
        printf("---Menu de Imagem---\n");
        printf("0. Deslogar.\n1. Gerar Imagem.\n2. Salvar Imagem.\n3. Ler Imagem.\n4. Mostrar Imagem.\n");
        printf("5. Maior Valor.\n6. Menor Valor.\n7. Dist Euclidiana.\n8. Dist Manhattan.\n");
        printf("9. LBP.\n10. Matriz de Concorrencia\n11. Filtro de Media.\n12. Filtro de Mediana.\n");
        scanf("%d", &opc);

        switch (opc){
        case 0:
            printf("Deslogado.\n");
            break;
        
        case 1:
            printf("Digite altura e largura: ");
            scanf("%d %d", &altura, &largura);
            orientando->imagem = aloca(altura, largura);
            orientando->imagemFiltrada = aloca(altura, largura);
            preenche(orientando->imagem);
            printf("Imagem gerada.\n");
            break;

        case 2:
            printf("principal(0) ou secundária(1)? ");
            scanf("%d", &imgOpc);
            printf("digite o nome do arquivo: ");
            scanf("%s", nome);
            sprintf(nome, "%s", ".txt");
            if(imgOpc == 0) salvarImagem(orientando->imagem, nome);
            else if(imgOpc == 1) salvarImagem(orientando->imagemFiltrada, nome);
            break;
        
        case 3:
            printf("principal(0) ou secundária(1)? ");
            scanf("%d", &imgOpc);
            printf("digite o nome do arquivo: ");
            scanf("%s", nome);
            sprintf(nome, "%s", ".txt");
            if(imgOpc == 0) orientando->imagem = lerImagem(nome);
            else if(imgOpc == 1) orientando->imagemFiltrada = lerImagem(nome);
            break;

        case 4:
            printf("principal(0) ou secundária(1)? ");
            scanf("%d", &imgOpc);
            if(imgOpc == 0) mostrarImagem(orientando->imagem);
            else if(imgOpc == 1) mostrarImagem(orientando->imagemFiltrada);
            break;
        
        case 5:
            printf("principal(0) ou secundária(1)? ");
            scanf("%d", &imgOpc);
            printf("Maior Valor: ");
            if(imgOpc == 0) printf("%d\n", maiorValor(orientando->imagem));
            else if(imgOpc == 1) printf("%d\n", maiorValor(orientando->imagemFiltrada));
            break;
        
        case 6:
            printf("principal(0) ou secundária(1)? ");
            scanf("%d", &imgOpc);
            printf("Menor Valor: ");
            if(imgOpc == 0) printf("%d\n", menorValor(orientando->imagem));
            else if(imgOpc == 1) printf("%d\n", menorValor(orientando->imagemFiltrada));
            break;
        
        case 7:
            printf("principal(0) ou secundária(1)? ");
            scanf("%d", &imgOpc);
            printf("Digite as coordenas de x e y de dois pontos(x1 y1 x2 y2): ");
            scanf("%d %d %d %d", &ponto1.x, &ponto1.y, &ponto2.x, &ponto2.y);
            printf("Distancia: ");
            if(imgOpc == 0) printf("%.2f\n", distEuclidiana(orientando->imagem, ponto1, ponto2));
            else if(imgOpc == 1) printf("%.2f\n", distEuclidiana(orientando->imagemFiltrada, ponto1, ponto2));
            break;
        
        case 8:
            printf("principal(0) ou secundária(1)? ");
            scanf("%d", &imgOpc);
            printf("Digite as coordenas de x e y de dois pontos(x1 y1 x2 y2): ");
            scanf("%d %d %d %d", &ponto1.x, &ponto1.y, &ponto2.x, &ponto2.y);
            printf("Distancia: ");
            if(imgOpc == 0) printf("%.2f\n", distManhattan(orientando->imagem, ponto1, ponto2));
            else if(imgOpc == 1) printf("%.2f\n", distManhattan(orientando->imagemFiltrada, ponto1, ponto2));
            break;
        
        case 9:
            orientando->imagemFiltrada = LBP(orientando->imagem);
            printf("Filtro aplicado. Resultado na imagem secundaria.\n");
            break;
        
        case 10:
            printf("Digite o angulo(0, 45, 90 ou 135) e a distancia: ");
            scanf("%d %d", &angulo, &distancia);
            orientando->imagemFiltrada = matrizDeConcorrencia(orientando->imagem, distancia, angulo);
            printf("Filtro aplicado. Resultado na imagem secundaria.\n");
            break;

        case 11:
            orientando->imagemFiltrada = filtroDeMedia(orientando->imagem);
            printf("Filtro aplicado. Resultado na imagem secundaria.\n");
            break;

        case 12:
            orientando->imagemFiltrada = filtroDeMediana(orientando->imagem);
            printf("Filtro aplicado. Resultado na imagem secundaria.\n");
            break;

        default:
            break;
        }
    }while(opc != 0);
}