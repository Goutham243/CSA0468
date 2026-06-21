#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if(fd < 0)
    {
        printf("File creation failed\n");
        return 1;
    }

    write(fd, "Operating Systems Lab", 21);

    printf("File created and written successfully\n");

    close(fd);

    return 0;
}
