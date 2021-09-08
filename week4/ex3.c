#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void read_command(char *command);

int main(){
	char command[20];
	while(strcmp(command, "exit") != 0){
		printf("> ");
		read_command(command);
		system(command);
	}
	return 0;
}

void read_command(char *command){
	scanf(" %[^\n]",command);
	printf("%s", command);
}
