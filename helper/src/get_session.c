#define _POSIX_C_SOURCE 200809L

#include "../helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
 * Generate a session ID for helper based on PID and timestamp.
 * Format: "HELPER-<PID>-<TIMESTAMP>"
 * Returns 0 on success, -1 on failure.
 */
int get_session(char *session_id, size_t len)
{
    pid_t pid;
    time_t now;
    int ret;

    if (!session_id || len < 32) {
        print_error("session_id buffer too small");
        return -1;
    }

    pid = getpid();
    now = time(NULL);

    if (now == (time_t)-1) {
        print_error("time() failed");
        return -1;
    }

    ret = snprintf(session_id, len, "HELPER-%d-%ld", (int)pid, (long)now);
    if (ret < 0 || (size_t)ret >= len) {
        print_error("session_id buffer overflow");
        return -1;
    }

    return 0;
}
