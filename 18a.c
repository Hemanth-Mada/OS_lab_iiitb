/*    Program Number: 18a
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 3 April, 2025
      Description: This program writes locks the record in the file.
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct record{
    int num;
    char *name;
} rec;

int main(int argc, char *argv[]){
    int fd = open(argv[1], O_WRONLY);
    if (fd == -1){
        printf("Unable to open the file\n");
        exit(1);
    }

    printf("Enter the record number you wish to lock (1 to 3)\n");
    int num;
    if (scanf("%d", &num) != 1 || num < 1 || num > 3){
        printf("Record number out of bounds\n");
        exit(1);
    }

    struct flock flk;
    flk.l_type = F_WRLCK;
    flk.l_whence = SEEK_SET;
    flk.l_start = sizeof(rec) * (num - 1);
    flk.l_len = sizeof(rec);
    flk.l_pid = getpid();

    int ret = fcntl(fd, F_SETLKW, &flk);

    if (ret == -1){
        printf("Write lock failed\n");
        exit(1);
    }
    else{
        printf("Write locked with lock type %d:\n", flk.l_type);
        flk.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &flk);
    }

    printf("Unlocked\n");
    close(fd);
}
