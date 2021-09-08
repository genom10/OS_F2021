#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	int pid;
	// for each itteration of the loop n childs will be created,
	// then for all childrens loop continues with i copied from the moment of creation of the child.
	// due to that 1st 1st-gen child will create n-1 children, while 2nd 1-st gen child will create n-2 children.
	for (int i = 0; i < n; i++){
		pid = fork();
	}
	sleep(5);
}

