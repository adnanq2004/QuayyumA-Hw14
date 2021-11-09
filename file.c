#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

static void sighandler(int sig) {

  if (sig == SIGINT) {
    printf("this is a SIGINT");
    exit(0);
  }
  else if (sig == SIGUSR1) {
    printf("PPID: %d\n", getppid());
  }

}

int main() {

  while (1) {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    printf("%d\n", getpid());
    sleep(1);
  }
  return 0;

}
