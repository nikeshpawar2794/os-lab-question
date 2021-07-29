#include<stdio.h>
 #include <sys/mman.h>
#include <sys/stat.h>  
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

int *count;

int main(int argc, const char *argv[])
{
    int shmd;
    shmd = shm_open("/nik", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);

    ftruncate(shmd,sizeof(int));
    count = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0);

    while(1)
    {
        printf("%d\n",*count);
        sleep(2);
    }

    return 0;
}