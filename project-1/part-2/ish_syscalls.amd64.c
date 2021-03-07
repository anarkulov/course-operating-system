long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    long result;
	
    __asm__ __volatile__ (
		"mov $0, %%rax\n\t"
		"syscall"
		:"=a" (result)
	);

    return result;
}

int ish_chdir(const char *path)
{
    int result;

    __asm__ __volatile__ (
		"mov $80, %%rax\n\t"
		"syscall"
		:"=a" (result)
    );

    return result;
}

void ish_exit(int status)
{
     __asm__ __volatile__ (
        "mov $60, %%rax\n\t"
        "syscall"
        :::
    );
}

int ish_stat(const char *path, void *stat_result)
{
    int result;

    __asm__ __volatile__ (
        "mov $4, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );
	
	return result;
}

int ish_open(const char *path, int flags)
{
    int result;

    __asm__ __volatile__ (
        "mov $2, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int ish_creat(const char *path, unsigned int mode)
{  
	int result;

    __asm__ __volatile__ (
        "mov $85, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    int result;

    __asm__ __volatile__ (
        "mov $33, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int ish_close(int file_descriptor)
{
    int result;

    __asm__ __volatile__ (
        "mov $3, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int ish_fork()
{	
    int result;

    __asm__ __volatile__ (
        "mov $57, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );

    return result;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
    int result;

    __asm__ __volatile__ (
        "mov $59, %%rax\n\t"
        "syscall"
        :"=a" (result)
        ::
    );
	
    return result;
}

int ish_waitpid(int pid, int *status, int options)
{
    int result;

    __asm__ __volatile__ (
        "mov $61, %%rax\n\t"
	"mov $0, %%r10\n\t"
        "syscall"
        :"=a" (result)
        ::

    );	

    return result;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{

    long result;

    __asm__ __volatile__ (
        "mov $1, %%rax\n\t"
        "syscall"
        :"=a" (result)
    );

    return result;
}
