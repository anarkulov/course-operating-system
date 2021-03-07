#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{	
	for (int i = 1; i < argc; i++){
		write(STDOUT_FILENO, argv[i], strlen(argv[i]));
		if (i < argc - 1) {
			 write(STDOUT_FILENO, " ", 1);
		}
	}

	write(STDOUT_FILENO, "\n", sizeof("\n")-1);

	return 0;
}

/*
int main(int argc, char *argv[])
{	
	for (int i = 1; i < argc; i++)
	{
		printf(i < argc - 1 ? "%s " : "%s", argv[i]);
	}
	puts("")l

	return 0;
}
*/
