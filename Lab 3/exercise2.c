#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{   
    for (int i = 0; i < 5; i++)
       {
        __pid_t cpid;
        if (fork() == 0)
        {
            printf("%s", "I am fork ");
            printf("%d\n", i+1);
            exit(0);
        }
        else{
            cpid = waitpid(0);
            printf("%s", "Exit status for child ");
            printf("%d", i+1);
            printf("%s", ": ");
            printf("%d\n",cpid);
        }
    }

    return 0;
}