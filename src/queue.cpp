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
    qData aux, son;
    aux.val = *t;
    doQueue(&aQueue, aux);
    int cont = 0;

    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);

        cout << aux.val -> item.word << "\t\t\t\t";
        cout << "item " << cont << ": ";
        for (long unsigned int i = 0; i < aux.val -> item.binaryCodification.size(); i++) {
            cout << aux.val -> item.binaryCodification[i] << " ";
        }

        cout << endl;

        if (aux.val -> leftSon != NULL) {
            son.val = aux.val -> leftSon;
            doQueue(&aQueue, son);
        }

        if (aux.val -> rightSon != NULL) {
            son.val = aux.val -> rightSon;
            doQueue(&aQueue, son);
        }

        cont++;
    }
}

void generateCode(HuffTree **t) {
    Queue aQueue;
    MEQueue(&aQueue);
    qData aux, son;
    aux.val = *t;
    doQueue(&aQueue, aux);
    bool booleanAux;

    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);

        if (aux.val -> leftSon != NULL) {
            aux.val -> leftSon -> item.binaryCodification = aux.val -> leftSon -> dad-> item.binaryCodification;
            booleanAux = 0;
            aux.val -> leftSon -> item.binaryCodification.push_back(booleanAux);

            son.val = aux.val -> leftSon;
            doQueue(&aQueue, son);
        }

        if (aux.val -> rightSon != NULL) {
            aux.val -> rightSon -> item.binaryCodification = aux.val -> rightSon -> dad -> item.binaryCodification;
            booleanAux = 1;
            aux.val -> rightSon -> item.binaryCodification.push_back(booleanAux);

            son.val = aux.val -> rightSon;
            doQueue(&aQueue, son);
        }
    }
}

void findWordCode(HuffTree **t, string wordToSearch, vector <bool> &vectorToSave) {
    Queue aQueue;
    MEQueue(&aQueue);
    qData aux, son;
    aux.val = *t;
    doQueue(&aQueue, aux);
    
    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);
        
        // cout << aux.val->item.word << endl;
        if (aux.val -> item.word == wordToSearch) {
            vectorToSave = aux.val ->item.binaryCodification;
        }

        if (aux.val -> leftSon != NULL) {
            son.val = aux.val -> leftSon;
            doQueue(&aQueue, son);
        }

        if (aux.val -> rightSon != NULL) {
            son.val = aux.val -> rightSon;
            doQueue(&aQueue, son);
        }

    }
}

void translateToBinary(vector <bool> &mainVector, vector <string> &text, HuffTree **t) {
    string aux;
    vector <bool> auxVec;

    while (!text.empty()) {
        findWordCode(t, text[0], auxVec);
        // cout << "word: " << text[0] << "\tcode: "; 
        for (long unsigned int i = 0; i < auxVec.size(); i++) {
            // cout << auxVec[i];
            // mainVector[mainVector.end()] = auxVec[i];
            mainVector.push_back(auxVec[i]);
        }

        text.erase(text.begin());
        auxVec.clear();
    }   
}