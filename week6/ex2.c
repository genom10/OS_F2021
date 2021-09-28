#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <malloc.h>


typedef struct processArrivalData{
    int P, arrival, burst;
    bool queued;
}processArrivalData;

typedef struct processExecData{
    int P; // process number
    int AT; // arrival time
    int BT; // burst time
    int CT; // completion time
    int TAT; // Turn Around Time = (Completion Time – Arrival Time)
    int WT; // waiting time
}processExecData;

typedef struct node{
    processArrivalData data;
    struct node *next;
}node;

typedef struct pqueue{
    node *head;
}pqueue;

void pInit(pqueue *p){
    p->head = NULL;
}
void pPush(pqueue *p, processArrivalData a){
    if (p->head == NULL){
        p->head = (node*)malloc(sizeof(node));
        p->head->data = a;
        p->head->next = NULL;

    }
    else{
        if (p->head->data.burst > a.burst){
            node *new = (node *) malloc(sizeof(node));
            new->data = a;
            new->next = p->head;
            p->head = new;
        }
        else {
            node *cur = p->head;
            while (cur->next != NULL && cur->next->data.burst <= a.burst)
                cur = cur->next;
            node *new = (node *) malloc(sizeof(node));
            new->data = a;
            new->next = cur->next;
            cur->next = new;
        }
    }
}

processArrivalData pPop(pqueue *p){
    processArrivalData data = p->head->data;
    node *next = p->head->next;
    free(p->head);
    p->head = next;
    return data;
}

int getNewMinArrivalTime(int n, processArrivalData *arrivalQueue){
    int ret = INT_MAX;
    for (int i = 0; i < n; i++)
        if (!arrivalQueue[i].queued && arrivalQueue[i].arrival < ret)
            ret = arrivalQueue[i].arrival;
    return ret;
}

processArrivalData pPeek(pqueue *p){
    return p->head->data;
}

bool pIsEmpty(pqueue *p){
    return p->head == NULL;
}

int main()
{
    int n;
    printf("Type in the number of processes:");
    scanf("%i", &n);
    processArrivalData arrivalQueue[n];
    for (int i = 0; i < n; i++){
        printf("Type in the arrival and burst time for process #%i:", i);
        scanf("%i %i", &(arrivalQueue[i].arrival), &(arrivalQueue[i].burst));
        arrivalQueue[i].P = i;
        arrivalQueue[i].queued = false;
    }

    struct processExecData processes[n];
    int done = 0;
    int curTime = 0;
    pqueue *waiters;
    pInit(waiters);
    while (done != n){
        int lastArrivalTime = getNewMinArrivalTime(n, arrivalQueue);
        curTime = (curTime < lastArrivalTime && pIsEmpty(waiters) ? lastArrivalTime : curTime);

        if (lastArrivalTime <= curTime || pIsEmpty(waiters))
            for (int i = 0; i < n; i++){
                if (arrivalQueue[i].arrival == lastArrivalTime){
                    pPush(waiters, arrivalQueue[i]);
                    arrivalQueue[i].queued = true;
                }
            }

        while (!pIsEmpty(waiters) && curTime <= lastArrivalTime){
            processes[done].P = pPeek(waiters).P;
            processes[done].AT = pPeek(waiters).arrival;
            processes[done].BT = pPeek(waiters).burst;
            processes[done].CT = curTime + processes[done].BT;
            processes[done].TAT = processes[done].CT - processes[done].AT;
            processes[done].WT = processes[done].TAT - processes[done].BT;
            pPop(waiters);
            curTime += processes[done].BT;
            done++;
        }
    }

    printf("\nP#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++){
        printf("\n%i\t%i\t%i\t%i\t%i\t%i", processes[i].P+1, processes[i].AT, processes[i].BT, processes[i].CT, processes[i].TAT, processes[i].WT);
    }

    double totalTAT = 0;
    double totalWT = 0;
    for (int i = 0; i < n; i++){
        totalTAT += processes[i].TAT;
        totalWT += processes[i].WT;
    }
    printf("\n\naverage TAT: %f;\naverage WT: %f;", totalTAT/n, totalWT/n);
    return 0;
}