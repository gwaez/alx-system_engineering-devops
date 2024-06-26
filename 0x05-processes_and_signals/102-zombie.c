#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

int main(void)
{
    pid_t child_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid == 0)
            exit(0); // Child exits immediately, becoming a zombie
        else if (child_pid > 0)
            printf("Zombie process created, PID: %d\n", child_pid);
        else
        {
            perror("fork");
            return (1);
        }
    }

    infinite_while(); // Run indefinitely to keep zombies
    return (0);
}

