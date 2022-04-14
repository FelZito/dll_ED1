#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

#ifndef Dll_C_
#define Dll_C_

#define TRUE 1
#define FALSE 0

// Implementando função Criar
DLList *dllCreate(void) {
    DLList *l;
    l = (DLList *)malloc(sizeof(DLList));
    if (l != NULL){
        l -> cur = NULL;
        l -> first = NULL;
        return l;  
    }
    return NULL;
}

// Implementando função Inserir
int dllInsertAsLast(DLList *l, void *data) {
    DLNode* node;
    DLNode* last;
    
    if (l == NULL) {
        return FALSE;
    }
    
    node = (DLNode*)malloc(sizeof(DLNode));
    if (node == NULL) {
        return FALSE;
    }
    
    node->data = data;
    node->next = NULL;
    
    if (l->first == NULL) {
        l->first = node;
    } else {
        last = l->first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = node;
    }
    return TRUE;
}

// Implementando função Remover
void dllRemoveSpec(DLList *l, void* chave, int(*cmp)(void*, void*)) {
    DLNode *atual, *proximo, *anterior;
    int procurados;

    if (l == NULL || l -> first == NULL){
        return;
    }
    
    //Procura o valor
    atual = l -> first;
    procurados = cmp(atual -> data, chave);

    while (procurados != TRUE && atual -> next != NULL){
        atual = atual -> next;
        procurados = cmp(atual -> data, chave);
    }

    if (procurados == TRUE){
        proximo = atual -> next;
        anterior = atual -> prev;
        if (anterior == NULL){
            l -> first = proximo;
        }
        else {
            anterior -> next = proximo;
        }
        if (proximo != NULL){
            proximo -> prev = anterior;
        }
        free(atual);
    }
    
    
}

//Implementa a função esvaziar
void dllEmpty(DLList* l){
    DLNode *atual, *anterior;
    if (l != NULL){
        if (l -> first != NULL){
            atual = l -> first;
            while (atual != NULL){
                free(atual -> data);
                anterior = atual;
                atual = atual -> next;
                free(anterior);
            }
            
        }
        l->first = NULL;
    }
    
}

//Implementa a função destruir
int dllDestroy(DLList* l){
    if (l != NULL && l -> first == NULL){ //Se a lista estiver vazia, destrói
        free(l);
        return TRUE;
    }

    return FALSE;
    
}

//Implementa a função
void* dllGetFirst(DLList *l){
    if ( l != NULL) {
        l->cur = l->first;
        return l->cur;
    }    
    return NULL;
}

void* dllGetNext(DLList *l){
    if (l != NULL){
        if (l -> cur != NULL){
            l -> cur = l -> cur -> next;
            return l -> cur;
        }
    }
    return NULL;    
}


void* dllGet(DLList *l, void* chave, int (*cmp)(void*, void*)){
    DLNode* cur;
    if (l != NULL) {
        if (l->first != NULL) {
            cur = l->first;
            while (cur->next != NULL && cmp(chave, cur->data) != TRUE) {
                cur = cur -> next;
            }
            if (cmp(chave, cur->data) == TRUE) {
                return cur;
            }
        }
    }
    return NULL;
}


void* dllRemove(DLList *l, void* chave) {
    DLNode *atual;
    DLNode *anterior;
    DLNode *proximo;

        
    if (l == NULL || l->first == NULL) {
        return NULL;
    }
        
    atual = l->first;
        
    while (atual != chave && atual->next != NULL) {
        atual = atual->next;
    }
        
    proximo = atual->next;
    anterior = atual->prev;
    if (anterior != NULL) {
        anterior->next = proximo;
    } else {
        l->first = proximo;
    }
    if (proximo != NULL) {
        proximo->prev = anterior;
    }
        
    free(atual);
}


#endif //idfndef

