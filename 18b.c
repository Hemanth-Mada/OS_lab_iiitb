#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    printf("Which record (1-3) to lock? ");
    int num;
    if (scanf("%d", &num) != 1 || num < 1 || num > 3)
    {
        printf("Invalid input\n");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = sizeof(struct record) * (num - 1);
    lock.l_len = sizeof(struct record);

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("Lock failed");
        return 1;
    }

    printf("Locked record %d for reading\n", num);

    sleep(5); // Simulate some work

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Unlocked record %d\n", num);

    close(fd);
    return 0;
}
