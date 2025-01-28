#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char s[100];
    for (int i = 1; i < argc; i++)
    {
        strcat(s, argv[i]);
    }
    printf(s, "%d\n");
    return 0;
}