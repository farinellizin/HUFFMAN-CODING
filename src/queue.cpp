#include "queue.hpp"

void MEQueue(Queue *q) {
    q -> first = 1;
    q -> last = 1;
}

void queue(Queue *q, queueData tree) {
    if (q -> last % MAXTAM + 1 == q -> first) {
        cout << "Queue is full!";
    } else {
        q -> arr[q->last - 1] = tree;
        q -> last = q -> last % MAXTAM + 1;
    }
}

void deQueue(Queue *q, queueData *tree) {
    if (q -> first == q -> last) {
        cout << "Queue is empty!";
    } else {
        *tree = q -> arr[q -> first - 1];
        q -> first = q -> first % MAXTAM + 1;
    }
}

void QRemove(Queue *q, queueData tree) {
    Queue aux;
    queueData rem;

    MEQueue(&aux);

    if (q -> first == q -> last) {
        cout << "Queue is empty!";
    } else {
        while (q -> first != q -> last) {
            deQueue(q, &rem);
            if (rem.value != tree.value) {
                queue(&aux, rem);
            }
        }

        *q = aux;
    }
}

void QPrint(Queue *q) {
    int aux = q -> first;

    while (aux != q -> last) {
        cout << q->arr[aux - 1].value << endl;
        aux = aux % MAXTAM + 1;
    }

    cout << endl << endl;
}