#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    pid_t fpid = fork();
    if(fpid == 0)
    {
        if(argc == 3)
            execl("./mmv.out", "./mmv.out", argv[1], argv[2], NULL);
        else
            execl("./mmv.out", "./mmv.out", "blake.txt", "happy.tmp", NULL);
    }
    wait(NULL);
    return 0;
}