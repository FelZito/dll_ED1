/*
    Criando o header Dll.h
    A implementação de Dll.h encontrase em ./src/Dll.c\
*/

#ifndef DLL_H_
#define DLL_H_

typedef struct _dlnode_ {
    struct _dlnode_ *next, *prev;
    void* data;
}DLNode;



typedef struct _dllist_
{
     DLNode *first;     
     DLNode *cur;
}DLList;

// Atribuição das funções

DLList *dllCreate ();
int dllInsertAsLast (DLList *l, void *data);
void dllRemoveSpec(DLList *l, void* chave, int (*cmp)(void*, void*));
void dllEmpty(DLList* l);
int dllDestroy(DLList* l);
void* dllGetFirst(DLList* l);
void* dllGetNext(DLList* l);
void* dllGet(DLList *l, void* chave, int (*cmp)(void*, void*));
void* dllRemove(DLList *l, void* chave);

#endif 