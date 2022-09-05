#include "HuffTree.hpp"

void huffTreeInit(HuffTree **ht) {
    *ht = NULL;
}

void huffTreeInsert(HuffTree **t, Data content) {
    if (*t == NULL) {
        (*t) = new HuffTree;
        (*t) -> rightSon = NULL;
        (*t) -> leftSon = NULL;
        (*t) -> item = content;
    } else {
        if ((*t) -> item.normalizedValue > content.normalizedValue) {
            huffTreeInsert(&(*t) -> leftSon, content);
        } else {
            huffTreeInsert(&(*t) -> rightSon, content);
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