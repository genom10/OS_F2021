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
typedef struct queue{
    node *head;
}queue;
void qInit(queue *p){
    p->head = NULL;
}
void qPush(queue *p, processArrivalData a){
    if (p->head == NULL){
        p->head = (node*)malloc(sizeof(node));
        p->head->data = a;
        p->head->next = NULL;

    }
    else{
        node *cur = p->head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = (node *) malloc(sizeof(node));
        cur->next->data = a;
        cur->next->next = NULL;
    }
}
processArrivalData qPop(queue *p){
    processArrivalData data = p->head->data;
    node *next = p->head->next;
    free(p->head);
    p->head = next;
    return data;
}
processArrivalData qPeek(queue *p){
    return p->head->data;
}
bool qIsEmpty(queue *p){
    return p->head == NULL;
}

int getNewMinArrivalTime(int n, processArrivalData *arrivalQueue){
    int ret = INT_MAX;
    for (int i = 0; i < n; i++)
        if (!arrivalQueue[i].queued && arrivalQueue[i].arrival < ret)
            ret = arrivalQueue[i].arrival;
    return ret;
}

int main()
{
    int quantum, n;
    printf("Type in the quantum length:");
    scanf("%i", &quantum);
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
    queue *waiters;
    qInit(waiters);

    while (done != n){
        int lastArrivalTime = getNewMinArrivalTime(n, arrivalQueue);
        curTime = (curTime < lastArrivalTime && qIsEmpty(waiters) ? lastArrivalTime : curTime);

        if (lastArrivalTime <= curTime || qIsEmpty(waiters))
            for (int i = 0; i < n; i++){
                if (arrivalQueue[i].arrival == lastArrivalTime){
                    qPush(waiters, arrivalQueue[i]);
                    arrivalQueue[i].queued = true;
                }
            }

        while (!qIsEmpty(waiters) && curTime <= lastArrivalTime){
            if (qPeek(waiters).burst <= quantum){
                processes[done].P = qPeek(waiters).P;
                processes[done].AT = qPeek(waiters).arrival;
                processes[done].BT = arrivalQueue[processes[done].P].burst;
                processes[done].CT = curTime + qPeek(waiters).burst;
                processes[done].TAT = processes[done].CT - processes[done].AT;
                processes[done].WT = processes[done].TAT - qPeek(waiters).burst;
                qPop(waiters);
                curTime += processes[done].BT;
                done++;
            } else{
                curTime += quantum;
                processArrivalData partialExec = qPop(waiters);
                partialExec.burst-=quantum;
                qPush(waiters, partialExec);
            }
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