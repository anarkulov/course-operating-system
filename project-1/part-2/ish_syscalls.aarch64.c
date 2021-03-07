long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    register long result asm ("x0");

    __asm__ __volatile__(
        "mov x8, #63\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8"
    );

    return result;
}

int ish_chdir(const char *path)
{
    register int result asm ("w0");

    __asm__ __volatile__(
        "mov x8, #49\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8"
    );

    return result;
}

void ish_exit(int status)
{
    __asm__ __volatile__(
        "mov x8, #93\n\t"
        "svc #0"
        :
        :: "x8"
    );
}

int ish_stat(const char *path, void *stat_result)
{
    register int result asm ("w0");

    __asm__ __volatile__(
        "mov x8, #79\n\t"
        "mov x2, x1\n\t"
        "mov x1, x0\n\t"
        "mov x0, #-100\n\t"
        "mov x3, #0\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8", "x3", "x2", "x1"
    );

    return result;
}

int ish_open(const char *path, int flags)
{
    register int result asm("w0");

    __asm__ __volatile__(
        "mov x8, #56\n\t"
        "mov x2, x1\n\t"
        "mov x1, x0\n\t"
        "mov x0, #-100\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8", "x2", "x1"
    );

    return result;
}

int ish_creat(const char *path, unsigned int mode)
{   
    register int result asm("w0");

    __asm__ __volatile__(
        "mov x8, #56\n\t"
        "mov x3, x1\n\t"
        "mov x1, x0\n\t"
        "mov x0, #-100\n\t"
        "mov x2, #577\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8", "x3", "x2", "x1"
    );

    return result; 
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    register int result asm("w0");

    __asm__ __volatile__(
        "mov x8, #23\n\t"
        "mov x2, #0\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8", "x2"
    );

    return result;
}

int ish_close(int file_descriptor)
{
    register int result asm("w0");

    __asm__ __volatile__(
        "mov x8, #57\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8"
    );

    return result;
}

int ish_fork()
{   
    register int result asm("w0");

    __asm__ __volatile__(
        "mov x1, #0\n\t"
        "mov x2, #0\n\t"
        "mov x3, #0\n\t"
        "mrs x21, tpidr_el0\n\t"
        "sub x5, x21, #0x700\n\t"
        "add x4, x5, #0xd0\n\t"
        "mov x8, #220\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8", "x4", "x3", "x2", "x1"
    );

    return result;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
     register int result asm("w0");

    __asm__ __volatile__(
        "mov x8, #221\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8"
    );

    return result;
}

int ish_waitpid(int pid, int *status, int options)
{
    register int result asm("w0");

    __asm__ __volatile__(
        "mov x8, #260\n\t"
        "mov x3, #0\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8"
    );

    return result;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
    register long result asm ("x0");

    __asm__ __volatile__(
        "mov x8, #64\n\t"
        "svc #0"
        : "=r" (result)
        :: "x8"
    );

    return result;
}
