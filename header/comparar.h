/*
    Criando o header Dll.h
    A implementação de Dll.h encontrase em ./src/Dll.c\
*/

#ifndef COMPARAR_H_
#define COMPARAR_H_

// Funções para comparar nomes (string), idade (int), salário (float)

int   cmpString   (void* item, void* chave); 
int   cmpInt      (void* item, void* chave);
int   cmpFloat    (void* item, void* chave);


#endif // COMPARAR_H_