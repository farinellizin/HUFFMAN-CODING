#include "queue.hpp"

void MEQueue(Queue *q) {
    q -> first = new qBlock;
    q -> last = q -> first;
    q -> first -> prox = NULL;
}

void doQueue(Queue *q, qData value) {
    q -> last -> prox = new qBlock;
    q -> last = q -> last -> prox;
    q -> last -> data = value;
    q -> last -> prox = NULL;
}

void deQueue(Queue *q, qData *value) {
    qBlock *aux;

    if (q -> first == q -> last || q == NULL || q -> first -> prox == NULL) {
        cout << "Nothing in queue" << endl;
        return;
    }

    aux = q -> first -> prox;
    q -> first -> prox = aux -> prox;
    if (q -> first -> prox == NULL) {
        q -> last = q -> first;
    }

    value -> val = aux -> data.val;
    free(aux);
}

bool isQueueEmpty(Queue *q) {
    if (q -> first == q -> last || q -> first -> prox == NULL || q == NULL) {
        return true;
    }

    return false;
}

void widthPath(HuffTree **t) {
    if (*t == NULL) {
        return;
    }

    Queue aQueue;
    MEQueue(&aQueue);
    qData aux;
    aux.val = *t;
    doQueue(&aQueue, aux);
    int cont = 0;

    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);
        *t = aux.val;

        cout << (*t) -> item.word << endl;

        if ((*t) -> leftSon != NULL) {
            aux.val = (*t) -> leftSon;
            doQueue(&aQueue, aux);
        }

        if ((*t) -> rightSon != NULL) {
            aux.val = (*t) ->rightSon;
            doQueue(&aQueue, aux);
        }

        cont++;
    }
}