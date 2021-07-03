#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();
    int status;

    if(pid>0){
        printf("parent: child = %d \n", pid);
        wait(&status);
        printf("child %d is done\n", pid);
    }
    else if(pid==0){
        printf("child is existing\n");
    }
    else{
        printf("fork error \n");
    }
    return 0;
}
