#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#define MAX 10

/*
*   	si and so are equal to 0 for the entire execution of the program
*   	with time only the amount of free memory has changed. And it decreased
*   	but as soon as program was terminated the free memory gor back to the value
*   	close to the one at the start of the programm
*
*	when using 'top' command it appeared that the process was slepping most of the time.
*	sometimes it showd as 'running', however each second memory usage was rising.
*/

int main () {
    int *a[MAX];
    for (int i = 0; i < MAX; i ++) {
        a[i] = malloc(10 * 1024 * 1024);
        memset(a[i], 0, 10 * 1024 * 1024);
        sleep(1);
    }
    return 0;
}
