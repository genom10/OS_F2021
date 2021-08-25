#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc == 2){
        int n = atoi(argv[1]);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n-i; j++){
                printf(" ");
            }
            for (int j = 0; j < i*2+1; j++){
                printf("*");
            }
            for (int j = 0; j < n-i; j++){
                printf(" ");
            }
                printf("\n");
        }
    }
    else
    {
        printf("Wrong number of arguments (%i). Type exactly 1 argument to build a pyramid", argc-1);
    }
	return 0;
}