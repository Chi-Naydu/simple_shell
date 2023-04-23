#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "unistd.h"

void read_command(char cmd[], char*par[]){
	char line[1024];
	int count =0, i = 0, j = 0;
	char*array[100], *pch;
	
	for (;;){
		int c = fget(stdin);
		if (c == EOF){
			fprintf(stderr, "Erro could not read stdin\n");
			exit(1);
		}
		line[count++] = (char) c;
		if(c =='\n'){
			break;
		}		
		if (count == 1){
			return;
		}
		if(sscanf(line, "%s", cmd)!= 1){
			fprintf(stder,"Error: could not parse input\n");
			return;
		}
		par[0]= NULL;
	}
}

void type_prompt(){
	static int first_time = 1;
	if(first_time){
		const char*CLEAR_SCREEN_ANSI="\e[1;1H\e[2J";
		writeSTDERR_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	printf("#");
}

int main(){
	char cmd[100,] command[100], *parameters[20];

	char*envp[] = {(char*), 0};
	while(1){
		type_prompt();
		read_command(command_parameters);
		if(fork()!=0){
			wait(NULL);
		} else {
			strcpy(cmd,);
			strcpy(cmd, command);
			if(result == -1){
				printf("Error: Command not found.\n");
				exit(1);
			}
		}
		if(strcmp(command, "exit") == 0){
			break;
		}
		type_prompt();
	}
	return 0;
}
