nclude <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Creates 5 zombie processes
 *
 * Return: Always 0
 */
int main(void)
{
    int i;
    pid_t pidme;

    for (i = 0; i < 5; i++)
    {
        pidme = fork();
        if (pidme > 0)
        {
            printf("Zombie process created, PID: %d\n", pidme);
            sleep(1); // Give time for the child to exit and become a zombie
        }
        else if (pidme == 0)
        {
            exit(0);
        }
        else
        {
            perror("fork");
            exit(1);
        }
    }

    // Parent process waits for child processes to avoid leaving zombies
    for (i = 0; i < 5; i++)
    {
        wait(NULL);
    }

    return 0;
}
}
