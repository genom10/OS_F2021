#include <stdio.h>
void Swap( int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int* arr, int n){
    for (int i = 0; i < n; i++){
    	for (int i = 0; i < n; i++){//*********
    	    printf("%i ", arr[i]);
    	}
    	printf("\n");//*********/
        for (int ii = 0; ii < n-1; ii++){
            if (arr[ii] > arr[ii+1])
                Swap(arr+ii, arr+ii+1);
        }
    }
}

int main(){
	int n;
	printf("input array length:\n");
	scanf("%i", &n);
	int* arr = (int*) malloc (n* sizeof(int));
	printf("input array elements:\n");
	for (int i = 0; i < n; i++){
    	scanf("%i", arr+i);
	}
	
	bubble_sort(arr, n);
	
	printf("sorted array elements:\n");
	for (int i = 0; i < n; i++){
	    printf("%i ", arr[i]);
	}
	printf("\n");
	return 0;
}