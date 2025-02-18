#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 100

int main()
{
    int fd1[2]; // FOR PARENT TO CHILD
    int fd2[2]; // FOR CHILD TO PARENT

    pipe(fd1);
    pipe(fd2);

    pid_t Child = fork();

    // Parent PROCESS
    if (!Child)
    {
        // READ
        // printf("Child process, PID = %d\n", getpid());
        // printf("%s\n", "Child IS READING");
        close(fd1[1]);
        close(fd2[0]);
        char bufferReadChild[100];
        read(fd1[0], bufferReadChild, 100);
        printf("Child received: %s\n", bufferReadChild);

        // WRITE
        // printf("%s\n", "Child IS WRITING");
        close(fd2[0]);
        char msg[] = "Hello father, I am goooood!!";
        write(fd2[1], msg, strlen(msg) + 1);

        exit(0);
    }

    // Parent PROCESS
    else
    {
        // WRITE
        // printf("Parent process, PID = %d\n", getpid());
        close(fd2[1]);
        close(fd1[0]);
        char msg[] = "Hello son, how are ya??";
        write(fd1[1], msg, strlen(msg) + 1);
        // printf("%s\n", "Parent IS WRITING");

        // READ
        // printf("%s\n", "Parent IS READING");
        close(fd2[1]);
        char bufferReadParent[100];
        read(fd2[0], bufferReadParent, 100);
        printf("Parent received: %s\n", bufferReadParent);
    }


    return 0;
}