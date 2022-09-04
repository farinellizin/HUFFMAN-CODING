#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "HuffTree.hpp"
using namespace std;
typedef struct queueData queueData;
typedef struct Queue Queue;
#define MAXTAM 300

struct queueData {
    HuffTree *value;
};

struct Queue {
    queueData arr[MAXTAM];
    int first;
    int last;
};

void MEQueue(Queue *q);
void queue(Queue *q, queueData tree);
void deQueue(Queue *q, queueData *tree);
void QRemove(Queue *q, queueData tree);
void QPrint(Queue *q);

#endif