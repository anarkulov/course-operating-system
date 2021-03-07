int my_unlinkat(int dirfd, const char *pathname, int flags)
{
    int result;

    __asm__ __volatile__ (
        "mov $0x107, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; ++i){
        my_unlinkat(-100, argv[i], 0);
    }
   return 0;
} 