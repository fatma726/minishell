#include "exec.h"
#include <unistd.h>     // fork, execve, _exit
#include <sys/wait.h>   // waitpid, WIFEXITED, WEXITSTATUS, ...
#include <stdio.h>      // perror

int ms_exec_abs(const char *path, char *const argv[], char *const envp[])
{
    pid_t pid = fork(); // 0 > 0
    if (pid < 0) 
    {                     // fork failed
        perror("fork"); 
        return 1;
    }
    if (pid == 0) 
    {                    // child
        execve(path, (char *const *)argv, envp);
        perror("execve");              // only if execve fails
        _exit(126);                    // 126 = exec error/permission
    }
    int st = 0;                        // parent
    if (waitpid(pid, &st, 0) < 0) 
    {
        perror("waitpid");
        return 1;
    }
    if (WIFEXITED(st))   return WEXITSTATUS(st);
    if (WIFSIGNALED(st)) return 128 + WTERMSIG(st);
    return 1;
}
