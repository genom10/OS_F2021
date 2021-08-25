#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("int max value: %i\n", a);
	printf("float max value: %f\n", b);
	printf("double max value: %f\n", c);
	printf("int size: %i\n", sizeof(a));
	printf("float size: %i\n", sizeof(b));
	printf("double size: %i\n", sizeof(c));
	return 0;
}
