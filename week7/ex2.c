#include <stdio.h>
#include <malloc.h>


int main()
{
    int n;
    printf("type in the length of an array:");
    scanf("%i", &n);
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i;
    for (int i = 0; i < n; i++)
        printf("arr[%i]=%i\n", i, arr[i]);
    free(&arr[0]);
    printf("memory wiped!");
    return 0;
}
