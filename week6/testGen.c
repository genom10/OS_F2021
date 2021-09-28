#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int processNumber = 3000;
float density = 1;
int maxBurst = 20;

int main(){
    FILE *fp;
    char filename[20];
    sprintf(filename, "n%id%.2fb%i.txt", processNumber, density, maxBurst);
    printf("%s", filename);
    fp = fopen(filename, "w+");
    srand(time(NULL));   // Initialization, should only be called once.
    fprintf(filename, "%i\n", processNumber);
    for (int i = 0; i < processNumber; i++){
        fprintf(fp,"%i %i\n", rand()%(int)(processNumber/density*maxBurst), rand()%(maxBurst)+1);
    }
    return 0;
}
