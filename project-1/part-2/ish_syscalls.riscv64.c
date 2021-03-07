long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    register long result asm ("a0");
    
    __asm__ __volatile__(
        "li a7, 63\n\t"
        "ecall"
        : "=r" (result)
        :: "a7"
    );

    return result;
}


int ish_chdir(const char *path)
{
    register int result asm ("a0");

    __asm__ __volatile__(
        "li a7, 49\n\t"
        "ecall"
        : "=r" (result)
        :: "a7"
    );

    return result;
}

void ish_exit(int status)
{
    __asm__ __volatile__(
        "li a7, 93\n\t"
        "ecall"
        :
        :: "a7"
    );
}

int ish_stat(const char *path, void *stat_result)
{
    register int result asm ("a0");

    __asm__ __volatile__(
        "li a7, 79\n\t"
        "move a2, a1\n\t"
        "move a1, a0\n\t"
        "li a0, -100\n\t"
        "li a3, 0\n\t"
        "ecall"
        : "=r" (result)
        :: "a7", "a3", "a2", "a1"
    );

    return result;
}

int ish_open(const char *path, int flags)
{
    register int result asm("a0");

    __asm__ __volatile__(
        "li a7, 56\n\t"
        "move a2, a1\n\t"
        "move a1, a0\n\t"
        "li a0, -100\n\t"
        "ecall"
        : "=r" (result)
        :: "a7", "a2", "a1"
    );

    return result;
}

int ish_creat(const char *path, unsigned int mode)
{   
    register int result asm("a0");

    __asm__ __volatile__(
        "li a7, 56\n\t"
        "move a3, a1\n\t"
        "move a1, a0\n\t"
        "li a0, -100\n\t"
        "li a2, 577\n\t"
        "ecall"
        : "=r" (result)
        :: "a7", "a3", "a2", "a1"
    );

    return result; 
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    register int result asm("a0");

    __asm__ __volatile__(
        "li a7, 24\n\t"
        "li a2, 0\n\t"
        "ecall"
        : "=r" (result)
        :: "a7", "a2"
    );

    return result;
}

int ish_close(int file_descriptor)
{
    register int result asm("a0");

    __asm__ __volatile__(
        "li a7, 57\n\t"
        "ecall"
        : "=r" (result)
        :: "a7"
    );

    return result;
}

int ish_fork()
{
    register int result asm("a0");

    __asm__ __volatile__(
	"li a7, 220\n\t"
       	"li a0, 0\n\t"
	"lui a0, 0x1200\n\t"
	"addi a0, a0, 17\n\t"	
        "li a1, 0\n\t"
        "li a2, 0\n\t"
        "li a3, 0\n\t"
	"addi a4, tp, -1600\n\t"
        "ecall"
        : "=r" (result)
        :: "a7", "a4", "a3", "a2", "a1"
    );

    return result;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
     register int result asm("a0");

    __asm__ __volatile__(
        "li a7, 221\n\t"
        "ecall"
        : "=r" (result)
        :: "a7"
    );

    return result;
}

int ish_waitpid(int pid, int *status, int options)
{
    register int result asm("a0");

    __asm__ __volatile__(
        "li a7, 260\n\t"
        "li a3, 0\n\t"
        "ecall"
        : "=r" (result)
        :: "a7"
    );

    return result;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
    register long result asm ("a0");

    __asm__ __volatile__(
        "li a7, 64\n\t"
        "ecall"
        : "=r" (result)
        :: "a7"
    );

    return result;
}

