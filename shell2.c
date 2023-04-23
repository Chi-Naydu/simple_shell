#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "unistd.h"

void read_command(char cmd[], char *par[]) {
    char line[1024];
    int count = 0, i = 0, j = 0;
    char *array[100], *pch;

    for (;;) {
        int c = fgetc(stdin);
        if (c == EOF) {
            fprintf(stderr, "Error: Could not read from stdin\n");
            exit(1);
        }
        line[count++] = (char) c;
        if (c == '\n') {
            break;
        }
        if (count == 1) {
            return;
        }
        if (sscanf(line, "%s", cmd) != 1) {
            fprintf(stderr, "Error: Could not parse input\n");
            return;
        }
        pch = strtok(line, " \n");
        while (pch != NULL) {
            array[i++] = strdup(pch);
            pch = strtok(NULL, " \n");
        }
        for (j = 0; j < i; j++) {
            par[j] = array[j];
        }
        par[i] = NULL;

    }
}

void type_prompt() {
    static int first_time = 1;
    if (first_time) {
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
        write(STDERR_FILENO, CLEAR_SCREEN_ANSI, 12);
        first_time = 0;
    }

    printf("#");
}

int main() {
    char cmd[100], command[100], *parameters[20];

    char *envp[] = { (char *) "PATH=C:\\Windows\\System32", 0 };
    while(1) {
        type_prompt();
        read_command(command, parameters);
        if (fork() != 0) {
            wait(NULL);
        } else {
            strcpy(cmd, "C:\\Windows\\System32");
            strcpy(cmd, command);
            int result = execvp(cmd, parameters);
            if (result == -1) {
                printf("Error: Command not found.\n");
                exit(1);
            }
        }
        if (strcmp(command, "exit") == 0) {
            break;
        }
        type_prompt();
    }
    return 0;
}

