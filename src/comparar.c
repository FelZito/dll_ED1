#include "jogador.h"
#include <string.h> // Para poder usar o comando strcmp

#define TRUE 1
#define FALSE 0


#ifndef COMPARA_C_
#define COMPARA_C_

int cmpString(void* item, void* chave) {
    JOGADOR* item_tp = (JOGADOR*)item;

    // Verifica se os nomes são iguais
    if (strcmp(item_tp-> nome, (char*)chave) == FALSE) {  
        return TRUE;
    }

    return FALSE;
}


int cmpInt(void* item, void* chave) {
    JOGADOR* item_tp = (JOGADOR*)item;

    // Verifica se os valores recebidos são do tipo int
    if (item_tp-> idade == *(int*) chave) {
        return  TRUE;
    }
    return FALSE;
}


int cmpFloat(void* item, void* chave) {
    JOGADOR* item_tp = (JOGADOR*)item;

    // Verifica o tipo informado em salário
    if (item_tp-> salario == *(float*)chave) {
        return TRUE;
    }
    return FALSE;
}

#endif // ifndef