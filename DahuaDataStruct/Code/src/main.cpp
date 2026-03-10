#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    printf("Hello C\n");
    while(1)
    {
        usleep(1000*10);
    }
    return 0;    
}
