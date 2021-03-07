long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
	register long result asm ("v0");
	
	__asm__ __volatile__ (
		"li $v0, 5000\n\t"
		"syscall"
		:"=r" (result)
		::
	);

    return result;
}

int ish_chdir(const char *path)
{
    register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5078\n\t"
        "syscall"
        :"=r" (result)
        ::
    );

    return result;
}

void ish_exit(int status)
{
    __asm__ __volatile__ (
        "li $v0, 5058\n\t"
        "syscall"
        :
        ::
    );
}

int ish_stat(const char *path, void *stat_result)
{
	register int result asm ("v0");

	__asm__ __volatile__ (
        "li $v0, 5004\n\t"
        "syscall"
        :"=r" (result)
        ::
    );

    return result;
}

int ish_open(const char *path, int flags)
{
	register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5002\n\t"
        "syscall"
        :"=r" (result)
        ::
    );

    return result;
}

int ish_creat(const char *path, unsigned int mode)
{	
	register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5083\n\t"
        "syscall"
        :"=r" (result)
        ::
    );

    return result;
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5032\n\t"
        "syscall"
        :"=r" (result)
        ::
    );

    return result;
}

int ish_close(int file_descriptor)
{

	register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5003\n\t"
        "syscall"
        :"=r" (result)
        ::
    );

    return result;
}

int ish_fork()
{
	register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5056\n\t"
        "syscall"
        :"=r" (result)
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
	register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5057\n\t"
        "syscall"
        :"=r" (result)
        ::
    );

    return result;
}

int ish_waitpid(int pid, int *status, int options)
{
    register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5059\n\t"
		"li $a3, 0\n\t"
        "syscall"
        :"=r" (result)
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
	register int result asm ("v0");

    __asm__ __volatile__ (
        "li $v0, 5001\n\t"
        "syscall"
        :"=r" (result)
        ::
    );
    return result;
}
