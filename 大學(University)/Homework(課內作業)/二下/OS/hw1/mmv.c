#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fbase = open(argv[1], O_RDONLY);
    int fnew = open(argv[2], O_RDWR | O_CREAT, S_IRWXU);

    char add[] = "\\\\----Say Hello to s1083339!----\\\\\n";
    write(fnew, add, strlen(add));

    char s[500];
    while (read(fbase, s, 500))
    {
        write(fnew, s, strlen(s));
        memset(s,0,500);
    }
    return 0;
}