#include "HuffTree.hpp"

void huffTreeInit(HuffTree **ht) {
    *ht = NULL;
}

void huffTreeInsert(HuffTree **ht, Data content, float *leftSonValue, float *rightSonValue) {
    if (*ht == NULL) {
        (*ht) = new HuffTree;
        content.value = (*leftSonValue) + (*rightSonValue);
        (*ht) -> item = content;
        (*ht) -> rightSon -> item.value = *rightSonValue;
        (*ht) -> leftSon -> item.value = *leftSonValue;
    } else {
        if ((*ht) -> item.value > content.value) {
            huffTreeInsert(&(*ht) -> leftSon, content, &(*ht) -> leftSon -> item.value, &(*ht) -> rightSon -> item.value);
        } else {
            huffTreeInsert(&(*ht) -> rightSon, content, &(*ht) -> leftSon -> item.value, &(*ht) -> rightSon -> item.value);
        }
    }
}





/*
    ALGORITMO DE INSERÇÃO PARA HOFFTREE

    Obs >> SEMPRE JUNTAR OS DOIS MENORES, A SOMA DELES SERÁ O VALOR DO PAI.

    1 - Verificar quais são os menores valores.
    2 - Iniciar uma árvore:
        - Pai = soma dos dois valores menores;
        - Filho direito = maior valor;
        - Filho esquerdo = menor valor;
    3 - Salvar o endereço do Pai;
    4 - Fazer isso até esvaziar o unordered_map de valores.

*/