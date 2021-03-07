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

int my_mkdir(const char *pathname)
{
    int result;

    __asm__ __volatile__ (
        "mov $0x53, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int main(int argc, char *argv[]){
    
    int fd = my_mkdir(argv[1]);

    my_close(fd);

    return 0;
}