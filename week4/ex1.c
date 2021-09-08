#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	int pid = fork();
	// a fork (child) is created with PID = 0;
	// the parrent keeps it's original PID;
	// other vatiables such as n are copied from parent to child
	if (pid>0){
		printf("hello from parrent[%i - %i]\n", pid, n);
	}
	else{
		if (pid==0){
			printf("hello from child[%i - %i]\n", pid, n);
		}
		else{
			return -1;
		}
	}
}
