#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc == 3){
        int t = atoi(argv[1]);
        int n = atoi(argv[2]);
        
        if (t == 1){
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
        if (t == 2){
            for (int i = 0; i < n; i++){
                for (int j = 0; j <= i; j++){
                    printf("*");
                }
                printf("\n");
            }
        }
        if (t == 3){
            for (int i = 0; i < n; i++){
                for (int j = 0; j <= i; j++){
                    printf("*");
                }
                printf("\n");
            }
            for (int i = 1; i < n; i++){
                for (int j = 0; j < n-i; j++){
                    printf("*");
                }
                printf("\n");
            }
        }
        if (t == 4){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    printf("*");
                }
                printf("\n");
            }
        }
    }
    else
    {
        printf("Wrong number of arguments (%i). Type exactly 2 arguments to build a shape.\nfirst argument for shape type, second for its size\n", argc-1);
        printf("\t1 - vertical pyramid\n");
        printf("\t2 - triangle from bottom-left corner\n");
        printf("\t3 - horisontal pyramid\n");
        printf("\t4 - square\n");
    }
	return 0;
}