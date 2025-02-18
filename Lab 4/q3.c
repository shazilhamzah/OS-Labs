#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define FIFO_PATH "myfifo"
#define num 5 // Adjust as needed

int main()
{
    // Create the named pipe (FIFO)
    mkfifo(FIFO_PATH, 0666);

    pid_t pid;

    for (int i = 0; i < num; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            int fd = open(FIFO_PATH, O_WRONLY);

            char message[100];
            sprintf(message, "Child %d: Hello from process %d!", i, getpid());

            write(fd, message, strlen(message) + 1);
            printf("Child %d sent message: %s\n", i, message);

            close(fd);
            exit(0);
        }
        else
        {
            int fd = open(FIFO_PATH, O_RDONLY);
            char buffer[100];

            read(fd, buffer, sizeof(buffer));
            printf("Parent received: %s\n", buffer);

            close(fd);
        }
    }

    return 0;
}