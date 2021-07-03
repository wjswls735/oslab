#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>

void cat(int fd)
{
    int n;
    char buf;

    while((n=read(fd, &buf, sizeof(buf))) >0){
        if(write(1, &buf, n) != n){
            printf("cat : write error\n");
            return;
        }
    }
    if(n<0){
        printf("cat : read error\n");
        return;
    }
}

int main(int argc, char *argv[])
{
    int fd, i;
    if(argc <= 1){
        cat(0);
        return 0;
    }
    for(i=1; i<argc; i++){
        if((fd =open(argv[i], 0)) <0){
            printf( "cat: cannot open %s\n", argv[i]);
            return 0;
        }
        cat(fd);
        close(fd);
    }
    return 0;
}

