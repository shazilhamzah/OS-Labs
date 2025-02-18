#include<stdio.h>
#include<unistd.h>


int main(){
    pid_t pid1;
    pid_t pid2;

    pid1=fork();
    if(!pid1){
        printf("Child process 1, PID = %d\n", getpid());
        int x = execlp("ps","ps",NULL);
        printf("%d\n",x);
        exit(0);
    }

    waitpid(pid1);

    pid2 = fork();
    if(!pid2){
        printf("Child process 2, PID = %d\n", getpid());
        int x = execlp("whoami","whoami",NULL);
        printf("%d\n",x);
        exit(0);
    }

    waitpid(pid2);

    return 0;
}