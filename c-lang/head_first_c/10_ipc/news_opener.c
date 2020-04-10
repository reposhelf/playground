#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void open_url(const char *url) {
    pid_t pid = fork();

    if (pid == -1) {
	error("Can not clone process fot browser");
    }

    if (!pid) {
	// on Windows
	execl("cmd", "cmd", "/c", "start", url, NULL);
	// on Linux
	execl("/usr/bin/xdg-open", "/usr/bin/xdg-open", url, NULL);
	// on Mac
	execl("open", "open", url, NULL);

	error("Can not start a browser");
    }
}

int main(int argc, char **argv) {
    const char *phrase = argv[1];

    const char *vars[] = {
	"RSS_FEED=http://rss.nytimes.com/services/xml/rss/nyt/US.xml",
	NULL
    };

    int fd[2];

    if (pipe(fd) == -1) {
	error("Can not create pipe");
    }

    pid_t pid = fork();

    if (pid == -1) {
	error("Can not clone process");
    }

    if (!pid) {
	dup2(fd[1], 1);
	close(fd[0]);

	if (execle("/usr/bin/python",
		   "/usr/bin/python",
		   "./rssgossip.py",
		   "-u",
		   phrase,
		   NULL,
		   vars) == -1) {
	    error("Can not run script");
	}
    }

    dup2(fd[0], 0);
    close(fd[1]);

    char line[255];

    while (fgets(line, 255, stdin)) {
	if (line[0] == '\t') {
	    open_url(line + 1);
	}
    }

    return 0;
}
