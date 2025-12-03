
#include "wrapper.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int connect_daemon(const char *restrict path, int method, ...) {
  int sockfd;
  struct sockaddr_un addr;

  (void)path; // unused for now, hardcoded to /tmp/brutalshell.sock as per plan
  (void)method;

  if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return -1;
  }

  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "/tmp/brutalshell.sock", sizeof(addr.sun_path) - 1);

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    // It's okay if we can't connect, maybe daemon isn't running.
    // We just won't log.
    close(sockfd);
    return -1;
  }

  return sockfd;
}

int send_daemon(int method, int fd, char *restrict buf, ssize_t len) {
  (void)method;
  if (fd < 0)
    return -1;
  return write(fd, buf, len);
}
