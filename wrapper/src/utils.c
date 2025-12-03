#include "wrapper.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void usage(const char *restrict name) {
  fprintf(stderr, "Usage: %s [command [args...]]\n", name);
}

void get_configure(int argc, char **argv, const char *restrict config_path) {
  (void)argc;
  (void)argv;
  (void)config_path;

  // Default settings
  loglevel = log_normal;
  logfd = STDERR_FILENO;

  // In a real implementation, we would parse flags and read the config file.
  // For now, defaults are sufficient to make it work.
}
