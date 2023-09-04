/*Zombie process -> defuct process is a process that has completed execution but still has the entry in the process table */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid != 0) {
        // This is the parent process
        printf("Parent process (PID: %d) is running.\n", getpid());
        sleep(1);  // Sleep briefly to allow child process to exit
    } else {
        // This is the child process
        printf("Child process (PID: %d) is running and exiting.\n", getpid());
        exit(0);
    }

    return 0;
}
