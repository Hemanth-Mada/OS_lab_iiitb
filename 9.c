/*    Program Number: 9
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program prints various details about a given file,
                   including inode, links, UID, GID, size, and timestamps.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    struct stat fileStat;

    stat("q9.txt", &fileStat);

    printf("Inode: %lu\n", (unsigned long)fileStat.st_ino);
    printf("Number of Hard Links: %lu\n", (unsigned long)fileStat.st_nlink);
    printf("UID: %u\n", (unsigned int)fileStat.st_uid);
    printf("GID: %u\n", (unsigned int)fileStat.st_gid);
    printf("Size: %ld\n", (long)fileStat.st_size);
    printf("Block size: %lu\n", (unsigned long)fileStat.st_blksize);
    printf("Number of Blocks: %lu\n", (unsigned long)fileStat.st_blocks);
    printf("Time of last access: %ld\n", (long)fileStat.st_atime);
    printf("Time of last modification: %ld\n", (long)fileStat.st_mtime);
    printf("Time of last change: %ld\n", (long)fileStat.st_ctime);

    return 0;
}
