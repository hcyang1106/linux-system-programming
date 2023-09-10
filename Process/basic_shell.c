#include <stdlib.h>
#include <stdio.h>
#include <glob.h>
#include <string.h>
#include <unistd.h>

#define DELIMS " \t\n"

struct cmd_st {
    glob_t globres;
};

static void prompt() {
    printf("mysh-0.1$ ");
}

static void parse(char *line, struct cmd_st *res) {
    char *tok;
    int i = 0;

    while (1) {
        tok = strsep(&line, DELIMS);
        if (tok == NULL) {
            break;
        }
        if (tok[0] == '\0') { // continuous delims
            continue;
        }

        glob(tok, GLOB_NOCHECK | GLOB_APPEND * i, NULL, &res->globres);
        i = 1;
    }

}

int main() {
    char *linebuf = NULL;
    size_t linebuf_size = 0;
    struct cmd_st cmd;

    while (1) {
        prompt();
        if (getline(&linebuf, &linebuf_size, stdin) < 0) {
            break;
        }
        parse(linebuf, &cmd);
        if (0) {

        } else {
            pid_t pid;
            pid = fork();
            if (pid < 0) {

            }
            if (pid == 0) {
                execvp(cmd.globres.gl_pathv[0], cmd.globres.gl_pathv);
                perror("execvp()");
                exit(1);
            } else {
                wait(NULL);
            }
        }
    }
}