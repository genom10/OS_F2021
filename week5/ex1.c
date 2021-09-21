#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void *myThread(void *arg){
    printf("Hello world! From thread #%d.\n", ((int)(intptr_t) arg));
    pthread_exit(NULL);
}

int main(){
    int n;
    printf("type the number of threads to create:");
    scanf("%i", &n);
    for (int i = 1; i <= n; i++){
        pthread_t curThread = (pthread_t)NULL;
        if(pthread_create(&curThread, NULL, myThread, (void*)(intptr_t)i))
        {
            printf("failed to create a thread");
        }
        else {
            printf(">> Thread #%i created.\n", i);
            if (pthread_join(curThread, NULL) != 0) {
                perror("failed to join thread to thread generator");
                exit(3);
            }
            printf(">> Thread #%i has finished its job.\n", i);
        }
    }
}