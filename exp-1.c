#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main ()
{
    pid_t pid;
    pid = fork ();
    if (pid < 0)
    {
        perror ("fork failed");
        exit (1);
    }
    else if (pid == 0)
    {
        printf ("This is the child process.\n");
        printf ("The process ID is %d.\n", getpid ());
        printf ("The parent process ID is %d.\n", getppid ());
    }
    else
    {
        printf ("This is the parent process.\n");
        printf ("The process ID is %d.\n", getpid ());
        printf ("The child process ID is %d.\n", pid);
    }
    return 0;
}

