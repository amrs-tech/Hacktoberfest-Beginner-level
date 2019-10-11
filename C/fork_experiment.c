#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(void) {

	int i = 0;
	int rc;
	int *fd = malloc(sizeof(int) * 4); // 4 = 2*n - 2 (n = 3 in this case)
	int *free_fd = fd;

	char *args[3];

	do {
		switch(i) {	// test cases
			case 0:
				args[0] = "ls";
				args[1] = "-l";
				args[2] = NULL;
				break;
			case 1:
				args[0] = "head";
				args[1] = "-n 3";
				args[2] = NULL;
				break;
			case 2:
				args[0] = "wc";
				args[1] = "-l";
				args[2] = NULL;
				break;
			default:
				fprintf(stderr, "switch failed.\n");
				exit(1);
		}

		if(pipe(fd) < 0) {
			fprintf(stderr, "pipe failed.\n");
			exit(1);
		}
		if((rc = fork()) < 0) {
			fprintf(stderr, "fork failed.\n");
			exit(1);
		} else if (rc == 0) {
			if ( i == 2 ) {		// last command? ==> print the output in stdout
				close(fd[0]);
				close(fd[1]);
				execvp(args[0], args);
			} else {
				close(fd[0]);
				dup2(fd[1],STDOUT_FILENO); // dup2(x,y) : input ==> y ==> x ==> pipe_write
				close(fd[1]);
				execvp(args[0], args);
			}
		} else {
			if ( i == 2 ) {		// last command? ==> close unnecesary file descriptors
				close(fd[0]);
				close(fd[1]);
			} else {
				close(fd[1]);
				dup2(fd[0],STDIN_FILENO);
				close(fd[0]);
			}
		}
		++i;	// i used to provide the test cases, in more general cases it is unnecesary
		if(i != 2) {	// if i = 2 then fd will address unallocated memory: fd[0] = free_fd[5]
			fd += 2;	// using pointer arithmetic
		}
	} while (i < 3 && rc != 0);

	if (rc != 0) {
		wait(NULL);
		free(free_fd);
		fd = NULL;
	} else {
		exit(1);
	}

	return 0;
}
