#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h> 
#include <sys/types.h>

#define BUF_SIZE 2048
char buffer[BUF_SIZE];
char *arguments[BUF_SIZE];

int main(int argc, char **argv, char **envp){
    long bytes_read;
    while ((bytes_read = read(0, buffer, BUF_SIZE)) > 0) {
        
        for (int i = 0; i < argc; i++){
            arguments[i] = argv[i];
        }
        
        char *executable = arguments[0];
    	int pid = fork();
    	if (pid == 0) {
            execve(executable, arguments, envp);
    	} else if (pid > 0) {
            int child_status;
            waitpid(pid, &child_status, 0);
        }
    }
    return 0;
}
