#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();
    int status;

    char *argv[3];
    argv[0] = "ls";
    argv[1] = 0;
    argv[2] = 0;


    if(pid >0){
        printf("parent: child = %d \n", pid);
        wait(&status);
        printf("child %d is done \n", pid);
    }
    else if(pid ==0){
        printf("child is existing\n");
        execve("/bin/ls", argv, NULL);
    }
    else{
        printf("fork error\n");
    }

    return 0;
}
