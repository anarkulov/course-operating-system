#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h> 
#include <sys/types.h>
#include <stdio.h>

unsigned long build_argument_array_from_input();

char* carve_token_in_cstring();


static const unsigned long Max_Input_String_Length = 255;
static const unsigned long Max_Argument_Count = 255;

int main(int argc, char **argv, char **envp)
{
    char buffer[Max_Input_String_Length + 1];
    buffer[Max_Input_String_Length] = '\0';

    while (read(0, buffer, Max_Input_String_Length) >= 0) {
        char *arguments[Max_Argument_Count + 1];
        arguments[Max_Argument_Count] = 0;

        unsigned long argument_count =
            		build_argument_array_from_input(
                		buffer,
                		arguments,
                		Max_Argument_Count
           	 	    );
        
        printf("%s\n", arguments[0]);
    	char *executable = arguments[0];
        
    	int pid = fork();
    	if (pid == 0) {
            execve(executable, arguments, envp);
    	}else if (pid > 0) {
            int child_status;
            waitpid(pid, &child_status, 0);
        }
    }
    return 0;
}

int is_space(int character)
{
    int result =
        character == ' ' ||
            (unsigned int) character - '\t' < 5;

    return result;
}

unsigned long build_argument_array_from_input(
                  char *input,
                  char **arguments,
                  unsigned long max_argument_count
              )
{
    unsigned long argument_index = 0;

    for (char *cursor = input; cursor && argument_index < max_argument_count; ++argument_index) {
        arguments[argument_index] =
            carve_token_in_cstring(
                cursor,
                is_space,
                &cursor
            );
    }

    arguments[argument_index] = 0;

    unsigned long argument_count =
        argument_index == 0 ?
            0 : argument_index - 1;

    return argument_count;
}

char* carve_token_in_cstring(
          char *string,
          int (*is_separator)(int character),
          char **cursor_after_token
      )
{
    char *result = 0;

    while (*string && is_separator(*string)) {
        ++string;
    }

    if (*string) {
        result = string;
    }

    while (*string && !is_separator(*string)) {
        ++string;
    }

    if (cursor_after_token) {
        *cursor_after_token = 0;
    }

    if (*string) {
        *(string++) = '\0';

        if (*string && cursor_after_token) {
            *cursor_after_token =
                string;
        }
    }

    return result;
}