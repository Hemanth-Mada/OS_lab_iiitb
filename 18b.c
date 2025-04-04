/*    Program Number: 18b
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 3 April, 2025
      Description: This program read locks the record in the file.
      ./a.out q18.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct record
{
    int num;
    char *name;
} rec;

int main(int argc, char *argv[])
{
    // Open the file specified in the command line argument with read and write access
    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        printf("Unable to open the file\n");
        exit(1);
    }

    // Prompt the user to enter the record number they wish to lock
    printf("Enter the record number you wish to lock (1 to 3)\n");
    int num;

    if (scanf("%d", &num) != 1 || num < 1 || num > 3)
    {
        printf("Record number out of bounds\n");
        exit(1);
    }

    struct flock flk;
    // Set up the flock structure for read lock
    flk.l_type = F_RDLCK;
    flk.l_whence = SEEK_SET;
    flk.l_start = sizeof(rec) * (num - 1);
    flk.l_len = sizeof(rec);
    flk.l_pid = getpid();

    // Attempt to set the lock on the file
    int ret = fcntl(fd, F_SETLK, &flk);

    if (ret == -1)
    {
        printf("Read lock failed\n");
        exit(1);
    }
    else
    {
        printf("Read locked with lock type %d:\n", flk.l_type);
        // Unlock the record after use
        flk.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &flk);
    }

    printf("Unlocked\n");
    close(fd);
}