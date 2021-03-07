#include <stdio.h>

long my_write(int fd, const void *buf, unsigned long count){
    long result;

    __asm__ __volatile__(
        "mov $1, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

unsigned long my_strlen(const char *s){
    const char *start = s;
    for (;*s; ++s);
    return (unsigned long) (s-start);
}

int main(int argc, char *argv[])
{	
    int i = 0;
    if(argc > 1) {
		while(i < 1)
		{	
			for(int j = 1; j < argc; j++){
			
				my_write(1, argv[j], my_strlen(argv[j])); // printf(j < argc - 1 ? "%s " : "%s\n", argv[j]);
				if (j < argc - 1) {
					my_write(1, " ", 1);
				}
				my_write(1, "\n", sizeof("\n")-1);
			}
		}
    } else {
		while(i < 1){
			my_write(1, "y\n", sizeof("y\n")-1);
		}
    }
}