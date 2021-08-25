#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	printf("Input values to swap:\n");
	int a, b;
	printf("a:");
	scanf("%i", &a);
	printf("\nb:");
	scanf("%i", &b);
	printf("\nbefore swap a:%i, b:%i", a, b);
	swap(&a, &b);
	printf("\nafter swap a:%i, b:%i", a, b);
	return 0;
}