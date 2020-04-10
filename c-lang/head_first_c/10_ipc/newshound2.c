#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void error(const char *msg)
 {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char **argv)
 {

    char *phrase = argv[1];

    char *vars[] = {
	"RSS_FEED=http://rss.nytimes.com/services/xml/rss/nyt/US.xml",
	NULL};

    FILE *file = fopen("stories.txt", "w");
    if (!file)
	error("Can not open stories.txt");

    pid_t pid = fork();
    if (pid == -1)
	error("Can not clone the process");

    if (!pid) {
	if (dup2(fileno(file), 1) == -1)
	    error("Can not redirect standard output");

	if (execle("/usr/bin/python",
		   "/usr/bin/python",
		   "./rssgossip.py",
		   phrase,
		   NULL, vars) == -1) {
	    error("Can not run script");
	}
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1)
	error("Error while waiting for child process");

    return 0;
}
