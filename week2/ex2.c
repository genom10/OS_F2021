#include <stdio.h>
#include <string.h>

int main(){
	printf("Input string to reverse:\n");
	char str[100];
	scanf("%s", str);
	printf("Reversed string:\n");
	for (int i = strlen(str)-1; i >= 0; i--)
		printf("%c",str[i]);
	return 0;
}