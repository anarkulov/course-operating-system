#include <string.h>
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

char *my_getcwd(char *buf, unsigned long size){
	char result;
    __asm__ __volatile__(
        "mov $0x4f, %%rax\n\t"
        "syscall"
        :"=a" (buf)
        ::
    );
}

unsigned long my_strnlen(const char *s, unsigned long n){
    const char *start = s;
    while (n-- > 0 && *start){
		start++;
	}

    return (unsigned long) (start-s);
}

#define BUF_SIZE 4096
static char buffer[BUF_SIZE];

int main(int argc, char *argv[])
{
	my_getcwd(buffer, BUF_SIZE);
	my_write(1, buffer, my_strnlen(buffer, BUF_SIZE));
	my_write(1, "\n", sizeof("\n") - 1);

	return 0;	
}

