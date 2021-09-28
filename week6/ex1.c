#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>


typedef struct processArrivalData{
    int arrival, burst;
    bool done;
}processArrivalData;

typedef struct processExecData{
    int P; // process number
    int AT; // arrival time
    int BT; // burst time
    int CT; // completion time
    int TAT; // Turn Around Time = (Completion Time – Arrival Time)
    int WT; // waiting time
}processExecData;

int getNewMinArrivalTime(int n, processArrivalData *arrivalQueue){
    int ret = INT_MAX;
    for (int i = 0; i < n; i++)
        if (!arrivalQueue[i].done && arrivalQueue[i].arrival < ret)
            ret = arrivalQueue[i].arrival;
    return ret;
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
        arrivalQueue[i].done = false;
    }

    struct processExecData processes[n];
    int done = 0;
    int curTime = 0;
    while (done != n){
        int lastArrivalTime = getNewMinArrivalTime(n, arrivalQueue);
        curTime = (curTime > lastArrivalTime ? curTime : lastArrivalTime);
        for (int i = 0; i < n; i++){
            if (arrivalQueue[i].arrival == lastArrivalTime){
                processes[done].P = i+1;
                processes[done].AT = arrivalQueue[i].arrival;
                processes[done].BT = arrivalQueue[i].burst;
                processes[done].CT = curTime + processes[done].BT;
                processes[done].TAT = processes[done].CT - processes[done].AT;
                processes[done].WT = processes[done].TAT - processes[done].BT;
                curTime += processes[done].BT;
                arrivalQueue[i].done = true;
                done++;
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