int my_rename(const char *oldpath, const char *newpath)
{
    int result;

    __asm__ __volatile__ (
        "mov $0x52, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}
int main(int argc, char *argv[]){
    
    my_rename(argv[1], argv[2]);

    return 0;
}