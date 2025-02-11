#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    __pid_t cpid = fork();

    if (cpid == 0)
    {
        int x = 0;
        FILE *fptr = fopen(argv[1], "r");
        if (fptr == NULL)
        {
            return 1;
        }

        // Read and print each line from the file
        char buff[100];
        while (fgets(buff, sizeof(buff), fptr) != NULL)
        {
            printf("%s", buff);
        }
        for (int i = 0; i < 100; i++)
        {
            if (buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u')
            {
                x++;
            }
        }
        
        printf("%d\n", x);

        fclose(fptr);
    }
    else
    {
        cpid = wait(NULL);
    }

    return 0;
}
