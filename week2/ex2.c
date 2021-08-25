#include <stdio.h>
#include <string.h>

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	printf("Input values to swap:\n");
	int a, b;
	printf("a:");
	scanf("%i", &a);
	printf("b:");
	scanf("%i", &b);
	printf("before swap a:%i, b:%i", a, b);
	swap(a, b);
	printf("after swap a:%i, b:%i", a, b);
	return 0;
}