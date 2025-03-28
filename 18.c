#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct record
{
    int num;
    char name[20];
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("File open failed");
        return 1;
    }

    struct record recs[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}};

    // writing records into file
    for (int i = 0; i < 3; i++)
    {
        if (write(fd, &recs[i], sizeof(struct record)) == -1)
        {
            perror("Write failed");
            close(fd);
            return 1;
        }
    }

    printf("3 records written to %s\n", argv[1]);

    close(fd);
    return 0;
}
