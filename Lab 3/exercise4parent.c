#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("%s\n", "Invalid arguments!");
        return 0;
    }

    __pid_t pid = fork();
    if (pid < 0)
    {
        printf("%s\n", "Fork failed!");
        return 0;
    }
    else if (pid == 0)
    {
        execlp(argv[1], argv[1], (char *)NULL);
        printf("%s\n", "Execlp failed!");
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("%s\n", "Child finished!");
    }
}