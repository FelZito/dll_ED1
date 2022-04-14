#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "jogador.h"
#include "comparar.h"

int main()
{
    int opcao, c = 1, i;
    int totalItens, buscarItem;
    char nome[30];
    float salario;

    DLList *Dll = NULL;
    JOGADOR *jogador;
    DLNode* encontrado;

    // Implementando o menu
    do
    {
        printf("\033[2J \033[H");
        printf("============================ \n");
        printf("      MENU OPERATIVO \n");
        printf("============================ \n");
        printf("1 - Criar uma coleção \n");
        printf("2 - Inserir elementos na coleção \n");
        printf("3 - Listar todos os elementos da coleção \n");
        printf("4 - Consultar algum elemento da coleção \n");
        printf("5 - Remover elemento da coleção \n");
        printf("6 - Esvaziar coleção \n");
        printf("7 - Destruir coleção \n");
        printf("Informe a opção desejada: ");

        opcao = -1; //Se o usuário informar um valor de tipo != de inteiro, o programa encerra.
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            Dll = dllCreate();

            if (Dll != NULL)
            {
                printf("COLEÇÃO CRIADA! \n");
            }
            else
            {
                printf("ERRO AO CRIAR COLEÇÃO! \n"); // Se a coleção for <= 0, não será possível criar coleção
            }
            break;

        case 2:
            if (Dll == NULL)
            {
                printf("DEFINA PRIMEIRO O TAMANHO DA COLEÇÃO \n");
                break;
            }


            // Aloca as posições da  coleção
            jogador = (JOGADOR *)malloc(sizeof(JOGADOR));

            if (jogador == NULL)
            {
                printf("IMPOSSÍVEL ALOCAR!"); // Quebra o programa aqui
                break;
            }

            printf("Informe o nome do jogador: ");
            scanf("%s", jogador-> nome);

            printf("Informe a idade do jogador: ");
            scanf("%d", &jogador-> idade);

            printf("Informe o salário do jogador: ");
            scanf("%f", &jogador-> salario);

            dllInsertAsLast(Dll, (void*)jogador);

            printf("Jogador: %s  Idade: %d | Salário: R$%.2f - INSERIDO \n",    jogador->nome, jogador-> idade, jogador-> salario);
            break;

        case 3:
            if (Dll == NULL)
            {
                printf("DEFINA PRIMEIRO A LISTA! \n");
                break;
            }

            if (Dll->first == NULL)
            {
                printf("ERRO! LISTA NÃO DEFINIDA. \n");
                break;
            }

            DLNode* atual = (DLNode*)dllGetFirst(Dll);
            while (atual != NULL) {

                jogador = (JOGADOR*)atual->data;
                printf("POSIÇÃO %d: | JOGADOR: %s | IDADE: %d | SALÁRIO: R$%.2f \n", i, jogador->nome, jogador->idade, jogador->salario);
                
                atual = (DLNode*)dllGetNext(Dll);
            }
            break;

        case 4:
            if (Dll == NULL)
            {
                printf("ERRO! LISTA NÃO DEFINIDA. \n");
                break;
            }

            if (Dll->first == NULL)
            {
                printf("ERRO! SUA LISTA ESTÁ VAZIA. \n");
                break;
            }

            printf("BUSCAR ITEM: \n");
            printf("1 - Jogador \n");
            printf("2 - Idade \n");
            printf("3 - Salário \n");
            printf("Informe a opção desejada: ");
            scanf("%d", &buscarItem);

            
            switch (buscarItem)
            {
            case 1:
                printf("Informe o nome do jogador que deseja encontrar: ");
                scanf("%s", nome);
                encontrado = dllGet(Dll, (void *)nome, cmpString);
                break;
            case 2:
                printf("Informe a idade do jogador que deseja encontrar: ");
                scanf("%d", &opcao);
                encontrado = dllGet(Dll, (void *)&opcao, cmpInt);
                break;
            case 3:
                printf("Informe o salário do jogador que deseja encontrar: ");
                scanf("%f", &salario);
                encontrado = dllGet(Dll, (void *)&salario, cmpFloat);
            }

            if (encontrado != NULL) // Caso seja satisfeito, vamos para esse menu
            {
                jogador = (JOGADOR*)encontrado->data;
                printf("============================ \n");
                printf("  JOGADOR IDENTIFICADO\n");
                printf("============================ \n");
                printf("Nome: %s \n", jogador->nome);
                printf("Idade: %d \n", jogador->idade);
                printf("salário: R$%.2f \n", jogador->salario);
            }
            else
            {
                printf("ERRO! JOGADOR NÃO IDENTIFICADO. \n");
            }
            break;

        case 5:
            if (Dll == NULL)
            {
                printf("ERRO! LISTA NÃO DEFINIDA. \n");
                break;
            }

            if (Dll->first == NULL)
            {
                printf("ERRO! SUA LISTA ESTÁ VAZIA.");
                break;
            }

            printf("BUSCAR ITEM A SER REMOVIDO: \n");
            printf("1 - Jogador \n");
            printf("2 - Idade \n");
            printf("3 - Salário \n");
            printf("Informe a opção desejada: ");
            scanf("%d", &buscarItem);

            
            switch (buscarItem)
            {
            case 1:
                printf("Informe o nome do jogador que deseja encontrar: ");
                scanf("%s", nome);
                encontrado = dllGet(Dll, (void *)nome, cmpString);
                break;
            case 2:
                printf("Informe a idade que deseja encontrar: ");
                scanf("%d", &opcao);
                encontrado = dllGet(Dll, (void *)&opcao, cmpInt);
                break;
            case 3:
                printf("Informe o salário que deseja encontrar: ");
                scanf("%f", &salario);
                encontrado = dllGet(Dll, (void *)&salario, cmpFloat);
                break;
            }

            if (encontrado != NULL)
            {
                jogador = (JOGADOR*)encontrado->data;
                printf("INFORME O ITEM QUE DESEJA REMOVER: \n");
                printf("Jogador: %s \n", jogador->nome);
                printf("Idade: %d \n" , jogador->idade);
                printf("Salário: %.2f \n", jogador->salario);
                printf("CASO QUEIRA REMOVER ESTE ITEM, TECLE 1. CASO NÃO QUEIRA, TECLE QUALQUER OUTRO NÚMERO! \n");
                printf("Informe a opção desejada: ");
                scanf("%d", &buscarItem);

                switch (buscarItem)
                {
                case 1:
                    dllRemove(Dll, encontrado);
                }
            }
            break;
        case 6:
            if (Dll == NULL)
            {
                printf("ERRO! LISTA NÃO DEFINIDA. \n");
                break;
            }

            if (Dll->first == NULL) {
                    printf("ERRO! SUA LISTA ESTÁ VAZIA");
                    break;
            }
            dllEmpty(Dll);
            printf("COLEÇÃO ESVAZIADA! \n");
            break;
        case 7:
            if (Dll == NULL)
            {
                printf("ERRO! COLEÇÃO NÃO DEFINIDA. \n");
                break;
            }

            if (Dll->first != NULL)
            {
                printf("REMOVA TODOS OS ITENS DA COLEÇÃO PARA PODER DESTRUI-LA! \n");
                break;
            }
            dllDestroy(Dll);
            printf("COLEÇÃO DESTRUIDA! \n");
            Dll = NULL;
            break;
        default:
            printf("FECHANDO PROGRAMA...  \n");
            c = 0;
        }

        // Limpando terminal e capturando tecla
        printf("Pressione um botão para continuar \n");
        while(getchar() != '\n');       
        getchar(); 

    } while (c);
}