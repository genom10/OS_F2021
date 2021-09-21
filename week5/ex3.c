#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define N 10

char buffer[N];
int count = 0;
int working = 0;

void *consumer(void *arg){
    printf("consumer is alive!\n");
    while (1){
        if (count >= 0 && !working){
            working = 1;
            buffer[count] = 'c';
            count = count - 1;
            for (int i = 0; i < N; i++)
                printf("%c ", buffer[i]);
            printf("consumed\n");
            working = 0;
        }
        else{
            //printf("consumer halted!\n");
        }
    }
}

void *producer(void *arg){
    printf("producer is alive!\n");
    while (1){
        if (count < N && !working){
            working = 1;
            buffer[count] = 'p';
            count = count + 1;
            for (int i = 0; i < N; i++)
                printf("%c ", buffer[i]);
            printf("produced\n");
            working = 0;
        }
        else{
            //printf("producer halted!\n");
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
        buffer[i]='c';
    pthread_t pro, con;
    pthread_create(&con, NULL, consumer, NULL);
    printf("consumer created!\n");
    pthread_create(&pro, NULL, producer, NULL);
    printf("producer created!\n");
    pthread_join(con, NULL);
    return 0;
}
