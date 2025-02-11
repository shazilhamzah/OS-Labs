#include<stdio.h>
#include<unistd.h>

int main(){
    int x = 0;
    printf("%s\n","Original value of x: 0");
    __pid_t pid;
    pid = fork();
    if(pid==-1){
        printf("%s","Fork failed!");
        return 1;
    }

    if(pid==0){
        printf("%s","Value of x inside child process: ");
        x = 1;
        printf("%d\n",x);
        printf("Child process, PID = %d\n", getpid());
    }
    else{
        printf("%s","Value of x inside parent process: ");
        x = 2;
        printf("%d\n",x);
        printf("Parent process, PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}