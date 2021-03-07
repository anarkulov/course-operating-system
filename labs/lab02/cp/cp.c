
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUF_SIZE 131072
static char buffer[BUF_SIZE];

int main(int argc, char *argv[]){

    int fd = openat(AT_FDCWD, argv[1], O_RDONLY);
    int fd2 = openat(AT_FDCWD, argv[2], O_WRONLY|O_CREAT|O_EXCL, 0664);

    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUF_SIZE) != 0)){
        write(fd2, buffer, bytes_read);        
    }
    close(fd);
    close(fd2);
    return 0;
}