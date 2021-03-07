long my_write(int fd, const void *buf, unsigned long count){
    long result;

    __asm__ __volatile__(
        "mov $0x1, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

long my_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    long result;
	
    __asm__ __volatile__ (
		"mov $0x0, %%rax\n\t"
		"syscall"
		:"=a" (result)
	);

    return result;
}

int my_openat(int dirfd, const char *pathname, int flags)
{
    int result;

    __asm__ __volatile__ (
        "mov $0x101, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int my_close(int fd)
{
    int result;

    __asm__ __volatile__ (
        "mov $0x3, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

#define BUF_SIZE 13072
static char buffer[BUF_SIZE];

int main (int argc, char *argv[])
{
    if (argc > 1) {
	for(int i = 1; i < argc; i++){
	    int fd = my_openat(-100, argv[i], 00);

	    long bytes_read;
	    while((bytes_read = my_read(fd, buffer, BUF_SIZE)) > 0){
	    	my_write(1, buffer, bytes_read);
	    }

	    my_close(fd);
	}
    } else {
		long bytes_read;
        while((bytes_read = my_read(1, buffer, BUF_SIZE)) > 0){
            my_write(1, buffer, bytes_read);
        }
    }

	return 0;
}
