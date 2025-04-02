/*    Program Number: 21
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: a program that opens a file, calls fork, and allows both 
                   the child and parent processes to write to the file. 
*/

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
        write(file, "Child process writing\n", 22);
    }
    else
    {
        write(file, "Parent process writing\n", 23);
    }

    close(file);
    return 0;
}
