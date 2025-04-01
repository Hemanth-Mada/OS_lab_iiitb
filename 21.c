#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int file = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file < 0)
    {
        perror("Error opening file");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0)
    {
        write(file, "Child process writing\n", 26);
    }
    else
    {
        wait(NULL);
        write(file, "Parent process writing\n", 27);
    }

    close(file);
    return 0;
}
